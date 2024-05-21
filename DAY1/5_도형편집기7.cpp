#include <iostream>
#include <vector>


// template method 디자인 패턴
// => 기반 클래스가 전체적인 틀을 담은 메소드(draw)를 제공
// => 변하는 부분만 가상함수화 해서( draw_imp)
// => 파생 클래스가 변하는 것만 변경할수 있는 기회를 제공하는 패턴

// 가장 널리 사용하는 디자인 기술.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 숨은 변해야 하는 코드를 찾아서
	// => 변하야 하는 코드는 별도의 가상함수로 분리

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}
public:
	void draw() 
	{ 
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}





	virtual Shape* clone() { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

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

			v.push_back(v[k]->clone());	

		}
	}
}






