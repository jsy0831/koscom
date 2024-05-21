#include <iostream>
#include <vector>

// 핵심 #1 : 모든 도형 파생 클래스의 공통의 특징은 반드시 기반 클래스에도
//        있어야 한다. - 문법적인 규칙이 아니라 디자인의 규칙

// 핵심 #2. 기반 클래스 함수중 파생 클래스가 override 하게되는 것은
//         반드시 가상함수 이어야 한다.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 함수는 가상으로 할까요 ? 비 가상으로 할까요 ?
	// => 파생 클래스가 override 할 필요 없다. - 비가상!!
	void set_color(int c) { color = c; }

	// 면적을 구하는 방법은 도형마다 다르다 
	// => virtual 이어야 한다.
	virtual int get_area() { return 0; }

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
				p->draw();  // 동일한 코드가 상황에 따라(객체의 종류)
							// 다르게 동작
							// 다형성(polymorphism)
							// 객체지향 3대 특징 : 캡슐화, 상속, 다형성

							// 다형성은 OCP 를 만족하는 좋은 코드 입니다
							// "p->draw()" 는 새로운 도형이 추가되어도 
							// 수정될 필요 없습니다.
		}
	}
}






