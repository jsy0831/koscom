#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� ����ڰ� ���� �����ؾ� �Ѵ�.

class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// ������ ���� �ڵ� �ӿ� ���� ���ؾ� �ϴ� �κ��� ã������!!
	// ���ϴ� �κ��� �����Լ��� �и��ϼ���
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

			if (validate(c)) // ���ؾ� �ϴ� �κ��� "�����Լ�ȣ��"��!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// Validation ��å�� �����Ϸ��� Edit �Ļ� Ŭ������ ����
// ��ӵ� �����Լ��� override �ϸ� �˴ϴ�.
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


