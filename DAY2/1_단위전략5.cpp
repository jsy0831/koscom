#include <iostream>
#include <vector>

template<typename T> class MyAlloc
{

};

int main()
{
//	std::vector <int > v; // �̷��� ����ϸ� ǥ�� �޸� �Ҵ��(allocator) ���
						  // new/delete ���

	std::vector<int, MyAlloc<int> > v; // ����� ���� allocator �� ��ü

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
