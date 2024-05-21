// protected 생성자의 의도 
// => 자신은 객체를 만들수 없지만(추상적 존재. abstract)
// => 파생 클래스는 객체를 만들수 있다(구체적 존재. concrete)

class Animal
{
//public:		// 1, 2 모두 에러 아님
//private:		// 1, 2 모두 에러!
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// 1	error
	Dog    d;	// 2	ok
}



