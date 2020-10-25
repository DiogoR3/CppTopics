#include <windows.h>
#include <intrin.h>
#include "WindowsAPI.h"

namespace CppTopics {

	void WindowsAPI::ShowMessageBox() {

	messagebox:

		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"This is a message box from windows.\nDo you want to show it again?",
			(LPCWSTR)L"Message Example",
			MB_ICONINFORMATION | MB_OKCANCEL | MB_DEFBUTTON2
		);

		switch (msgboxID)
		{
		case IDOK:
			goto messagebox;
			break;
		case IDCANCEL:
			return;
			break;
		}
	}

	void WindowsAPI::DoBeep() {
		Beep(523, 500);
		Sleep(300);
	}

	WindowsAPI::CPURAMInfo WindowsAPI::SystemInfo() {
		int CPUInfo[4] = { -1 };
		unsigned int nExIds, i = 0;
		char CPUBrand[0x40] = { 0 };

		__cpuid(CPUInfo, 0x80000000);
		nExIds = CPUInfo[0];
		for (i = 0x80000000; i <= nExIds; ++i)
		{
			__cpuid(CPUInfo, i);
			if (i == 0x80000002)
				memcpy(CPUBrand, CPUInfo, sizeof(CPUInfo));
			else if (i == 0x80000003)
				memcpy(CPUBrand + 16, CPUInfo, sizeof(CPUInfo));
			else if (i == 0x80000004)
				memcpy(CPUBrand + 32, CPUInfo, sizeof(CPUInfo));
		}

		WindowsAPI::CPURAMInfo systemInfo;
		strncpy_s(systemInfo.CPUBrand, CPUBrand, strlen(CPUBrand));
		
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		systemInfo.Cores = sysInfo.dwNumberOfProcessors;

		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		systemInfo.RAM = statex.ullTotalPhys / (1024 * 1024);

		return systemInfo;
	}
}
