//  ���ۿ��� "C# stream" �˻��� image ����� �غ�����

// Decorator - 65 page
#include <iostream>
#include <string>

// ���ͳݿ��� �׸��� download �ؼ� ȭ�鿡 �׸��� �Լ�
class Picture
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
		// ���ͳݿ��� �׸��� download �ϴ� �ڵ�.
	}
	void draw() { std::cout << "draw " << url << std::endl; }
};

//---------------------------------------------------
// ������ ����� ����� �߰�

class Frame
{
	Picture* pic;	

public:
	Frame(Picture* pic) : pic(pic) {}

	void draw()
	{
		std::cout << "#######################\n"; 
		pic->draw();  							  
		std::cout << "#######################\n";
	}
};
// �ɱ׸��� �߰��ϴ� ��ü(Decorator)
class Flower
{
	Picture* pic;
public:
	Flower(Picture* pic) : pic(pic) {}

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
	frame.draw();

	Flower flower(&pic);
	flower.draw();
}