#include <iostream>
#include <string>


// Picture 와 Picture 에 기능을 추가하는 클래스(Decorator)는
// 공통의 인터페이스가 필요 하다.
// => 모두 그릴수 있다.

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
// 포함을 사용한 기능의 추가

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
// 꽃그림을 추가하는 객체(Decorator)
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