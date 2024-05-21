#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; }
	void cry2() { std::cout << "Animal Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry() { std::cout << "Dog Cry" << std::endl; }
};
int main()
{
	Dog d;  

	Animal* p = &d;
	p->cry();
}
