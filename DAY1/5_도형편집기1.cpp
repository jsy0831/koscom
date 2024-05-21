#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 만드는 과정을 생각해 봅시다.

// 1. 각 도형을 타입화 하면 편리합니다.

class Rect
{
	// x, y, w, h, 생성자등의 코드는 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Rect*> v;

}

