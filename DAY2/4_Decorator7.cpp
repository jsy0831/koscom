#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


// ��� Stream ���� ������ �����ϵ����ϱ� ����
// ��Ģ(�������̽�) ����

struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// �׿ܿ� "Read, Flush, IsOpen..." ���� Stream ���� �پ��� �Լ��� ���
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
		printf("%s ����\n", s.c_str());
	}
};

// �پ��� Stream Decorator ��...
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* stream) : stream(stream) {}

	void Write(const std::string& data) override
	{
		auto s = "[ " + data + " ] �����"; // �����ϴ� �ڵ� �ۼ�

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
		auto s = "[ " + data + " ] ��ȣȭ��"; 

		stream->Write(s);
	}
};
int main()
{
	FileStream fs("a.txt");
//	fs.Write("AAA");

	ZipDecorator zd(&fs);
//	zd.Write("AAA");	// 1. ����Ÿ ������ �ϰ�
						// 2. fs.Write()�� ����.

	EncryptDecorator ed(&zd);
	ed.Write("AAA");	// 1. ��ȣȭ�� �ϰ�
						// 2. zd.Write()�� ����.


}