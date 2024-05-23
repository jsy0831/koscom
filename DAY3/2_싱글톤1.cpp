// 3_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//			��𿡼����� ������ ������� ��ü�� �����Ҽ� �ִ°�

// => �ᱹ ��������!!
// => ���������� ���� �ʽ��ϴ�.
// => �׷��� �̱��� ���Ͽ� ���� ���ǵ� ���� �ֽ��ϴ�.


class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}

	// ��Ģ 2. �����Ϸ����� ���� �����ڿ� ���Կ����ڸ� ������ ���ϰ� �ؾ� �մϴ�
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete; // ���簡 �����Ǹ� ���������� ���Ե�����

	// ��Ģ 3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� static ��� �Լ�
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

//	Cursor c3 = c1; // ���� ������ ȣ�� �� ��ü ������ ���ƾ� �մϴ�.

//	Cursor c1, c2; // error
}








