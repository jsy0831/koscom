#include <iostream>
#include <string>


// Picture �� Picture �� ����� �߰��ϴ� Ŭ����(Decorator)��
// ������ �������̽��� �ʿ� �ϴ�.
// => ��� �׸��� �ִ�.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class Picture : public IDraw 
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
	}
	void draw() { std::cout << "draw " << url << std::endl; }
};

//---------------------------------------------------
// ������ ����� ����� �߰�

class Frame : public IDraw
{
	IDraw* pic;

public:
	Frame(IDraw* pic) : pic(pic) {}

	void draw()
	{
		std::cout << "#######################\n"; 
		pic->draw();  							  
		std::cout << "#######################\n";
	}
};
// �ɱ׸��� �߰��ϴ� ��ü(Decorator)
class Flower : public IDraw
{
	IDraw* pic;
public:
	Flower(IDraw* pic) : pic(pic) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&\n";
		pic->draw();
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&\n";
	}
};


int main()
{
	Picture pic("www.naver.com/a.png");

	Frame frame(&pic); 
//	frame.draw();

	Flower flower(&frame);
	flower.draw();
}