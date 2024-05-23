#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// 참조계수를 자동으로 관리하는 포인터 역활의 객체, 스마트 포인터를 만들어 봅시다.
// 아래 코드가 안드로이드같은 거의 모든 오픈소스에서 볼수 있는 스마트 포인터 입니다.
template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p) : obj(p) { if (obj != nullptr) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }
	~sp() { if (obj != nullptr) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};
int main()
{
	// 아래 처럼사용하게된다면.. 쉽지 않을까요 ??
	sp<ICalc> calc1 = get_proxy(); // sp<ICalc> calc1( get_proxy() );
	sp<ICalc> calc2 = calc1;

	int n = calc1->Add(10, 20); // (calc1.operator->()) -> Add(10, 20) 의 원리
}




