#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// 문자열을 보관하고 있다가 화면에 이쁘게 출력하는 기능.
class TextView
{
	// font name, font size, color 등 다양한 정보를 관리하는 기능
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};

//===============================================

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// Adapter 종류
// class adapter  : 클래스의 인터페이스 변경
// object adapter : 객체의 인터페이스 변경

class Text : public Shape, public TextView
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() {show();}
};

class ObjectAdapter : public Shape
{
	TextView* tview; // 핵심 : 포인터나 참조 멤버!!
					 // => 외부에 이미 생성된 객체를 가리키겠다는 의도
public:
	ObjectAdapter(TextView* v) : tview(v) {}

	void draw() {}
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("Hello");	// TextView : 클래스
							// tv		: 객체

	// 이미 생성된 객체 tv 를 v에 넣을수 있을까 ?
//	v.push_back(&tv);	// error
	v.push_back( new ObjectAdapter(&tv) );	// ok
}







