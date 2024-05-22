// ZipDecorator ������ ������

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

// ObjectAdapter ���� �ؿ�����

class ObjectAdapter : public Shape
{
	TextView* tview; 
public:
	ObjectAdapter(TextView* v) : tview(v) {}

	void draw() { tview->show(); }
};

// Decorator �� Adapter  �ڵ�� ������ ���Դϴ�.
// �׷���, �ǵ��� ������ �ٸ��ϴ�.

// Adapter   : ����� �߰��� �ƴ� �������̽��� ���� (�Լ� �̸��� ����)�� ��ǥ
//				"show" => "draw" �� �����ϱ� ���ؼ� �����

// Decorator : �������̽�(�Լ��̸�)�� �����ϰ� ���� �˴ϴ�.
//				����� �߰��ϱ� ���� ���� ��ǥ �Դϴ�
//				������ "Write" �� �����ϸ鼭 �������� �߰�.

// �پ��� ������ ������ ������ ���̸� �׻� �� ������ "�ǵ�"�� �ľ��ϼ���