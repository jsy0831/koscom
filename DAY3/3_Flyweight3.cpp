#include <iostream>
#include <string>
#include <map>
#include "Helper.h" // 2교시에 만든 헤더. git  에 있습니다.

// SRP : Single Responsibility Principle
// => 하나의 클래스는 하나의 책임만 

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// ImageFactory 에서는 Image 의 private 멤버에 접근이 가능하도록!!
	friend class ImageFactory;
};

// Image 객체를 생성/공유 하는 기능을 제공하는 클래스
class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it != image_map.end())
		{
			img = it->second;
		}
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return img;
	}
};







int main()
{
	ImageFactory& factory = ImageFactory::get_instance();


	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



