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
	Picture* pic;	// �ٽ� : "������ �Ǵ� ����" ����� �߰�
					// => �ܺο� �̹� ������ Picture ��ü�� ����Ű�ڴٴ� �ǵ�

public:
	Frame(Picture* pic) : pic(pic) {}

	void draw()
	{
		std::cout << "#######################\n"; // �߰��� ���
		pic->draw();  							  // ������ ��� ����
		std::cout << "#######################\n";
	}
};

int main()
{
	Picture pic("www.naver.com/a.png");	
//	pic.draw();

	Frame frame(&pic); // pic ��� �̹� ������ ��ü�� ����� �߰��ϴ� ��ü
					   // Ŭ������ �ƴ� ��ü�� ��� �߰�
	frame.draw();
}