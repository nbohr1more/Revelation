/***************************************************************

Simple wrapper to start Win32 applications with command parameters
without using batch files.

(c) Ralph Engels, September 01, 2012

Licensed under the GPL license.

***************************************************************/

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#pragma warning(disable : 4996) // deprecation win8
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/* Declarations for new process	 */
	STARTUPINFO			si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	int					ret;
	LPSTR				baseLine = "revelation.exe +set fs_game_base base +set fs_game cdoom";

	/* Needed for OS detection */
	OSVERSIONINFOEX		osvi;
	BOOL				bOsVersionInfoEx;

	/* Setup startup flags */
	si.dwFlags = STARTF_USESHOWWINDOW;

	/* Check the Operating System version */
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if (!(bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO *)&osvi)))
	{
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

		if (!GetVersionEx((OSVERSIONINFO *)&osvi))
		{
			exit(EXIT_FAILURE);
		}
	}

	/* If newer than windows9x/ME then hide */
	if (osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
		si.wShowWindow = SW_HIDE;
	}
	else
	{
		si.wShowWindow = SW_SHOW;
	}
	ret = CreateProcess(NULL, baseLine, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	if (ret == 0)
	{
		MessageBox(NULL, "ERROR: Could not launch Doom3 with this mod, its either missing or you installed it in the wrong place!", baseLine, MB_OK | MB_ICONERROR);
		exit(EXIT_FAILURE);
	}
	return 0;
}
