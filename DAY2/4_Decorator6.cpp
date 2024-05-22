#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


// 모든 Stream 들이 사용법이 동일하도록하기 위해
// 규칙(인터페이스) 설계

struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// 그외에 "Read, Flush, IsOpen..." 등의 Stream 관련 다양한 함수를 약속
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	// File 에 쓸때 암호화 해서 쓰는 기능이 필요 하다.

	// 1. 상속을 사용한 기능 추가. 
	// => FileStream 의 파생 클래스인 EncrpytFileStream 을 만들자.
	// => 다양한 요구 조건에 따라 계속 파생 클래스를 만들어야 하고
	// => 2가지 이상의 기능을 동시에 제공하기 어려워 진다.
	// => FileStream 뿐 아니라 NetworkStream 에도 필요 하다.


	// 2. Decorator 패턴을 사용하면 어떨까 ?
	FileStream fs("a.txt");
	fs.Write("AAA");

	ZipDecorator zd(&fs);
	zd.Write("AAA");  // 1. 데이타 압축을 하고
					  // 2. fs.Write()로 전달.

	EncryptDecorator ed(&zd);
	ed.Write("AAA"); // 1. 암호화를 하고
					 // 2. zd.Write()로 전달.


}