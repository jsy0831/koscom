// 방법 #2. 변하는 것을 다른 클래스로
// 메모리 할당 정책을 별도의 클래스로 분리한다.

// 특징 : 메모리 할당 방식이 vector 와 분리된 별도의 클래스로 제공된다
// 장점 : vector 뿐 아니라 list, set, map 등 다른 컨테이너도 사용가능

// 단점 : 메모리 할당, 해지 함수가 가상함수이다.
//       호출시 오버헤드가 있다


// 메모리 할당기의 인터페이스
template<typename T>
struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;
	virtual ~IAllocator() {}
};

template<typename T>
class vector
{
	T* buff;
	IAllocator* palloc = nullptr;
public:
	void set_allocator(IAllocator<T>* p) { palloc = p; }

	void resize(std::size_t sz)
	{
		// 이제 메모리의 할당과 해지는 allocator 객체에 의존한다
		buff = palloc->allocate(sz);

		palloc->deallocate(p, sz);

	}
};

// 이제 다양한 메모리 할당 정책을 담은 클래스를 제공하면 됩니다.
template<typename T> class MyAlloc : public IAllocator<T>
{
public:
	T* allocate(std::size_t sz) override
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz) override { free(p); }
};
int main()
{
	vector<int> v; 
	MyAlloc<int> a;
	v.set_allocator(&a); // vector가 사용할 메모리 할당기 연결

	v.resize(10); // MyAlloc 을 사용해서 메모리 할당

}