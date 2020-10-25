#include <iostream>
#include <string>
#include "Menu.h"
#include "WindowsAPI.h"
#define jumpln std::endl

namespace CppTopics {

	Menu::Menu() {
		exit = false;
	}

	void Menu::start() {

		CppTopics::WindowsAPI winAPI;
		std::string userInput;

		while (!exit) {

			std::cout << "**** CppTopics ****" << jumpln << jumpln;
			std::cout << "Choose an option below:" << jumpln;
			std::cout << "1 - Windows API - Message box" << jumpln;
			std::cout << "2 - Exit" << jumpln;
			std::cout << jumpln;

			std::cout << "Option: ";
			std::getline(std::cin, userInput);
			
			if (userInput.length() != 1)
				userInput[0] = 0;
			 
			switch (userInput[0]) {

			case '1':

				winAPI.ShowMessageBox();
				break;

			case '2':
				end();
				break;

			default:
				std::cout << "Invalid option selected!" << jumpln << jumpln;
				break;
			}
		}
	}

	void Menu::end() {
		std::cout << "Press any key to exit..." << jumpln;
		exit = true;
		std::cin.get();
	}
}
