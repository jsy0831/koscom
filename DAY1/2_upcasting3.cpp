// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

// upcasting Ȱ�� 2. ������ ������ �ִ� �Լ� �����
//void NewYear(Dog* pDog) // Dog ��ü�� ���� �޴� �Լ�
void NewYear(Animal* p)   // ��� ������ ���ڷ� �޴� �Լ�
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











