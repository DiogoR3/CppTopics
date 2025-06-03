#ifndef WindowsAPI_HEADER
#define WindowsAPI_HEADER

namespace CppTopics
{
	class WindowsAPI
	{
	public:
		WindowsAPI();
		struct CPURAMInfo
		{
			char CPUBrand[64];
			unsigned long Cores;
			unsigned long long RAM;
		};
		void showMessageBox();
		void doBeep();
		CPURAMInfo systemInfo();
		void openFileDialog();

	private:
		bool isWindows_{false};
	};
}

#endif
