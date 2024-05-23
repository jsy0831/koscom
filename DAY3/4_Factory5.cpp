// factory5.cpp - factory2�� ����

#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	static Shape* create() { return new Rect; }

	virtual Rect* clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	virtual Circle* clone() { return new Circle(*this); }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map; // �ߺ��� �����ϴ� map

public:
	void register_shape(int type, Shape* sample)
	{
		prototype_map[type] = sample;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		Shape* sample = prototype_map[type];

		if (sample != nullptr)
			p = sample->clone(); // ���纻�� ����� �����Լ� ȣ��

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	
	// �Ʒ� �ڵ�� ���忡 (1) ��ü   (2) Ŭ����   �� ����ϴ� �ڵ�
	// => ��ü�� ����� �Լ� �����͸� ����ϹǷ� "Ŭ����" �� ����ϴ� �ǹ�
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


	// ���� ���Ǵ� ��ü�� �̸� ���� ���忡 ����� ���ô�.
	Rect* blueRect = new Rect; 
	Rect* redRect = new Rect;
	Circle* redCircle = new Circle;

	factory.register_shape(1, blueRect);
	factory.register_shape(2, redRect);
	factory.register_shape(3, redCircle);




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




