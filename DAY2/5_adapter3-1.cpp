#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 상속을 사용한 adapter
// => 기반 클래스의 모든 기능을 외부에 노출하겠다는 의도
// => list 를 stack 으로 바꾸는 어답터에서는 좋지 않은 디자인..
// => java 의 stack 이 vector로 부터 상속 되어서 구현 - 나쁜 디자인의 대표적 예!!

// 아래 처럼 포함을 사용한 adapter 가 훨씬 좋은 디자인!
template<typename T> class stack 
class stack
{
	std::list<T> c;
public:
	void push(T& a) { c.push_back(a); }
	void pop()      { c.pop_back(); }
	T& top()        { return c.back(); }
};
int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // ???
}