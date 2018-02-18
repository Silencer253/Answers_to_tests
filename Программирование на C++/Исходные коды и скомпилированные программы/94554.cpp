const n =4;
const char* cmds[n] = {"-help","-cmd1","-cmd2","-cmd3"};

//
//
int mystrcmp(const char *string1, const char *string2)
{/*impl skipped*/}


int main(int argc, char *argv[])
{
	const char* cmd = argc > 1 ? argv[1] : "";
	
	for (int i=0; i<n; i++)
		if (cmds[i]==cmd)
		{
			cout << "Option \"" << cmds[i] << "\" selected." << endl;
		}
}	

