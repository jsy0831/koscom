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

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
			{
				// C++17�� ���ο� if ��
				// ����   if : if ( ���ǽ� )
				// ���ο� if : if ( �ʱ�ȭ����; ���ǽ� )
				// vs ���� C++17 ����Ϸ��� ������Ʈ�޴�, �Ӽ� �޴����� C++���� ����
				if ( Rect* r = dynamic_cast<Rect*>(p); r != nullptr )
				{
					r->draw();
				}
				else if (Circle* c = dynamic_cast<Circle*>(p); c != nullptr)
				{
					c->draw();
				}

			}
		}
	}
}






