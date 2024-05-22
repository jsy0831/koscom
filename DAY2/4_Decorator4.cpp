#include <iostream>
#include <string>

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

// 기능을 추가하는 클래스들은 공통의 특징을 가지게 됩니다.
// => 원래 그림의 어느 위치에 이모티콘을 추가할것인가등(x, y)


// 기능 추가 객체의 공통의 특징을 제공하는 기반 클래스
class IDecorator : public IDraw
{
	int x, y;
	IDraw* pic;
public:
	IDecorator(IDraw* pic) : pic(pic) {}

	void draw() { pic->draw(); }
};

// 이제 모든 기능추가 클래스는 IDecorator 로 부터 파생되면 됩니다.
class Frame : public IDecorator
{
public:
	Frame(IDraw* pic) : IDecorator(pic) {}

	void draw()
	{
		std::cout << "#######################\n";
		IDecorator::draw();
		std::cout << "#######################\n";
	}
};

class Flower : public IDecorator
{
public:
	Flower(IDraw* pic) : IDecorator(pic) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&\n";
		IDecorator::draw();
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