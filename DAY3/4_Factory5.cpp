// factory5.cpp - factory2번 복사

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

	std::map<int, Shape*> prototype_map; // 견본을 보관하는 map

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
			p = sample->clone(); // 복사본을 만드는 가상함수 호출

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	
	// 아래 코드는 공장에 (1) 객체   (2) 클래스   를 등록하는 코드
	// => 객체를 만드는 함수 포인터를 등록하므로 "클래스" 를 등록하는 의미
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


	// 자주 사용되는 객체를 미리 만들어서 공장에 등록해 봅시다.
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




