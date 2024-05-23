#include <iostream>

// ½Ì±ÛÅæ1.cpp : ¿ÀÁ÷ ÇÑ°³ÀÇ °´Ã¼¸¦ static Áö¿ªº¯¼ö·Î ¸¸µå´Â ¸ðµ¨
//              => data ¸Þ¸ð¸®¿¡ °´Ã¼ »ý¼º

// ½Ì±ÛÅæ2.cpp : ÇÑ°³ÀÇ °´Ã¼¸¦ Èü¿¡ ¸¸µå´Â ¸ðµ¨

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; 

	static Cursor* sinstance;

public:
	static Cursor& get_instance()
	{
		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








