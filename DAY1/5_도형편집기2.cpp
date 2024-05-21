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
				p->draw();   // error. Shape ���� draw �� ����.
		}
	}
}
// �� �ڵ�� �� �����ϱ�� ?
// => A �κп��� p �� Ÿ���� Shape* �ε�, Shape ���� draw ������
// �ذ�å�� ������ ������
// 1. Shape* �� p�� Rect* �� Circle* �� ĳ�����ؼ� ���
// 2. Shape ���� draw() �� ������.





