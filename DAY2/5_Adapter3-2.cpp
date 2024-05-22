#include <iostream>
#include <list>
#include <vector>
#include <deque>

/*
template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	void push(T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};
*/
#include <stack> // C++ 표준 stack 이 위처럼 되어 있습니다.
				 // 흔히 stack adapter 라고 합니다.
int main()
{
	std::stack<int, std::list<int> > s;
	std::stack<int, std::vector<int> > s2;
	std::stack<int> s3;
	s.push(10);
}