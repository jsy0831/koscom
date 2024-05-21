#include <iostream>
#include <string>
#include <conio.h>
// Edit 예제의 핵심
// => 변하지 않은 코드에서 변하는 코드는 분리하는 개념, 
// => 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 분리 - Edit2.cpp
// 2. 변하는 것을 다른 클래스로 분리 - Edit3.cpp


class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


