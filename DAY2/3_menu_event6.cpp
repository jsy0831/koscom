#include <memory>

int main()
{
	int* p1 = new int;  // new 한 객체를 raw pointer 로 담으면
	delete p1;			// 반드시 delete 해야 합니다.

	std::shared_ptr<int> sp(new int);	// 스마트 포인터 사용시
										// 자동 delete 됩니다.
	// 주의 사항
	std::shared_ptr<int> sp1 = new int; // error. 
	std::shared_ptr<int> sp2( new int); // ok
}