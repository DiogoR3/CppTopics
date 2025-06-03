#include <windows.h>
#include <intrin.h> // __cpuid
#include <iostream> // print file name
#include "WindowsAPI.hpp"

namespace CppTopics
{
	WindowsAPI::WindowsAPI()
	{
#ifdef _WIN32
		isWindows_ = true;
#endif
	}

	void WindowsAPI::showMessageBox()
	{
		if (!isWindows_)
		{
			std::cerr << "showMessageBox is only available on Windows." << std::endl;
			return;
		}

	messagebox:

		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"This is a message box from windows.\nDo you want to show it again?",
			(LPCWSTR)L"Message Example",
			MB_ICONINFORMATION | MB_OKCANCEL | MB_DEFBUTTON2);

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

	void WindowsAPI::doBeep()
	{
		if (!isWindows_)
		{
			std::cerr << "doBeep is only available on Windows." << std::endl;
			return;
		}

		Beep(523, 500);
		Sleep(300);
	}

	WindowsAPI::CPURAMInfo WindowsAPI::systemInfo()
	{
		if (!isWindows_)
		{
			std::cerr << "systemInfo is only available on Windows." << std::endl;
			return {};
		}

		int CPUInfo[4] = {-1};
		unsigned int nExIds, i = 0;
		char CPUBrand[0x40] = {0};

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

		std::copy(CPUBrand, CPUBrand + sizeof(CPUBrand), systemInfo.CPUBrand);

		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		systemInfo.Cores = sysInfo.dwNumberOfProcessors;

		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		systemInfo.RAM = statex.ullTotalPhys / (1024 * 1024);

		return systemInfo;
	}

	void WindowsAPI::openFileDialog()
	{
		if (!isWindows_)
		{
			std::cerr << "openFileDialog is only available on Windows." << std::endl;
			return;
		}

		OPENFILENAME ofn;
		SecureZeroMemory(&ofn, sizeof(ofn));
		char f1[MAX_PATH];
		f1[0] = 0;
		ofn.lStructSize = sizeof(ofn);
		ofn.lpstrTitle = L"Select A File";
		ofn.lpstrFilter = L"Text Files\0*.txt\0All Files\0*.*\0\0";
		ofn.nFilterIndex = 2;
		ofn.lpstrFile = (LPWSTR)f1;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn) != FALSE)
		{
			std::cout << "Chosen file: ";
			std::wcout << ofn.lpstrFile << std::endl;
		}
		else
		{
			std::cout << "No file chosen!";
		}

		std::cout << std::endl;
	}
}
