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

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_execute() { return true; }
	virtual void undo() {}
	virtual bool can_undo() { return false; }
	virtual ~ICommand() {}
};

template<typename T>
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new T); }
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

	void undo()  override { system("cls"); }

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
			pcmd = new AddCommand<Rect>(v);

			if (pcmd->can_execute())
			{
				pcmd->execute();      
				undo_stack.push(pcmd);
			}
		}

		else if (cmd == 2)
		{
			pcmd = new AddCommand<Circle>(v);

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
				std::cout << "현재상태에서는 실행할수 없는 명령(disable menu)\n";
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

					redo_stack.push(pcmd); 
				}
			}
		}
	}
}




