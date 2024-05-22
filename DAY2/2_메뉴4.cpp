#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// Folder 는 File 을 보관하지만 Folder 도 보관한다.
// => Folder 와 File 을 같이 보관해야 한다 - 공통의 기반 클래스 필요

// PopupMenu 는 MenuItem 을 보관하지만 PopupMenu 자신도 보관 가능
// => 공통의 기반 클래스 필요

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }


	// 모든 메뉴는 선택될수 있다.
	virtual void command()  = 0;

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


			if (cmd == sz + 1) // 종료 메뉴
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;


			// 선택된 메뉴 실행
			v[cmd - 1]->command();
		}


	}
};


int main()
{
	MenuItem m1("참치 김밥",   11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m9("라면",        21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);
			
	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&kimbab); // ?? 핵심. 잘 생각해 보세요
	pm.add(&m9);

	pm.command(); 
}




