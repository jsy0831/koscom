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

// 다양한 Stream Decorator 들...
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* stream) : stream(stream) {}

	void Write(const std::string& data) override
	{
		auto s = "[ " + data + " ] 압축됨"; // 압축하는 코드 작성

		stream->Write(s);
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* stream) : stream(stream) {}

	void Write(const std::string& data) override
	{
		auto s = "[ " + data + " ] 암호화됨"; 

		stream->Write(s);
	}
};
int main()
{
	FileStream fs("a.txt");
//	fs.Write("AAA");

	ZipDecorator zd(&fs);
//	zd.Write("AAA");	// 1. 데이타 압축을 하고
						// 2. fs.Write()로 전달.

	EncryptDecorator ed(&zd);
	ed.Write("AAA");	// 1. 암호화를 하고
						// 2. zd.Write()로 전달.


}