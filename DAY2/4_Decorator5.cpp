#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


// 모든 Stream 들이 사용법이 동일하도록하기 위해
// 규칙(인터페이스) 설계

struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// 그외에 "Read, Fluse, IsOpen..." 등의 Stream 관련 다양한 함수를 약속
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
	FileStream fs("a.txt");
	fs.Write("AAA");


//	NetworkStream ns("127.100.100.1", 3000);
//	ns.Write("AAA"); // 네트워트를 통해서 데이타 전달

	// 그외에 PipeStream, MemoryStream 등도 있다고 생각해 봅시다.

}