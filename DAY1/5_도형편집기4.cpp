#include <iostream>
#include <vector>

// 핵심 #1 : 모든 도형 파생 클래스의 공통의 특징은 반드시 기반 클래스에도
//        있어야 한다. - 문법적인 규칙이 아니라 디자인의 규칙

// 핵심 #2. 기반 클래스 함수중 파생 클래스가 override 하게되는 것은
//         반드시 가상함수 이어야 한다.


class Shape
{
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }
};

class Rect : public Shape
{
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
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v) 
				p->draw();  
		}
	}
}






