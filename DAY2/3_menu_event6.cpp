#include <memory>

int main()
{
	int* p1 = new int;  // new �� ��ü�� raw pointer �� ������
	delete p1;			// �ݵ�� delete �ؾ� �մϴ�.

	std::shared_ptr<int> sp(new int);	// ����Ʈ ������ ����
										// �ڵ� delete �˴ϴ�.
	// ���� ����
	std::shared_ptr<int> sp1 = new int; // error. 
	std::shared_ptr<int> sp2( new int); // ok
}