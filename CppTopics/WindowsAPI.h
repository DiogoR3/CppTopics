#ifndef WindowsAPI_HEADER
#define WindowsAPI_HEADER

namespace CppTopics {
	class WindowsAPI
	{
	public:
		struct CPURAMInfo {
			char CPUBrand[64];
			unsigned long Cores;
			unsigned long long RAM;
		};
		void ShowMessageBox();
		void DoBeep();
		CPURAMInfo SystemInfo();
	};
}

#endif
