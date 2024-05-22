#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>
#include <memory>		// 스마트 포인터를 위한 헤더.
using namespace std::placeholders;


// 아래 코드에서 BaseMenu* => std::shared_ptr<BaseMenu> 로 모두 바꾸세요



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
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";
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

	std::vector<HANDLER> handler_vector; // 메뉴 선택시 여러곳에 알려주기위해

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
		// 메뉴 선택시 등록된 모든 함수를 호출
		for (auto f : handler_vector)
			f();
	}
};

void new_file()
{
	std::cout << "새파일 작업\n";
	_getch();
}
void work(int id)
{
	std::cout << "다양한 작업 : " << id << std::endl;
	_getch();
}

int main()
{
	std::shared_ptr<PopupMenu> root ( new PopupMenu("ROOT") );

	root->add( std::shared_ptr<MenuItem>(new MenuItem("새파일", 11, &new_file)));

	root->add(std::shared_ptr<MenuItem>(new MenuItem("화면지우기", 12, std::bind(&work, 12))));
	root->add(std::shared_ptr<MenuItem>(new MenuItem("화면색상변경", 13, std::bind(&work, 13))));

	root->command();
}




