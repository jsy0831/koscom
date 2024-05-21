// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};

class Derived : public Base
{
public:
	// �ٽ� #1. �����Լ��� override �Ҷ��� virtual ��
	//         ǥ���ص� �ǰ� ǥ������ �ʾƵ� �˴ϴ�.
//	virtual void foo() {}

	// �ٽ� #2. �����Լ� override �ÿ� �Ǽ�(��Ÿ)�� �־
	//          ������ �ƴմϴ�
	// => �ٸ� �����Լ��� ������ٰ� �����Ϸ��� �����ϰ� �˴ϴ�.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// �ٽ� #3. �� ������ �ذ��ϱ� ���� C++11 ���� override Ű�����߰�
	virtual void fooo()      override {} // error
	virtual void goo(double) override {} // error

};

int main()
{
}





