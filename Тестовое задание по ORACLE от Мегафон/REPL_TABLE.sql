PROCEDURE REPL_TABLE(idtab              in number default -1,
                       dd                 in date default sysdate - 1,
                       job_n              in integer default 0, --REPL_JOB_TYPE
                       job_run            in integer default 0, --УИД JOBа если запущено из JOBа или 0
                       p_rep_run_id       in integer default null, --УИД потока для получения используйте GET_REP_LOG_RUN_ID
                       step               in integer default 0, --шаг рекурсии
                       SET_STATUS_DATA_OK IN integer default 10) --
   as
    IDREP constant integer := 4000;
    rep_run_id integer; --УИД потока для получения используйте GET_REP_LOG_RUN_ID
    f_error    boolean;
    f_Aerror   boolean;
    l_start    number;
  begin
    begin
      if step < 20 then
        --действуя по принципу минимално-достаточного
        if p_rep_run_id is null then
          --если поток не создан, то создаём его
          rep_run_id := GET_REP_LOG_RUN_ID(IDREP);
        else
          rep_run_id := p_rep_run_id;
        end if;
        vorobiev.rep_log_add_msg(IDREP,
                                 '--- Запуск репликации (job=' || job_n || ')',
                                 rep_run_id,
                                 job_run);
        f_Aerror := false;
      
        for cc in (select id_repl_table,
                          proc_to,
                          copy_name,
                          f_lock,
                          rep_obj,
                          next_step
                     from repl_table_list
                    where f_lock <> -1
                      and (f_lock = 0 or
                          (trunc(dd) = trunc(dd, 'month') + f_lock - 1))
                      and ((id_repl_table = idtab) or
                          ((last_upd_time <= trunc(sysdate) or
                          last_upd_time is null) and - 1 = idtab) or
                          (-2 = idtab))
                      and (job_n = 0 or job_n = job)
                    order by srt, id_repl_table) loop
          l_start := dbms_utility.get_time;
          if cc.proc_to = 'BASE' then
            f_error := not
                        REPL_TABLE_BASE(cc.id_repl_table,
                                                 rep_run_id,
                                                 job_run,
                                                 SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
          elsif cc.proc_to = 'BSM1' then
            f_error := not
                        REPL_TABLE_BSM1(cc.id_repl_table,
                                                 dd,
                                                 rep_run_id,
                                                 job_run,
                                                 true,
                                                 SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
          elsif cc.proc_to = 'BSM2' then
            f_error := not
                        REPL_TABLE_BSM1(cc.id_repl_table,
                                                 dd,
                                                 rep_run_id,
                                                 job_run,
                                                 SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
            --    elsif cc.proc_to='CLLM' then
            --      f_error := not REPL_TABLE_CLLM(rep_run_id=>rep_run_id,job_run=>job_run);
          elsif cc.proc_to = 'CALL' then
            f_error := not
                        REPL_TABLE_CALL2(trunc(dd),
                                                  rep_run_id,
                                                  job_run,
                                                  SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
          elsif cc.proc_to = 'MERG' then
            f_error := not
                        REPL_TABLE_MERG(cc.id_repl_table,
                                                 dd,
                                                 rep_run_id,
                                                 job_run,
                                                 SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
          elsif cc.proc_to = 'MRG1' then
            f_error := not
                        REPL_TABLE_MERG(cc.id_repl_table,
                                                 dd,
                                                 rep_run_id,
                                                 job_run,
                                                 true,
                                                 SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
          elsif cc.proc_to = 'UPDT' then
            f_error := not
                        REPL_TABLE_UPD(cc.id_repl_table,
                                                dd,
                                                rep_run_id,
                                                job_run,
                                                SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
          else
            f_error := true;
          end if;
          f_Aerror := f_Aerror or f_error;
        
          if not f_error then
            if trunc(dd) = trunc(sysdate - 1) then
              update repl_table_list
                 set last_upd_time = sysdate
               where id_repl_table = cc.id_repl_table;
              commit;
            end if;
            if cc.next_step is not null then
              REPL_TABLE(cc.next_step,
                         dd,
                         10,
                         rep_run_id,
                         step + 1,
                         SET_STATUS_DATA_OK => SET_STATUS_DATA_OK);
            end if;
            vorobiev.rep_log_add_msg(IDREP,
                                     'Ok. Время обработки ' || cc.copy_name || '(' ||
                                     cc.id_repl_table || ') процедурой ' ||
                                     cc.proc_to || ' - ' ||
                                     round((dbms_utility.get_time - l_start) / 100,
                                           2) || ' секунд.',
                                     rep_run_id,
                                     job_run);
          else
            vorobiev.rep_log_add_msg(IDREP,
                                     '*** Время обработки ' || cc.copy_name || '(' ||
                                     cc.id_repl_table || ') процедурой ' ||
                                     cc.proc_to || ' - ' ||
                                     round((dbms_utility.get_time - l_start) / 100,
                                           2) || ' секунд.',
                                     rep_run_id,
                                     job_run);
          end if;
        
        end loop;
        if not f_Aerror then
          vorobiev.rep_log_add_msg(IDREP,
                                   '=== Репликация завершена (job=' ||
                                   job_n || ')',
                                   rep_run_id,
                                   job_run);
        else
          vorobiev.rep_log_add_msg(IDREP,
                                   '### Репликация завершена (job=' ||
                                   job_n || '). При выгрузке были ошибки',
                                   rep_run_id,
                                   job_run);
        end if;
      else
        vorobiev.rep_log_add_msg(IDREP,
                                 '### Репликация прервана (job=' || job_n ||
                                 '). Step=' || step,
                                 rep_run_id,
                                 job_run);
      end if;
    end;
    if f_Aerror then
      Raise_application_error(-20000,
                              'Репликация job=' || job_n || ',  idtab=' ||
                              idtab || ' упала. Рестарт. ' || user);
    end if;
  end;