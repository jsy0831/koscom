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
// 스티커 사진 처럼 다운로드한 그림에 다양한 이모티콘을 추가하고 싶다.

// 상속을 통한 기능의 추가
class Frame : public Picture
{
public:
	Frame(const std::string& url) : Picture(url) {}

	void draw()
	{
		std::cout << "#######################\n";	// 추가된 기능
		Picture::draw();							// 기존의 기능 수행
		std::cout << "#######################\n";
	}
};


int main()
{
	Picture pic("www.naver.com/a.png");
	pic.draw();
}