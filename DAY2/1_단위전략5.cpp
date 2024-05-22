#include <iostream>
#include <vector>

template<typename T> class MyAlloc
{

};

int main()
{
//	std::vector <int > v; // 이렇게 사용하면 표준 메모리 할당기(allocator) 사용
						  // new/delete 사용

	std::vector<int, MyAlloc<int> > v; // 사용자 정의 allocator 로 교체

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
