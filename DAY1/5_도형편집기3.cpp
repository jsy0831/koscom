#include <iostream>
#include <vector>

// 아래 코드는 OCP 를 만족하지 못하는 안좋은 코드 입니다
// => 새로운 도형(Triangle) 이 추가되면
// => main 함수의 cmd==9 안의 if 문이 한줄 추가되어야 합니다.
// 
// => 새로운 도형 추가할때마다 계속 변경
// => dynamic_cast 는 나쁜 디자인과 연결됩니다. 사용하지 마세요


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






