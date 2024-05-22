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

// ����� �߰��ϴ� Ŭ�������� ������ Ư¡�� ������ �˴ϴ�.
// => ���� �׸��� ��� ��ġ�� �̸�Ƽ���� �߰��Ұ��ΰ���(x, y)


// ��� �߰� ��ü�� ������ Ư¡�� �����ϴ� ��� Ŭ����
class IDecorator : public IDraw
{
	int x, y;
	IDraw* pic;
public:
	IDecorator(IDraw* pic) : pic(pic) {}

	void draw() { pic->draw(); }
};

// ���� ��� ����߰� Ŭ������ IDecorator �� ���� �Ļ��Ǹ� �˴ϴ�.
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