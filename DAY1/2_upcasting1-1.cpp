#include <iostream>

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
	Animal a;

	Animal* p = &d; 

	Dog* pdog = static_cast<Dog*>(p);

	std::cout << pdog << std::endl;


}











