// 1_������2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& n, int a) : name(n), age(a) {}
};
// Person ���� ���� ��ӹ޴� Student ����� ������
// 1. int id  ��� �߰��� ������
// 2. ������ ����� ������
// 3. main ���� Student ��ü ������ ������

class Student : public Person
{
	int id;
public:
//	Student(int n) : id(n) {} // error.
//	Student(int n) : Person(), id(n) {} // �����Ϸ��� ������ �ڵ�

	Student(const std::string& name, int age, int id)
		: Person(name, age), id(id) {}
};

int main()
{
	Student s("kim", 20, 15);

//	Person p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
	Person p2("kim", 20); // ok. �ʱ�ȭ�� ��ü. �����ϴ�!!
}


