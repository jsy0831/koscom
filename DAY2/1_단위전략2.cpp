// ��� #1. ���ϴ� ���� �����Լ��� - template method

template<typename T>
class vector
{
	T* buff;
public:
	void resize(std::size_t sz)
	{
		buff = allocate(sz);
		
		// ... resize.. �� ���� �ڵ�.. 

		deallocate(buff, sz);
	}
	virtual T* allocate(std::size_t sz) { return new T[sz]; }
	virtual void deallocate(T* p, std::size_t sz) { delete[] p; }
};

// �� �ڵ��� �ǵ�
// => �޸� �Ҵ�/���� ����� �����Ϸ���
// => vector �� �Ļ� Ŭ������ ���� ��ӵ� �����Լ��� override �϶�°�
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