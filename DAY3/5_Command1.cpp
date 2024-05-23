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
	virtual void can_execute() { return true;  }
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




