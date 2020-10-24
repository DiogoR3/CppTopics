#include <iostream>
#include "Menu.h"
#include "WindowsAPI.h"
#define jumpln std::endl

namespace CppTopics {

	void Menu::start() {

		while (true) {

		menu:

			std::cout << "**** CppTopics ****" << jumpln << jumpln;
			std::cout << "Choose an option below:" << jumpln;
			std::cout << "1 - Windows API - Message box" << jumpln;
			std::cout << "2 - Exit" << jumpln;
			std::cout << jumpln;

			int userInput = std::cin.get();
			CppTopics::WindowsAPI winAPI;

			switch (userInput) {

			case 49: // option 1

				winAPI.ShowMessageBox();
				break;

			case 50: // option 2
				return;
				break;

			default:
				std::cout << jumpln;
				break;
			}
		}
	}

	void Menu::end() {

		std::cout << "Press any key to exit...";
		std::cin.get();
	}
}
