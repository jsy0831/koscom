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






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }


	// static 멤버 데이타의 특징을 생각해 보세요
	// => Rect 객체가 없어도 메모리 존재 합니다. (전역변수와 동일)
	// => 즉, ar 의 생성자는 main 함수 이전에 호출되었습니다.
	// => 공장에 Rect 가 이미 등록됨
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

		    // Rect::ar 생성자는 main 함수 이전에 호출됨
//Rect r1; // 생성자 호출
//Rect r2; // 생성자 호출
//Rect r3; // 생성자 호출.. 즉, 생성자는 객체당 한번 호출.







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::create);



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




