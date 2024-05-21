class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;

	Dog* p1 = &d;	// ok	
	int* p2 = &d;	// error
	
	// �ٽ� 1. ��� Ŭ���� �����Ϳ� �Ļ� Ŭ���� ��ü�� �ּҸ� ������ �ִ�.
	// => ��ü���� �������� �ٽ�!!
	Animal* p3 = &d; // ok

	// �ٽ� 2. ��� Ŭ���� �����ͷδ� ��� Ŭ���� ����� ���� ����
	// => C++�� static type check ��� �̹Ƿ�
	// => static type check : ������ �ð��� ������ Ÿ������ ���� ���� Ȯ��
	// => ���̽� ���� ����ð��� check(dynamic check!!)
	p3->age = 10;   // ok
//	p3->color = 10; // error


	// �ٽ� 3. ��� Ŭ���� �����ͷ� �Ļ� Ŭ���� ����� �����Ϸ���
	//        ĳ���� �ʿ�.
	// => ��, �̰�� p3�� ����Ű�� ���� Dog ��� Ȯ���� �־�� �Ѵ�
	static_cast<Dog*>(p3)->color = 10;


}











