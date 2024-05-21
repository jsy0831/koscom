#include <iostream>
#include <vector>

// �ٽ� #1 : ��� ���� �Ļ� Ŭ������ ������ Ư¡�� �ݵ�� ��� Ŭ��������
//        �־�� �Ѵ�. - �������� ��Ģ�� �ƴ϶� �������� ��Ģ

// �ٽ� #2. ��� Ŭ���� �Լ��� �Ļ� Ŭ������ override �ϰԵǴ� ����
//         �ݵ�� �����Լ� �̾�� �Ѵ�.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// �Ʒ� �Լ��� �������� �ұ�� ? �� �������� �ұ�� ?
	// => �Ļ� Ŭ������ override �� �ʿ� ����. - �񰡻�!!
	void set_color(int c) { color = c; }

	// ������ ���ϴ� ����� �������� �ٸ��� 
	// => virtual �̾�� �Ѵ�.
	virtual int get_area() { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }
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
				p->draw();  // ������ �ڵ尡 ��Ȳ�� ����(��ü�� ����)
							// �ٸ��� ����
							// ������(polymorphism)
							// ��ü���� 3�� Ư¡ : ĸ��ȭ, ���, ������

							// �������� OCP �� �����ϴ� ���� �ڵ� �Դϴ�
							// "p->draw()" �� ���ο� ������ �߰��Ǿ 
							// ������ �ʿ� �����ϴ�.
		}
	}
}






