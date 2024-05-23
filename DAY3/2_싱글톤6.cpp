#include <iostream>

// �Ʒ� �ڵ�� 
// => effective - c++ å�� ������ "scott mayer" �� ó�� ������ �ڵ�
// => "mayer's singleton" �̶�� �մϴ�.
// => ��Ƽ ������ �����ϰ�(C++11����), 
// => ���� C++ �������� ���� ���� �𵨷� �� �˴ϴ�.



class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; 



public:
	static Cursor& get_instance()
	{

		static Cursor instance;


		return instance;
	}
};




int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








