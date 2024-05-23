#include <iostream>
#include <string>
#include <map>
#include "Helper.h" // 2���ÿ� ���� ���. git  �� �ֽ��ϴ�.

// SRP : Single Responsibility Principle
// => �ϳ��� Ŭ������ �ϳ��� å�Ӹ� 

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// ImageFactory ������ Image �� private ����� ������ �����ϵ���!!
	friend class ImageFactory;
};

// Image ��ü�� ����/���� �ϴ� ����� �����ϴ� Ŭ����
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



