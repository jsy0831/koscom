#include <iostream>
#include <vector>
#include <stack>

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
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// �޴� ���� �����Ҷ� �ؾ��� ���� �ִٸ�
// C ���       : �ؾ��� ���� "�Լ�"   �� �����մϴ�.
// Command ���� : �ؾ��� ���� "Ŭ����" �� �����մϴ�.


// ��� ����� �������̽�
struct ICommand
{
	virtual void execute() = 0;
	virtual void can_execute() { return true;  }
	virtual void undo() {}
	virtual bool can_undo() { return false; }
	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override {  }	
};






int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
	}
}




