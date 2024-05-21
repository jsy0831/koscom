// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& n, int a) : name(n), age(a) {}
};
// Person 으로 부터 상속받는 Student 만들어 보세요
// 1. int id  멤버 추가해 보세요
// 2. 생성자 만들어 보세요
// 3. main 에서 Student 객체 생성해 보세요

class Student : public Person
{
	int id;
public:
//	Student(int n) : id(n) {} // error.
//	Student(int n) : Person(), id(n) {} // 컴파일러가 변경한 코드

	Student(const std::string& name, int age, int id)
		: Person(name, age), id(id) {}
};

int main()
{
	Student s("kim", 20, 15);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	Person p2("kim", 20); // ok. 초기화된 객체. 안전하다!!
}


