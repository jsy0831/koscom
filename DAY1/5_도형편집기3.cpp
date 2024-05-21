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

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
			{
				// C++17의 새로운 if 문
				// 기존   if : if ( 조건식 )
				// 새로운 if : if ( 초기화구문; 조건식 )
				// vs 에서 C++17 사용하려면 프로젝트메뉴, 속성 메뉴에서 C++버전 변경
				if ( Rect* r = dynamic_cast<Rect*>(p); r != nullptr )
				{
					r->draw();
				}
				else if (Circle* c = dynamic_cast<Circle*>(p); c != nullptr)
				{
					c->draw();
				}

			}
		}
	}
}






