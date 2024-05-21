// 1_�߻�Ŭ����1.cpp - 10page
// �߻� Ŭ���� : ���������Լ��� �Ѱ� �̻� �ִ� Ŭ����
// Ư¡ : ��ü�� �����Ҽ� ����.
// �ǵ� : Ư���Լ�(��ӵ� �Լ�)�� �ݵ�� ������ ���� �ϴ� ��
class Shape
{
public:
	virtual void draw() = 0; // ���� �����Լ�(pure virtual function)
						     // Ư¡ : �����ΰ� ���� "=0" ���� ǥ��
};
class Rect : public Shape
{
	// draw�� �����θ� �������� ������ Rect �� �߻� Ŭ���� �Դϴ�(abstract)
	// draw�� �����θ� �����ϸ� Rect �� �߻��� �ƴմϴ�(��ü Ŭ����, concrete)
public:
	virtual void draw() override {}
};

int main()
{
	Shape  s; // error
	Shape* p; 
	Rect  r;
}
