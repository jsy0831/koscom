//  구글에서 "C# stream" 검색후 image 보기로 해보세요

// Decorator - 65 page
#include <iostream>
#include <string>

// 인터넷에서 그림을 download 해서 화면에 그리는 함수
class Picture
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
		// 인터넷에서 그림을 download 하는 코드.
	}
	void draw() { std::cout << "draw " << url << std::endl; }
};

//---------------------------------------------------
// 포함을 사용한 기능의 추가

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
// 꽃그림을 추가하는 객체(Decorator)
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