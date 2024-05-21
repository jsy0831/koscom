// 1_추상클래스1.cpp - 10page
// 추상 클래스 : 순수가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다.
// 의도 : 특정함수(약속된 함수)를 반드시 만들라고 지시 하는 것
class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수(pure virtual function)
						     // 특징 : 구현부가 없고 "=0" 으로 표기
};
class Rect : public Shape
{
	// draw의 구현부를 제공하지 않으면 Rect 도 추상 클래스 입니다(abstract)
	// draw의 구현부를 제공하면 Rect 는 추상이 아닙니다(구체 클래스, concrete)
public:
	virtual void draw() override {}
};

int main()
{
	Shape  s; // error
	Shape* p; 
	Rect  r;
}
