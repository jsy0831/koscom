#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {}
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Animal a;

//	Animal* p = &d; 
	Animal* p = &a;

//	if (����� �Է� == 1) p = &d;  

	// �ٽ� 1 : �����Ϸ��� ������ �ð��� p�� ����Ű�� ��ü�� ������ �˼� ����

	// static_cast : ������ �ð� ĳ����, ������尡 ���� ���� ���� ĳ����.
	// => p�� ����Ű�� ���� ���� Dog ���� �˼� ����. ������ ĳ���� ����
	// => p�� ����Ű�� ���� Dog �� �ƴ϶� �����ϴµ�, ������ å��!!!
//	Dog* pdog = static_cast<Dog*>(p);



	// dynamic_cast : ����ð� ĳ����
	// => ����ð��� p�� ����Ű�� ���� Dog ���� ������ ĳ����
	// => �����ؾ� �ϹǷ� ������尡 �ִ�

	Dog* pdog = dynamic_cast<Dog*>(p);

	std::cout << pdog << std::endl;

}











