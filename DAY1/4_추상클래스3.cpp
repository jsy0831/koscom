#include <iostream>


// People �� ī�޶� �ʿ� �Ҷ� "HDCamera" ��� ��ü Ŭ���� �̸�����
// "ICamera ��� �������̽� �̸�" �� ����ϴ� ���� ���� - ��ü �����ϱ�����


// ���� ���� ������ ��Ģ(DIP, Dependency Inversion Principle)
// => ��ü ���� �߻��� �����ض�!





// ���� ���̽� : ���Ѿ��ϴ� ��Ģ(���� �����Լ�)�� ���� ���
// �߻� Ŭ���� : ���Ѿ��ϴ� ��Ģ(���� �����Լ�) + �ٸ� ����� �ִ� ���

// java, C# : interface, abstract ��� ������ Ű���� ������
// C++      : ������ Ű���� ����. �߻� Ŭ���� �������� ��� ����


// ����� ī�޶� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�

// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�." ��� ��������
//        "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�." ��� ǥ��
//class ICamera
struct ICamera
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // �������̽��� �ᱹ ��� Ŭ����!!
						  // ��� Ŭ���� �Ҹ��ڴ� �����̾�� �Ѵ�.
};




// ī�޶� ����ڴ� �ݵ�� "��Ģ" ��� ����ؾ� �մϴ�.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};
// ��� ī�޶�� ��Ģ�� ���Ѿ� �մϴ�
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};
class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); // People Ŭ������ �������� �ʰ�
					    // ���ο� ��ǰ�� ����Ҽ� �ִ�.

}





