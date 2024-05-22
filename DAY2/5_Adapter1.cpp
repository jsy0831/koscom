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

// 도형편집기에서 문자열도 다루고 싶다.
// TextView 인터페이스(함수이름)을 변경해서 도형 편집기에서 사용할수 있게
// 하는 클래스

// Adapter : 기존의 존재하던 클래스의 인터페이스를 요구조건에 맞도록 수정하는 클래스
//			"인터페이스의 불일치를 해결하는 패턴"

class Text : public Shape, public TextView
{
public:
	Text(const std::string& data) : TextView(data) {}

	// 아래 코드가 "show" 라는 인터페이스(함수이름)을 "draw" 로 변경해서
	// 도형편집기의 요구조건을 만족하도록 만든것.
	void draw()
	{
		show();
	}
};
int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("Hello"));
	v[0]->draw();
}







