#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>
#include <memory>		// ����Ʈ �����͸� ���� ���.
using namespace std::placeholders;


// �Ʒ� �ڵ忡�� BaseMenu* => std::shared_ptr<BaseMenu> �� ��� �ٲټ���



class UnsupportedOperation {};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }


	virtual void command() = 0;

	virtual void add(std::shared_ptr<BaseMenu>) { throw UnsupportedOperation(); }
	virtual std::shared_ptr<BaseMenu> get_menu(int idx) { throw UnsupportedOperation(); }

};








class PopupMenu : public BaseMenu
{
	std::vector<std::shared_ptr<BaseMenu>> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(std::shared_ptr<BaseMenu> m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
			}
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}
	}

	std::shared_ptr<BaseMenu> get_menu(int idx) { return v[idx]; }
};

class MenuItem : public BaseMenu
{
	using HANDLER = std::function<void()>;

	std::vector<HANDLER> handler_vector; // �޴� ���ý� �������� �˷��ֱ�����

	int id;
public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr)
		: BaseMenu(title), id(id)
	{
		if (h != nullptr)
			handler_vector.push_back(h);
	}

	void add_handlder(HANDLER h) { handler_vector.push_back(h); }


	void command()
	{
		// �޴� ���ý� ��ϵ� ��� �Լ��� ȣ��
		for (auto f : handler_vector)
			f();
	}
};

void new_file()
{
	std::cout << "������ �۾�\n";
	_getch();
}
void work(int id)
{
	std::cout << "�پ��� �۾� : " << id << std::endl;
	_getch();
}

int main()
{
	std::shared_ptr<PopupMenu> root ( new PopupMenu("ROOT") );

	root->add( std::shared_ptr<MenuItem>(new MenuItem("������", 11, &new_file)));

	root->add(std::shared_ptr<MenuItem>(new MenuItem("ȭ�������", 12, std::bind(&work, 12))));
	root->add(std::shared_ptr<MenuItem>(new MenuItem("ȭ����󺯰�", 13, std::bind(&work, 13))));

	root->command();
}




