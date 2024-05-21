#include <iostream>
#include <vector>


// 핵심 : 다형성은 OCP 를 만족하는 아주 좋은 코드 입니다.
//        다형성은 "가상함수 기반" 코드 입니다.

// 디자인 패턴
// => 1994년에 4명의 저자가 지은 책은 이름
// => 자주 사용되는 코딩 기법에 이름을 붙인것, 23개의 이름..

// prototype 디자인 패턴
// => 이미 생성된 객체의 복사본을 만드는 가상함수
// => 아래 코드의 clone 가상함수!

// 리팩토링 용어 입니다. 의미를 이해해 보세요

// => replace conditional with polymorphism
//    "조건문(if, switch)" 를 "다형성(가상함수)" 로 변경해라.
//    도형편집기3.cpp  를 도형편집기4.cpp 로 변경해라


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }


	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용됩니다
	virtual Shape* clone() { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());	// 다형성
					// 새로운 도형이 추가되어도 이 한줄은 변하지 않는다.
					// k 번째 도형이 어떤 종류인지 조사할 필요도 없다.

		}
	}
}






