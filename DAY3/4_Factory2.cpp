#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// �ڽ��� ��ü�� ����� static ��� �Լ��� ���� �����ϰ� ���˴ϴ�.
	// => ���� ����̹Ƿ� �� ����ϼ���

	static Shape* create() { return new Rect; }
};

// Rect �� ����� 2���� ���
// 1. Rect* p1 = new Rect;
// 2. Rect* p2 = Rect::create();














class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) 
		{
			Shape* s = factory.Create(cmd);

			if (s != nullptr)
			{
				v.push_back(s);
			}
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




