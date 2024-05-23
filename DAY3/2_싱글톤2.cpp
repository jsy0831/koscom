#include <iostream>

// �̱���1.cpp : ���� �Ѱ��� ��ü�� static ���������� ����� ��
//              => data �޸𸮿� ��ü ����

// �̱���2.cpp : �Ѱ��� ��ü�� ���� ����� ��

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; 

	static Cursor* sinstance;

public:
	static Cursor& get_instance()
	{
		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








