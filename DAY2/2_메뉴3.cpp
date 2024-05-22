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

	// 메뉴 선택시 호출될 함수
	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

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

	// 아래 코드가 핵심입니다. 팝업메뉴를 선택할때 동작
	void command()
	{
		auto sz = v.size(); 

		for (int i = 0; i < sz; i++)
		{
			std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
 		}
		std::cout << sz + 1 << ". 종료\n";

		std::cout << "메뉴를 선택하세요 >> ";
		int cmd;
		std::cin >> cmd;

		// 선택된 메뉴 실행
		v[cmd - 1]->command();
	}
};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	// 아래 코드를 생각해 보세요
	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // 팝업 메뉴를 눌렀을때의 동작을 생각해 보세요
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >> 
}




