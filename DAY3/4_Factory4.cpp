#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();
	std::map<int, CREATOR> create_map;

public:
	void register_shape(int type, CREATOR f)
	{
		create_map[type] = f;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		CREATOR f = create_map[type];

		if (f != nullptr)
			p = f();

		return p;
	}
};

// 자동으로 공장에 제품을 등록해주는 클래스
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(type, f);
	}
};

// 전역변수의 생성자는 언제 호출되는지 생각해 보세요 
//AutoRegister ar(1, &Rect::create); 






#define REGISTER(classname)								\
static Shape* create() { return new classname; }		\
	static AutoRegister ar;

#define REGISTER_IMP(type, classname)						\
AutoRegister classname::ar(type, &classname::create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(Rect)
};
REGISTER_IMP(1, Rect)








class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	REGISTER(Circle)
};
REGISTER_IMP(2, Circle)


class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	REGISTER(Triangle)
};
REGISTER_IMP(3, Triangle)


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




