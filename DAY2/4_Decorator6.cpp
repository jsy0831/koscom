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

int main()
{
	// File �� ���� ��ȣȭ �ؼ� ���� ����� �ʿ� �ϴ�.

	// 1. ����� ����� ��� �߰�. 
	// => FileStream �� �Ļ� Ŭ������ EncrpytFileStream �� ������.
	// => �پ��� �䱸 ���ǿ� ���� ��� �Ļ� Ŭ������ ������ �ϰ�
	// => 2���� �̻��� ����� ���ÿ� �����ϱ� ����� ����.
	// => FileStream �� �ƴ϶� NetworkStream ���� �ʿ� �ϴ�.


	// 2. Decorator ������ ����ϸ� ��� ?
	FileStream fs("a.txt");
	fs.Write("AAA");

	ZipDecorator zd(&fs);
	zd.Write("AAA");  // 1. ����Ÿ ������ �ϰ�
					  // 2. fs.Write()�� ����.

	EncryptDecorator ed(&zd);
	ed.Write("AAA"); // 1. ��ȣȭ�� �ϰ�
					 // 2. zd.Write()�� ����.


}