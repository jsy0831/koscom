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

// 메뉴 등을 선택할때 해야할 일이 있다면
// C 언어       : 해야할 일을 "함수"   로 구현합니다.
// Command 패턴 : 해야할 일을 "클래스" 로 구현합니다.


// 모든 명령의 인터페이스
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_execute() { return true;  }
	virtual void undo() {}
	virtual bool can_undo() { return false; }
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }
	void undo()  override 
	{
		Shape* s = v.back(); // 꺼내기만 하고 제거 안되므로
		v.pop_back();		 // 별도로 제거

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
				pcmd->execute();        // 실행후

				undo_stack.push(pcmd);	// undo 를 위해서 스택에 보관
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

					// delete pcmd;  // redo 를 지원하지 않는 경우는 삭제..!!

					redo_stack.push(pcmd); // redo 를 지원하려면 다시 보관.
				}
			}
		}
	}
}




