#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() const { return title; }

	// �޴� ���ý� ȣ��� �Լ�
	void command()
	{
		std::cout << get_title() << " �޴��� ���õ�\n";

		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// �Ʒ� �ڵ尡 �ٽ��Դϴ�. �˾��޴��� �����Ҷ� ����
	void command()
	{
		auto sz = v.size(); 

		for (int i = 0; i < sz; i++)
		{
			std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
 		}
		std::cout << sz + 1 << ". ����\n";

		std::cout << "�޴��� �����ϼ��� >> ";
		int cmd;
		std::cin >> cmd;

		// ���õ� �޴� ����
		v[cmd - 1]->command();
	}
};


int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	// �Ʒ� �ڵ带 ������ ������
	PopupMenu pm("������ ���� �޴�");
	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // �˾� �޴��� ���������� ������ ������ ������
					// 1. ���
					// 2. ���
					// 3. ����
					// �޴��� �����ϼ��� >> 
}




