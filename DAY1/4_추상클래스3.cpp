#include <iostream>

// 사람과 카메라 사이에 지켜야 하는 규칙을 먼저 설계 합니다

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.
class ICamera
{
public:
	virtual void take() = 0;
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

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

}





