#include <Windows.h>
#include <mmsystem.h>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#pragma comment(lib,"WinMM.Lib")

using namespace std;


BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)
{
	// Get the required size of the buffer that receives the Unicode
	// string.
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, NULL, 0);
	assert(dwSize >= dwMinSize);

	// Convert headers from ASCII to Unicode.
	MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);
	return TRUE;
}

int main(int argc, char** argv)
{
	string s = "F:/Project_CPlus/PCLCLustering/init/BGM.wav";
	wchar_t wText[30] = { 0 };
	MByteToWChar(s.c_str(), wText, sizeof(wText) / sizeof(wText[0]));
	PlaySound(wText, NULL, SND_FILENAME | SND_SYNC);
	system("pause");
	return 0;
}
