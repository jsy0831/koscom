#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// linked list �� �̹� �ִµ�, stack �� �ʿ� �մϴ�.
// 1. stack �� ��� ����� ���� ����.
// 2. list �� �Լ��̸��� stack ó�� ���̵��� ����

// list �� �̸��� stack ó�� ���̰� �����մϴ�.
template<typename T> class stack : public std::list<T> 
class stack
{
public:
	void push(T& a) { std::list<T>::push_back(a); }
	void pop()      { std::list<T>::pop_back(); }
	T&   top()      { return std::list<T>::back(); }
};


int main()
{
	stack<int> s;
	s.push(10);
}