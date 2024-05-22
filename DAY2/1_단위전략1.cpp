template<typename T>
class vector
{
public:
	void resize(int sz)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 

		T* p = new T[sz]; // �̷��� ���� �ڵ带 �ۼ��ߴٸ�
		delete[] p;       // �޸� �Ҵ� ����� �����Ҽ� �����ϴ�
	}
};

int main()
{
	std::vector<int> v(10, 0);  // 10���� 0���� �ʱ�ȭ
	v.resize(20);				// ũ�⸦ 20���� ����
}