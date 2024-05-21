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

//	if (사용자 입력 == 1) p = &d;  

	// 핵심 1 : 컴파일러는 컴파일 시간에 p가 가리키는 객체의 종류를 알수 없다

	// static_cast : 컴파일 시간 캐스팅, 오버헤드가 전혀 없는 빠른 캐스팅.
	// => p가 가리키는 곳이 정말 Dog 인지 알수 없다. 무조건 캐스팅 성공
	// => p가 가리키는 곳이 Dog 가 아니라도 성공하는데, 개발자 책임!!!
//	Dog* pdog = static_cast<Dog*>(p);



	// dynamic_cast : 실행시간 캐스팅
	// => 실행시간에 p가 가리키는 곳이 Dog 인지 조사후 캐스팅
	// => 조사해야 하므로 오버헤드가 있다

	Dog* pdog = dynamic_cast<Dog*>(p);

	std::cout << pdog << std::endl;

}











