#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.

// ���ڿ��� �����ϰ� �ִٰ� ȭ�鿡 �̻ڰ� ����ϴ� ���.
class TextView
{
	// font name, font size, color �� �پ��� ������ �����ϴ� ���
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

// ���������⿡�� ���ڿ��� �ٷ�� �ʹ�.
// TextView �������̽�(�Լ��̸�)�� �����ؼ� ���� �����⿡�� ����Ҽ� �ְ�
// �ϴ� Ŭ����

// Adapter : ������ �����ϴ� Ŭ������ �������̽��� �䱸���ǿ� �µ��� �����ϴ� Ŭ����
//			"�������̽��� ����ġ�� �ذ��ϴ� ����"

class Text : public Shape, public TextView
{
public:
	Text(const std::string& data) : TextView(data) {}

	// �Ʒ� �ڵ尡 "show" ��� �������̽�(�Լ��̸�)�� "draw" �� �����ؼ�
	// ������������ �䱸������ �����ϵ��� �����.
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







