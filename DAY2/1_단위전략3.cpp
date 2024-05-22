// ��� #2. ���ϴ� ���� �ٸ� Ŭ������
// �޸� �Ҵ� ��å�� ������ Ŭ������ �и��Ѵ�.

// �޸� �Ҵ���� �������̽�
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
		// ���� �޸��� �Ҵ�� ������ allocator ��ü�� �����Ѵ�
		buff = palloc->allocate(sz);

		palloc->deallocate(p, sz);

	}
};

// ���� �پ��� �޸� �Ҵ� ��å�� ���� Ŭ������ �����ϸ� �˴ϴ�.
template<typename T> class MyAlloc : public IAllocator<T>
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
	vector<int> v; 
	MyAlloc<int> a;
	v.set_allocator(&a); // vector�� ����� �޸� �Ҵ�� ����

	v.resize(10); // MyAlloc �� ����ؼ� �޸� �Ҵ�

}