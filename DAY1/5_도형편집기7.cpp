#include <iostream>
#include <vector>


// template method ������ ����
// => ��� Ŭ������ ��ü���� Ʋ�� ���� �޼ҵ�(draw)�� ����
// => ���ϴ� �κи� �����Լ�ȭ �ؼ�( draw_imp)
// => �Ļ� Ŭ������ ���ϴ� �͸� �����Ҽ� �ִ� ��ȸ�� �����ϴ� ����

// ���� �θ� ����ϴ� ������ ���.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� ���� ���ؾ� �ϴ� �ڵ带 ã�Ƽ�
	// => ���Ͼ� �ϴ� �ڵ�� ������ �����Լ��� �и�

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}
public:
	void draw() 
	{ 
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}





	virtual Shape* clone() { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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
			std::cout << "���° ���� ������ ���� �ұ�� >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());	

		}
	}
}






