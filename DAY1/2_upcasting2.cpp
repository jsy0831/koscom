// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
//	std::vector<Dog*>    v1; // Dog ��ü�� ����
	std::vector<Animal*> v2; // Animal �� ���� �Ļ���
							 // ��� ���� ��ü ����
						     // "������ ����"

	// upcasting Ȱ�� 1. ������ �����ϴ� �����̳�
}