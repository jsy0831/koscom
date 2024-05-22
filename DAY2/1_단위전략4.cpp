// ��� #3. Policy Base Design


template<typename T,      // ������ ����� Ÿ��
	     typename Alloc>  // �޸� �Ҵ��
class vector
{
	T* buff;
	
	Alloc ax;	// �޸� �Ҵ�� ��ü
				// ���� vector �� ��� ��� �Լ����� �޸� �Ҵ��� �ʿ��ϸ�
				// ax �� ���� ��ӵ� �Լ��� ���.
public:

	void resize(std::size_t sz)
	{
		buff = ax.allocate(sz);

		ax.deallocate(p, sz);
	}
};

// �����̳ʰ� ����� �پ��� �޸� �Ҵ�� ��ü�� �����մϴ�.
// �Ҵ�� ��ü�� �ݵ�� "allocate/deallocate"�� �־�� �մϴ�.
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