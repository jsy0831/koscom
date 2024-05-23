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
	virtual bool can_execute() { return true;  }
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

	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }
	void undo()  override 
	{
		Shape* s = v.back(); // �����⸸ �ϰ� ���� �ȵǹǷ�
		v.pop_back();		 // ������ ����

		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); }

	bool can_undo() override { return true; }
	void undo()  override
	{
		Shape* s = v.back(); 
		v.pop_back();		

		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override 
	{ 
		for (auto s : v) 
			s->draw();
	}

	bool can_undo() override { return true; }
	
	void undo()  override  { system("cls");	}

	bool can_execute() override { return !v.empty(); }
};



int main()
{
	std::vector<Shape*> v;

	ICommand* pcmd = nullptr;

	std::stack<ICommand*> undo_stack;
	std::stack<ICommand*> redo_stack;


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v);

			if (pcmd->can_execute())
			{
				pcmd->execute();        // ������

				undo_stack.push(pcmd);	// undo �� ���ؼ� ���ÿ� ����
			}
		}

		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);

			if (pcmd->can_execute())
			{
				pcmd->execute();        

				undo_stack.push(pcmd);	
			}
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);

			if (pcmd->can_execute())
			{
				pcmd->execute();        

				undo_stack.push(pcmd);	
			}
			else
			{
				std::cout << "������¿����� �����Ҽ� ���� ���(disable menu)\n";
			}
		}

		if (cmd == 0)
		{
			if (undo_stack.empty() == false)
			{
				pcmd = undo_stack.top();
				undo_stack.pop();

				if (pcmd->can_undo())
				{
					pcmd->undo();

					// delete pcmd;  // redo �� �������� �ʴ� ���� ����..!!

					redo_stack.push(pcmd); // redo �� �����Ϸ��� �ٽ� ����.
				}
			}
		}
	}
}




