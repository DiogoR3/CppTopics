#include <iostream>
#include <string>
#include <thread>
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
			std::cout << "1 - Character Sequences" << jumpln;
			std::cout << "2 - Pointers" << jumpln;
			std::cout << "3 - Dynamic Memory (nothrow)" << jumpln;
			std::cout << "4 - Dynamic Memory (delete)" << jumpln;
			std::cout << "5 - Throwing exception" << jumpln;
			std::cout << "6 - Windows API - Show Message Box" << jumpln;
			std::cout << "7 - Windows API - Beep" << jumpln;
			std::cout << "8 - Windows API - CPU/RAM Info" << jumpln;
			std::cout << "9 - Windows API - Open file" << jumpln;
			std::cout << "0 - Exit" << jumpln;
			std::cout << jumpln;

			std::cout << "Option: ";
			std::getline(std::cin, userInput);

			if (userInput.length() != 1)
				userInput[0] = 0;

			switch (userInput[0]) {

			case '1': {
				char charArray[] = { 'C', '+', '+', '\0' };
				std::cout << "{ 'C', '+', '+', '\\0' } = " << charArray << jumpln;
				char stringLiteral[] = "C++";
				std::cout << "\"C++\" = " << stringLiteral << jumpln;
				break;
			}

			case '2': {
				double var = 10;
				std::cout << "var = " << var << jumpln;

				double* varptr = &var;
				std::cout << "varptr = " << varptr << jumpln;
				std::cout << "*(varptr) = " << *(varptr) << jumpln;
				break;
			}

			case '3':
				char* dynamicMemory;
				dynamicMemory = new (std::nothrow) char[1'000'000];
				if (dynamicMemory == nullptr) {
					std::cout << "Could not create char[1'000'000]" << jumpln;
				}
				else {
					std::cout << "char[1'000'000] created successfully" << jumpln;
				}
				break;

			case '4': {
				int number;
				std::cout << "How many numbers would you like to type? ";
				std::cin >> number;
				int* dynamicNumbers = new (std::nothrow) int[number];

				for (int n = 0; n < number; n++)
				{
					std::cout << "Enter number: ";
					std::cin >> dynamicNumbers[n];
				}
				std::cout << "You have entered: ";
				for (int n = 0; n < number; n++)
					std::cout << dynamicNumbers[n] << ", ";
				delete[] dynamicNumbers;
				std::cout << jumpln;
			}

			case '5':
				throw "This is a exception!";
				break;

			case '6':
				winAPI.ShowMessageBox();
				break;

			case '7':
				winAPI.DoBeep();
				break;

			case '8': {
				auto sysInfo = winAPI.SystemInfo();
				std::cout << "CPU: " << sysInfo.CPUBrand << jumpln;
				std::cout << "Numer of cores: " << sysInfo.Cores << jumpln;
				std::cout << "RAM: " << sysInfo.RAM << "MB" << jumpln;
				break;
			}

			case '9':
				winAPI.OpenFileDialog();
				break;

			case '0':
				end();
				break;

			default:
				std::cout << "Invalid option selected!" << jumpln << jumpln;
				break;
			}

			(void)std::getchar();
		}
	}

	void Menu::end() {
		std::cout << "Press any key to exit..." << jumpln;
		exit = true;
	}
}
