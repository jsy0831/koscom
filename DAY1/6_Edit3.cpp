#include <iostream>
#include <string>
#include <conio.h>
// Edit 예제의 핵심
// => 변하지 않은 코드에서 변하는 코드는 분리하는 개념, 
// => 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 분리 - Edit2.cpp
// 2. 변하는 것을 다른 클래스로 분리 - Edit3.cpp


// Validation 정책을 담은 클래스를 교체 가능하게 하려면
// 인터페이스가 필요 하다.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// 주민등록번호 : 991  1    확인버튼




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


