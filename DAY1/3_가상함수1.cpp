#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// �Լ� override : ��� Ŭ���� �Լ��� �Ļ� Ŭ���� "�ٽ� ����" �ϴ� ��
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry();
	Dog d;    d.cry();

	Animal* p = &d; 
//  if ( ������Է� == 1 ) p = &a;
	p->cry();
}

// p->cry() �� ��� �Լ��� �����Ұ��ΰ� ? "�Լ� ���ε�(binding)" �̶�� �մϴ�

// 1. static binding : �����Ϸ��� ������ �ð��� ��� �Լ��� ȣ������ ����
//                     "�����Ϸ��� p�� ����Ű�� ��ü�� ������ �˼� ����."
//					   �����Ϸ��� �ƴ� ���� p�� Animal* ��� �͸� �˼� �ִ�
//                     call Animal::cry ���� �ڵ� ����
// �� ����������, ������.
// C++/C# ����� �⺻ ���ε�

// 2. dynamic binding : ������ �ð����� p�� ����Ű�� �޸𸮸� �����ϴ� ���� ����
//						����ð��� �޸� ������ �Լ� ȣ�� ����
//						p�� ����Ű�� ���� Dog��� Dog::cry ȣ��
// ���������� ������.
// Java, Python, swift���� ��κ��� ��ü���� ����� ���ε� ��å
// C++/C# �� �����Լ�!