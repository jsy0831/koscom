// 3_menu_event0.cpp

void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	// C ����� �Լ� ������!
	// => �Լ��� �ּҸ� �����ߴٰ� ���߿� ȣ���ϱ� ���� ���
	void(*f)(int) = &f1;

	f(10); // �ᱹ f1(10) �� �ǹ�.

}