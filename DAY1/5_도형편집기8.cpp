#include <iostream>
#include <vector>

// ���ܷ� ����� Ŭ����
class NotImlemented {};



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}



	// ���� �Լ�     : �Ļ� Ŭ������ override ���� ������ �⺻��������
	// ���� �����Լ� : �Ļ� Ŭ�������� �ݵ�� ������ ���� �ϴ� ��	

protected:
	virtual void draw_imp() = 0;

public:
//	virtual Shape* clone() = 0; // �̷��� �ص� ���� �����̰�

	// �Ʒ� ó�� �ϴ� ����� �ֽ��ϴ�.
	// 1. clone() �� override �ϰ� ��� �ϸ� ok
	// 2. clone() �� override ���� �ʰ� ��� ������ ������ ok
	// 3. clone() �� override ���� �ʰ� ��� �ϸ� ���� �߻�

	virtual Shape* clone()
	{
		// �⺻ ������ ���� �߻�
		throw NotImplemented();
	}

	
//	virtual int get_area() = 0; // �̷��� �ص� �ǰ�

	// �⺻ �������� �߸��� ��(�������Ҽ� ���� �� �ǹ��ϴ� ��)�� ��ȯ
	// => get_area() �� ����� -1 �̸� ���� ���Ҽ������̶�� �Ŵ��������
	virtual int get_area() { return -1; }
};






class Rect : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw Rect\n"; }

	// �����Լ� override �ÿ� ��ȯ Ÿ�� ���� �����մϴ�!!!
//	Shape* clone() override  { return new Rect(*this); }
	Rect* clone() override { return new Rect(*this); }
};
// Rect* r1 = new Rect;
// Rect* r2 = r1->clone(); // ���ڵ尡 �Ƿ��� clone ��ȯŸ����
//							  Shape* �� �ƴ� Rect*  �̾�� �մϴ�.

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Circle* clone() override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 1. ��ü�� ������������ OCP �� �����ϰ� �Ҽ� ������� ?
		// => ���ο� ����(Triangle) �� �߰��ص� �Ʒ� �ڵ尡 ���� �������� �ʵ���
		// => "�߻� ���丮" ������ ����ϸ� �˴ϴ�. - 3���� ����

		// 2. Undo/Redo �� �Ϸ��� ��� �ؾ� �ұ�� ?
		// => "Command" ������ ����ϸ� �˴ϴ�. - 3���� ����
		// => ��, �̹� Ư�� ����� �����ϴ� �ڵ� �ۼ����� ��κ� �˷��� �ֽ��ϴ�.
		// => "������ ����"�� �߿��� ����!!!

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






