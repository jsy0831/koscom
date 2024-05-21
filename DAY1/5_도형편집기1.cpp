#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 만드는 과정을 생각해 봅시다.

// 1. 각 도형을 타입화 하면 편리합니다.

// 2. 모든 도형은 공통의 특징이 있다(색상등..)
//    공통의 기반 클래스가 있다면 모든 도형을 하나의 컨테이너에 보관할수 있다

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// x, y, w, h, 생성자등의 코드는 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v;
	std::vector<Shape*> v;

}

