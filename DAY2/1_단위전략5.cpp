#include <iostream>
#include <vector>

// 사용자 정의 allocator 를 만들때는 지켜야 하는 규칙이 있습니다.
template<typename T> class MyAlloc
{
public:
	// #1. 메모리 할당/해지를 책임지는 2개의 함수
	inline T* allocate(std::size_t sz)
	{
		printf("MyAlloc allocate : %d\n", sz);

		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, std::size_t sz) 
	{ 
		printf("MyAlloc deallocate : %d, %p\n", sz, p);
		free(p); 
	}

	// #2. 아래 3개의 멤버가 관례적으로 필요 합니다
	typedef T value_type;
	MyAlloc() {} 
	template<typename U> MyAlloc(const MyAlloc<U>&) {}
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
