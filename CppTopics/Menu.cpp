#include <iostream>
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
				const char charArray[] = {'C', '+', '+', '\0'};
				print("{ 'C', '+', '+', '\\0' } = " + std::string(charArray));

				const char stringLiteral[] = "C++";
				print("\"C++\" = " + std::string(stringLiteral));

				break;
			}
			case '2':
			{
				const double number = 10;
				print("number = " + std::to_string(number));

				const double *pNumber = &number;
				print("*pNumber = " + std::to_string(*pNumber));
				break;
			}
			case '3':
			{
				const char *dynamicMemory = new (std::nothrow) char[1'000'000];
				if (dynamicMemory == nullptr)
				{
					print("Could not create char[1'000'000]");
				}
				else
				{
					print("char[1'000'000] created successfully");
					delete[] dynamicMemory;
				}
				break;
			}
			case '4':
			{
				int number;
				print("How many numbers would you like to type?");
				std::cin >> number;
				int *dynamicNumbers = new (std::nothrow) int[number];

				for (int n = 0; n < number; n++)
				{
					print("Enter number: ");
					std::cin >> dynamicNumbers[n];
				}
				print("You have entered: ");
				for (int n = 0; n < number; n++)
					print(std::to_string(dynamicNumbers[n]) + ", ", false);

				if (dynamicNumbers != nullptr)
					delete[] dynamicNumbers;

				break;
			}
			case '5':
				throw "This is an exception!";
				break;
			case '6':
				winAPI.showMessageBox();
				break;
			case '7':
				winAPI.doBeep();
				break;
			case '8':
			{
				const auto sysInfo = winAPI.systemInfo();
				if (sysInfo.Cores != 0)
				{
					print("CPU: " + std::string(sysInfo.CPUBrand));
					print("Number of cores: " + std::to_string(sysInfo.Cores));
					print("RAM: " + std::to_string(sysInfo.RAM) + "MB");
				}

				break;
			}
			case '9':
				winAPI.openFileDialog();
				break;
			case '0':
				end();
				break;
			default:
				print("Invalid option selected!");
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
