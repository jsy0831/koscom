#include <iostream>
#include <vector>

// �Ŀ�����Ʈ ���� ���α׷��� ����� ������ ������ ���ô�.

// 1. �� ������ Ÿ��ȭ �ϸ� ���մϴ�.

class Rect
{
	// x, y, w, h, �����ڵ��� �ڵ�� ����
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Rect*> v;

}

