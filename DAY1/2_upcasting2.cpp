// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
//	std::vector<Dog*>    v1; // Dog 객체만 보관
	std::vector<Animal*> v2; // Animal 로 부터 파생된
							 // 모든 동물 객체 보관
						     // "동종을 보관"

	// upcasting 활용 1. 동종을 보관하는 컨테이너
}