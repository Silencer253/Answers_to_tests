//Allocate memory
int* m_CellsCopy = new int [m_Width * m_Height];
int size = sizeof(m_CellsCopy);
memmove(m_CellsCopy, m_Cells, size);

result = CalcWay(start, finish);

//Release memory
delete[] m_CellsCopy;
m_CellsCopy = 0;