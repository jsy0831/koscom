// 방법 #1. 변하는 것을 가상함수로 - template method

template<typename T>
class vector
{
	T* buff;
public:
	void resize(std::size_t sz)
	{
		buff = allocate(sz);
		
		// ... resize.. 을 위한 코드.. 

		deallocate(buff, sz);
	}
	virtual T* allocate(std::size_t sz) { return new T[sz]; }
	virtual void deallocate(T* p, std::size_t sz) { delete[] p; }
};

// 위 코드의 의도
// => 메모리 할당/해지 방법을 변경하려면
// => vector 의 파생 클래스를 만들어서 약속된 가상함수를 override 하라는것
template<typename T> class MyVector : public vector<T>
{
public:
	T* allocate(std::size_t sz) override 
	{ 
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz) override
	{
		free(p);
	}
};

int main()
{

}