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

	IValidator* pval = nullptr;
public:
	void set_validator(IValidator* v) { pval = v; }


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->is_complete(data))   ) break;

			if ( pval == nullptr || pval->validate(data, c) )  // �Է°��� ��ȿ�� Ȯ����
			{								// �ٸ� ��ü�� ����
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� �پ��� Validation ��å�� �����ϴ� Ŭ�������� �����ϸ� �˴ϴ�.
class LimitDigitValidator : public IValidator
{
	int count;
public:
	LimitDigitValidator(int c) : count(c) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < count && isdigit(c);
	}
	bool is_complete(const std::string& s) override
	{
		return s.size() == count;
	}
};
int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.set_validator(&v);    // Edit ��ü�� ���� ��ȿ���� Ȯ���ϴ� ��ü ����

	LimitDigitValidator v2(15);
	e.set_validator(&v2); // ���� Edit ��ü�� Validation ��å�� ��ü

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


