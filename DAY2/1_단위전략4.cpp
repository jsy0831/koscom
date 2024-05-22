// 방법 #3. Policy Base Design

// vector 같은 클래스가 사용하는 어떤 정책(메모리 할당 방법)
// => 별도의 클래스로 만들어서
// => template 인자로 교체 할수 있도록 하는 디자인

// strategy 패턴      : 정책 클래스를 인터페이스로 교체
// policy base 디자인 : 정책 클래스를 template 인자로 교체

template<typename T,      // 저장할 요소의 타입
	     typename Alloc>  // 메모리 할당기
class vector
{
	T* buff;
	
	Alloc ax;	// 메모리 할당기 객체
				// 이제 vector 의 모든 멤버 함수에서 메모리 할당이 필요하면
				// ax 가 가진 약속된 함수를 사용.
public:

	void resize(std::size_t sz)
	{
		buff = ax.allocate(sz);

		ax.deallocate(p, sz);
	}
};

// 컨테이너가 사용할 다양한 메모리 할당기 객체를 제공합니다.
// 할당기 객체는 반드시 "allocate/deallocate"가 있어야 합니다.
template<typename T> class MyAlloc 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, std::size_t sz)  { free(p); }
};



int main()
{
	vector<int, MyAlloc<int>> v;

}