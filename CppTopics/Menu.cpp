#include <iostream>
#include <string>
#include <thread>
#include "Menu.hpp"
#include "WindowsAPI.hpp"

namespace CppTopics
{
	void Menu::start()
	{
		CppTopics::WindowsAPI winAPI;
		std::string userInput;

		while (!exit_)
		{
			print("**** CppTopics ****");
			print("Choose an option below:");
			print("1 - Character Sequences");
			print("2 - Pointers");
			print("3 - Dynamic Memory (nothrow)");
			print("4 - Dynamic Memory (delete)");
			print("5 - Throwing exception");
			print("6 - Windows API - Show Message Box");
			print("7 - Windows API - Beep");
			print("8 - Windows API - CPU/RAM Info");
			print("9 - Windows API - Open file");
			print("0 - Exit");
			print("Option: ", false);

			std::getline(std::cin, userInput);

			if (userInput.length() != 1)
				userInput[0] = 0;

			switch (userInput[0])
			{

			case '1':
			{
				char charArray[] = {'C', '+', '+', '\0'};
				std::cout << "{ 'C', '+', '+', '\\0' } = " << charArray << std::endl;
				char stringLiteral[] = "C++";
				std::cout << "\"C++\" = " << stringLiteral << std::endl;
				break;
			}

			case '2':
			{
				double var = 10;
				std::cout << "var = " << var << std::endl;

				double *varptr = &var;
				std::cout << "varptr = " << varptr << std::endl;
				std::cout << "*(varptr) = " << *(varptr) << std::endl;
				break;
			}

			case '3':
				char *dynamicMemory;
				dynamicMemory = new (std::nothrow) char[1'000'000];
				if (dynamicMemory == nullptr)
				{
					std::cout << "Could not create char[1'000'000]" << std::endl;
				}
				else
				{
					std::cout << "char[1'000'000] created successfully" << std::endl;
				}
				break;

			case '4':
			{
				int number;
				std::cout << "How many numbers would you like to type? ";
				std::cin >> number;
				int *dynamicNumbers = new (std::nothrow) int[number];

				for (int n = 0; n < number; n++)
				{
					std::cout << "Enter number: ";
					std::cin >> dynamicNumbers[n];
				}
				std::cout << "You have entered: ";
				for (int n = 0; n < number; n++)
					std::cout << dynamicNumbers[n] << ", ";
				delete[] dynamicNumbers;
				std::cout << std::endl;
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

			case '8':
			{
				auto sysInfo = winAPI.SystemInfo();
				std::cout << "CPU: " << sysInfo.CPUBrand << std::endl;
				std::cout << "Numer of cores: " << sysInfo.Cores << std::endl;
				std::cout << "RAM: " << sysInfo.RAM << "MB" << std::endl;
				break;
			}

			case '9':
				winAPI.OpenFileDialog();
				break;

			case '0':
				end();
				break;

			default:
				std::cout << "Invalid option selected!" << std::endl
						  << std::endl;
				break;
			}

			(void)std::getchar();
		}
	}

	void Menu::print(std::string &&str, bool jumpLine)
	{
		if (jumpLine)
			str += "\n";
		std::cout << str;
	}

	void Menu::end()
	{
		print("Press any key to exit...");
		exit_ = true;
	}
}
