// 방법 #1. 변하는 것을 가상함수로 - template method

// 특징 : 메모리할당하는 정책을 vector 가 포함하게 된다.
// 단점 : vector외의 다른 컨테이너 (list, map, set등) 에도 메모리 할당
//       방식을 변경하려면 상속된 클래스를 만들어서 동일한 코드를 작성해야한다

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
		return static_cast<T*>( malloc(sizeof(T) * sz) );
	}
	void deallocate(T* p, std::size_t sz) override
	{
		free(p);
	}
};

int main()
{

}