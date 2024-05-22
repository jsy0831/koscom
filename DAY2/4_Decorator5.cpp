#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


// ��� Stream ���� ������ �����ϵ����ϱ� ����
// ��Ģ(�������̽�) ����

struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// �׿ܿ� "Read, Fluse, IsOpen..." ���� Stream ���� �پ��� �Լ��� ���
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
	FileStream fs("a.txt");
	fs.Write("AAA");


//	NetworkStream ns("127.100.100.1", 3000);
//	ns.Write("AAA"); // ��Ʈ��Ʈ�� ���ؼ� ����Ÿ ����

	// �׿ܿ� PipeStream, MemoryStream � �ִٰ� ������ ���ô�.

}