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

	// �ڽ��� ��ü�� ����� static ��� �Լ��� ���� �����ϰ� ���˴ϴ�.
	// => ���� ����̹Ƿ� �� ����ϼ���

	static Shape* create() { return new Rect; }
};

// Rect �� ����� 2���� ���
// 1. Rect* p1 = new Rect;			// ��ü ������ Ŭ���� �̸��� �ʿ� �մϴ�.
// 2. Rect* p2 = Rect::create();	// ��ü ������ �Լ��ּҸ� �˸� �˴ϴ�.

// #1. C++ �� Ŭ���� �̸��� �ڷᱸ���� �����ϰų� �Լ� ���ڷ� ����Ҽ� �����ϴ�.
// vector.push_back("Rect"); // Ŭ���� �̸��� ������ ���� �ƴ϶� ���ڿ� "Rect" ����
						  // ���ڿ� "Rect" �� Rect ��ü�� ������� �����ϴ�.

// #2. �Լ������ʹ� �ڷᱸ���� ���� �����մϴ�
// vector.push_back(&Rect::create); // ������ �Լ��� "Rect" ��ü ��������.!














class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)();      // �Լ� ������ Ÿ��
	std::map<int, CREATOR> create_map; // <������ȣ, �����Լ�> �� ���� �����ϴ� map

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
			p = f();		// map �� ��ϵ� �����Լ��� ���� ����

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// ������ ����ϱ� ���� ���忡 ��ǰ(����)�� ����ؾ� �մϴ�.
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




