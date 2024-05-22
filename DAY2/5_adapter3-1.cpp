#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ����� ����� adapter
// => ��� Ŭ������ ��� ����� �ܺο� �����ϰڴٴ� �ǵ�
// => list �� stack ���� �ٲٴ� ����Ϳ����� ���� ���� ������..
// => java �� stack �� vector�� ���� ��� �Ǿ ���� - ���� �������� ��ǥ�� ��!!

// �Ʒ� ó�� ������ ����� adapter �� �ξ� ���� ������!
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