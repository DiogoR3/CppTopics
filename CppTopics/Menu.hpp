#ifndef MENU_HEADER
#define MENU_HEADER

#include <string>

namespace CppTopics
{
	class Menu
	{
	public:
		void start();
		void end();

	private:
		void print(std::string &&str, bool jumpLine = true);
		bool exit_{false};
	};
}

#endif
