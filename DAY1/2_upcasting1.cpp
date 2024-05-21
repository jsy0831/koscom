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
	
	// 핵심 1. 기반 클래스 포인터에 파생 클래스 객체의 주소를 담을수 있다.
	// => 객체지향 디자인의 핵심!!
	Animal* p3 = &d; // ok

	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근 가능
	// => C++은 static type check 언어 이므로
	// => static type check : 컴파일 시간에 포인터 타입으로 에러 여부 확인
	// => 파이썬 등은 실행시간에 check(dynamic check!!)
	p3->age = 10;   // ok
//	p3->color = 10; // error


	// 핵심 3. 기반 클래스 포인터로 파생 클래스 멤버에 접근하려면
	//        캐스팅 필요.
	// => 단, 이경우 p3가 가리키는 곳이 Dog 라는 확신이 있어야 한다
	static_cast<Dog*>(p3)->color = 10;


}











