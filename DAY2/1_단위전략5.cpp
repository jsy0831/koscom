#include <iostream>
#include <vector>

// ����� ���� allocator �� ���鶧�� ���Ѿ� �ϴ� ��Ģ�� �ֽ��ϴ�.
template<typename T> class MyAlloc
{
public:
	// #1. �޸� �Ҵ�/������ å������ 2���� �Լ�
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

	// #2. �Ʒ� 3���� ����� ���������� �ʿ� �մϴ�
	typedef T value_type;
	MyAlloc() {} 
	template<typename U> MyAlloc(const MyAlloc<U>&) {}
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
