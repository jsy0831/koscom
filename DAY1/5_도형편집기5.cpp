#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

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
				p->draw();  
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			// k번째 도형의 복사본을 만들어서 v에 추가.
			// 어떻게 해야 할까요 ? k번째 도형이 어떤 도형일 까요 ?

			// 아래 처럼하면 역시 OCP 를 만족할수 없습니다!!
			// 나쁜 코드!!
			if (Rect* r = dynamic_cast<Rect*>(v[k]); r != nullptr)
			{
				v.push_back(new Rect(*r));
			}
			else if (Circle* c = dynamic_cast<Circle*>(v[k]); c != nullptr)
			{
				v.push_back(new Rect(*c));
			}
		}
	}
}






