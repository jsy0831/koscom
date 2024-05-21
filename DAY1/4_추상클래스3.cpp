#include <iostream>


// People 은 카메라가 필요 할때 "HDCamera" 라는 구체 클래스 이름보다
// "ICamera 라는 인터페이스 이름" 을 사용하는 것이 좋다 - 교체 가능하기위해


// 의존 관계 역전의 규칙(DIP, Dependency Inversion Principle)
// => 구체 보다 추상의 의존해라!





// 인터 페이스 : 지켜야하는 규칙(순수 가상함수)만 가진 경우
// 추상 클래스 : 지켜야하는 규칙(순수 가상함수) + 다른 멤버도 있는 경우

// java, C# : interface, abstract 라는 별도의 키워드 제공됨
// C++      : 별도의 키워드 없음. 추상 클래스 문법으로 모두 만듬


// 사람과 카메라 사이에 지켜야 하는 규칙을 먼저 설계 합니다

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라고 하지말고
//        "모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현
//class ICamera
struct ICamera
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // 인터페이스는 결국 기반 클래스!!
						  // 기반 클래스 소멸자는 가상이어야 한다.
};




// 카메라 사용자는 반드시 "규칙" 대로 사용해야 합니다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};
// 모든 카메라는 규칙을 지켜야 합니다
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};
class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); // People 클래스를 수정하지 않고도
					    // 새로운 제품을 사용할수 있다.

}





