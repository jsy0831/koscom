#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER> > notif_map;

public:

	// 주어진 키값으로 관찰자(함수)등록
	void addObserver(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key]) // notif_map[key] 는 결국 vector!
		{
			f(hint);
		}
	}
};




void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }

int main()
{
	// IOS 개발에 널리 사용되는 "통보센터" 라는 클래스를 만들어 봅시다.
	NotificationCenter nc;

	// 현재 코드에서 통보센터에 등록되는 함수는 "void(void*)" 이어야 합니다

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY",      std::bind(&goo, _1, 11)); // goo(void*, 11)
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 12));

	nc.addObserver("DISCONNECT_WIFI", 
					[](void* p) { std::cout << "lambda\n"; });

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}

// 중재자 패턴(Mediator)
// => 객체간이 상호 관계가 복잡하면 중재자를 도입해라
// => 객체간의 M:N 관계를 중재자와 객체간의 1:N 의 관계로 변경
// => 위 통보 센터가 결국 중재자 역활을 하게 됩니다.


