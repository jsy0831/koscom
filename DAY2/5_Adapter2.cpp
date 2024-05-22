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

// Adapter ����
// class adapter  : Ŭ������ �������̽� ����
// object adapter : ��ü�� �������̽� ����

class Text : public Shape, public TextView
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() {show();}
};

class ObjectAdapter : public Shape
{
	TextView* tview; // �ٽ� : �����ͳ� ���� ���!!
					 // => �ܺο� �̹� ������ ��ü�� ����Ű�ڴٴ� �ǵ�
public:
	ObjectAdapter(TextView* v) : tview(v) {}

	void draw() {}
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("Hello");	// TextView : Ŭ����
							// tv		: ��ü

	// �̹� ������ ��ü tv �� v�� ������ ������ ?
//	v.push_back(&tv);	// error
	v.push_back( new ObjectAdapter(&tv) );	// ok
}







