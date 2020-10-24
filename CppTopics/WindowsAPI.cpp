#include <windows.h>
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
}
