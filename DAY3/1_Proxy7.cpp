#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// ��������� �ڵ����� �����ϴ� ������ ��Ȱ�� ��ü, ����Ʈ �����͸� ����� ���ô�.
// �Ʒ� �ڵ尡 �ȵ���̵尰�� ���� ��� ���¼ҽ����� ���� �ִ� ����Ʈ ������ �Դϴ�.
template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p) : obj(p) {}
	sp(const sp& other) : obj(other.obj) {}
	~sp() {}

	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};
int main()
{
	sp<ICalc> calc1 = get_proxy();
	sp<ICalc> calc2 = calc1;

	int n = calc1->Add(10, 20);
}




