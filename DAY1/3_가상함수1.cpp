#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// 함수 override : 기반 클래스 함수를 파생 클래스 "다시 구현" 하는 것
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry();
	Dog d;    d.cry();

	Animal* p = &d; 
//  if ( 사용자입력 == 1 ) p = &a;
	p->cry();
}

// p->cry() 를 어느 함수와 연결할것인가 ? "함수 바인딩(binding)" 이라고 합니다

// 1. static binding : 컴파일러가 컴파일 시간에 어느 함수를 호출할지 결정
//                     "컴파일러는 p가 가리키는 객체의 종류를 알수 없다."
//					   컴파일러가 아는 것은 p가 Animal* 라는 것만 알수 있다
//                     call Animal::cry 기계어 코드 생성
// 비 논리적이지만, 빠르다.
// C++/C# 언어의 기본 바인딩

// 2. dynamic binding : 컴파일 시간에는 p가 가리키는 메모리를 조사하는 기계어 생성
//						실행시간에 메모리 조사후 함수 호출 결정
//						p가 가리키는 곳이 Dog라면 Dog::cry 호출
// 논리적이지만 느리다.
// Java, Python, swift등의 대부분의 객체지향 언어의 바인딩 정책
// C++/C# 의 가상함수!