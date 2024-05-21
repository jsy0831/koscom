#include <iostream>
#include <vector>


class Shape
{
public:
	virtual ~Shape() {}
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

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v) // A
				p->draw();   // error. Shape 에는 draw 가 없다.
		}
	}
}
// 위 코드는 왜 에러일까요 ?
// => A 부분에서 p 의 타입은 Shape* 인데, Shape 에는 draw 가없다
// 해결책을 생각해 보세요
// 1. Shape* 인 p를 Rect* 나 Circle* 로 캐스팅해서 사용
// 2. Shape 에도 draw() 를 만들자.





