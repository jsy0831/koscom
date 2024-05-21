#include <iostream>
#include <string>
#include <conio.h>

// GUI Widget 인 Edit 를 설계해 봅시다
// => 입력 값의 유효성을 확인하는 validation 기능이 있어야 합니다.

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

			if (c == 13) break; // enter 키

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c << std::endl;
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


