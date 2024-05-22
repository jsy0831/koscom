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
	Picture* pic;	// 핵심 : "포인터 또는 참조" 멤버로 추가
					// => 외부에 이미 생성된 Picture 객체를 가리키겠다는 의도

public:
	Frame(Picture* pic) : pic(pic) {}

	void draw()
	{
		std::cout << "#######################\n"; // 추가된 기능
		pic->draw();  							  // 기존의 기능 수행
		std::cout << "#######################\n";
	}
};

int main()
{
	Picture pic("www.naver.com/a.png");	
//	pic.draw();

	Frame frame(&pic); // pic 라는 이미 생성된 객체에 기능을 추가하는 객체
					   // 클래스가 아닌 객체에 기능 추가
	frame.draw();
}