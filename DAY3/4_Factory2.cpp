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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용하게 사용됩니다.
	// => 좋은 기술이므로 꼭 기억하세요

	static Shape* create() { return new Rect; }
};

// Rect 를 만드는 2가지 방법
// 1. Rect* p1 = new Rect;			// 객체 생성시 클래스 이름이 필요 합니다.
// 2. Rect* p2 = Rect::create();	// 객체 생성시 함수주소만 알면 됩니다.

// #1. C++ 은 클래스 이름을 자료구조에 보관하거나 함수 인자로 사용할수 없습니다.
// vector.push_back("Rect"); // 클래스 이름을 보관한 것이 아니라 문자열 "Rect" 보관
						  // 문자열 "Rect" 로 Rect 객체를 만들수는 없습니다.

// #2. 함수포인터는 자료구조에 보관 가능합니다
// vector.push_back(&Rect::create); // 보관된 함수로 "Rect" 객체 생성가능.!














class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)();      // 함수 포인터 타입
	std::map<int, CREATOR> create_map; // <도형번호, 생성함수> 의 쌍을 보관하는 map

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
			p = f();		// map 에 등록된 생성함수로 도형 생성

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장을 사용하기 전에 공장에 제품(도형)을 등록해야 합니다.
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




