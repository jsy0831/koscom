#include <iostream>
#include <vector>

// �Ŀ�����Ʈ ���� ���α׷��� ����� ������ ������ ���ô�.

// 1. �� ������ Ÿ��ȭ �ϸ� ���մϴ�.

// 2. ��� ������ ������ Ư¡�� �ִ�(�����..)
//    ������ ��� Ŭ������ �ִٸ� ��� ������ �ϳ��� �����̳ʿ� �����Ҽ� �ִ�

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// x, y, w, h, �����ڵ��� �ڵ�� ����
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v;
	std::vector<Shape*> v;

}

