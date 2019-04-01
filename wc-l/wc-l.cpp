#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>

using namespace std;
#define N 4096
int main(int argc, char** argv ) {
    long long t1, t2, freq;
	char str[N];
	unsigned lines = 0;
	DWORD nRead;
	BOOL bResult;
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	HANDLE f = CreateFile(L"a.txt", GENERIC_READ, FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	
do{
	bResult = ReadFile (f, str, N, &nRead, NULL);
	for (DWORD i = 0; i < nRead; ++i)
		if (str [i]=='\n')
			lines++;
} while (!(bResult && nRead == 0));

	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла

	CloseHandle(f);
	cout.precision(3);
	cout <<  " \n Time spent:" << std::fixed << (t2-t1)/(1.*freq) << '\n';
	cout << lines << "lines\n";
	return 0;
}