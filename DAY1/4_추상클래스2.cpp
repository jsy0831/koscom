//1_추상클래스2.cpp
#include <iostream>


// OCP
// => 기능확장에 열려 있고(Open, 나중에 새로운 클래스/모듈)이 추가되어도
// => 코드수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않게)
// => 디자인 하라는 원칙(Principle )

// 개방 폐쇄 의 법칙(open close principle)

// 객체지향 설계의 5대 원칙 : SRP, OCP, LSP, ISP, DIP  => SOLID


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ???

}





