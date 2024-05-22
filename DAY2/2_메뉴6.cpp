#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 예외를 위한 클래스
class UnsupportedOperation {};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }


	virtual void command() = 0;


	// 아래 멤버 함수들은 PopupMenu 에서만 필요하고
	// MenuItem 에서는 필요 없습니다.
	// 하지만 BaseMenu 에서 함수 선언을 제공하면 사용자가 편리하게 사용가능합니다.
	// 기본 구현은 "예외 전달" 기술로 구현하는 경우가 많습니다.
	virtual void add(BaseMenu*) { throw UnsupportedOperation(); }
	virtual BaseMenu* get_menu(int idx) { throw UnsupportedOperation(); }

};






class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

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
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			// 선택된 메뉴 실행
			v[cmd - 1]->command();
		}


	}

	BaseMenu* get_menu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	
	MenuItem* mi1 = new MenuItem("화면지우기", 11);

	// root 에는 2개의 메뉴가 있습니다.
	root->add(pm1);
	root->add(mi1);

	root->get_menu(0)->add(new MenuItem("HD", 21));


	root->command();

}


