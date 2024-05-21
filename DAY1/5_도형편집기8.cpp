#include <iostream>
#include <vector>

// 예외로 사용할 클래스
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



	// 가상 함수     : 파생 클래스가 override 하지 않으면 기본구현제공
	// 순수 가상함수 : 파생 클래스에게 반드시 만들라고 지시 하는 것	

protected:
	virtual void draw_imp() = 0;

public:
//	virtual Shape* clone() = 0; // 이렇게 해도 좋은 구현이고

	// 아래 처럼 하는 기법도 있습니다.
	// 1. clone() 을 override 하고 사용 하면 ok
	// 2. clone() 을 override 하지 않고 사용 하지도 않으면 ok
	// 3. clone() 을 override 하지 않고 사용 하면 예외 발생

	virtual Shape* clone()
	{
		// 기본 구현이 예외 발생
		throw NotImplemented();
	}

	
//	virtual int get_area() = 0; // 이렇게 해도 되고

	// 기본 구현으로 잘못된 값(면적구할수 없음 을 의미하는 값)을 반환
	// => get_area() 의 결과가 -1 이면 면적 구할수없음이라고 매뉴얼로제공
	virtual int get_area() { return -1; }
};






class Rect : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw Rect\n"; }

	// 가상함수 override 시에 반환 타입 변경 가능합니다!!!
//	Shape* clone() override  { return new Rect(*this); }
	Rect* clone() override { return new Rect(*this); }
};
// Rect* r1 = new Rect;
// Rect* r2 = r1->clone(); // 이코드가 되려면 clone 반환타입이
//							  Shape* 가 아닌 Rect*  이어야 합니다.

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

		// 1. 객체의 생성과정으로 OCP 를 만족하게 할수 없을까요 ?
		// => 새로운 도형(Triangle) 을 추가해도 아래 코드가 전혀 수정되지 않도록
		// => "추상 팩토리" 패턴을 사용하면 됩니다. - 3일차 수업

		// 2. Undo/Redo 를 하려면 어떻게 해야 할까요 ?
		// => "Command" 패턴을 사용하면 됩니다. - 3일차 수업
		// => 즉, 이미 특정 기능을 수행하는 코드 작성법은 대부분 알려져 있습니다.
		// => "디자인 패턴"이 중요한 이유!!!

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}






