template<typename T>
class vector
{
public:
	void resize(int sz)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

		T* p = new T[sz]; // 이렇게 직접 코드를 작성했다면
		delete[] p;       // 메모리 할당 방식을 변경할수 없습니다
	}
};

int main()
{
	std::vector<int> v(10, 0);  // 10개를 0으로 초기화
	v.resize(20);				// 크기를 20으로 변경
}