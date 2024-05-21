#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경 가능해야 한다.

class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// 변하지 않은 코드 속에 숨은 변해야 하는 부분을 찾으세요!!
	// 변하는 부분을 가상함수로 분리하세요
	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (validate(c)) // 변해야 하는 부분은 "가상함수호출"로!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// Validation 정책을 변경하려면 Edit 파생 클래스를 만들어서
// 약속된 가상함수를 override 하면 됩니다.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};
int main()
{
//	Edit e;
	NumEdit e;
//  AddressEdit e2;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


