#include <iostream>
#include <vector>


// 핵심 : 다형성은 OCP 를 만족하는 아주 좋은 코드 입니다.
//        다형성은 "가상함수 기반" 코드 입니다.


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






