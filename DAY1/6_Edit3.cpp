#include <iostream>
#include <string>
#include <conio.h>
// Edit ������ �ٽ�
// => ������ ���� �ڵ忡�� ���ϴ� �ڵ�� �и��ϴ� ����, 
// => ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� �и� - Edit2.cpp
// 2. ���ϴ� ���� �ٸ� Ŭ������ �и� - Edit3.cpp


// Validation ��å�� ���� Ŭ������ ��ü �����ϰ� �Ϸ���
// �������̽��� �ʿ� �ϴ�.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// �ֹε�Ϲ�ȣ : 991  1    Ȯ�ι�ư




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


