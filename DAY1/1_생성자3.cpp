// protected �������� �ǵ� 
// => �ڽ��� ��ü�� ����� ������(�߻��� ����. abstract)
// => �Ļ� Ŭ������ ��ü�� ����� �ִ�(��ü�� ����. concrete)

class Animal
{
//public:		// 1, 2 ��� ���� �ƴ�
//private:		// 1, 2 ��� ����!
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {}
};
int main()
{
	// ������ ������ ��� ��� ������
	Animal a;	// 1	error
	Dog    d;	// 2	ok
}



