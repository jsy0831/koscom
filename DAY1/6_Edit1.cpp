#include <iostream>
#include <string>
#include <conio.h>

// GUI Widget �� Edit �� ������ ���ô�
// => �Է� ���� ��ȿ���� Ȯ���ϴ� validation ����� �־�� �մϴ�.

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

			if (c == 13) break; // enter Ű

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


