// 2_싱글톤7.cpp 추가..   6번 복사해오세요
#include <iostream>

/*
#define MAKE_SINGLETON(classname)						\	
private:												\
	classname() {}										\
	classname(const classname&) = delete;				\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& get_instance()					\
	{													\
		static classname instance;						\
		return instance;								\
	}
	*/

#include "helper.h"

class Cursor
{
	MAKE_SINGLETON(Cursor)
};




int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








