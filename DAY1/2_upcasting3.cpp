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

// upcasting 활용 2. 동종을 받을수 있는 함수 만들기
//void NewYear(Dog* pDog) // Dog 객체만 전달 받는 함수
void NewYear(Animal* p)   // 모든 동물을 인자로 받는 함수
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











