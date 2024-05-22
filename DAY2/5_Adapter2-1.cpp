// ZipDecorator 복사해 오세요

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

// ObjectAdapter 복사 해오세요

class ObjectAdapter : public Shape
{
	TextView* tview; 
public:
	ObjectAdapter(TextView* v) : tview(v) {}

	void draw() { tview->show(); }
};

// Decorator 와 Adapter  코드는 유사해 보입니다.
// 그런데, 의도가 완전히 다릅니다.

// Adapter   : 기능의 추가가 아닌 인터페이스의 변경 (함수 이름의 변경)이 목표
//				"show" => "draw" 로 변경하기 위해서 만든것

// Decorator : 인터페이스(함수이름)은 동일하게 유지 됩니다.
//				기능을 추가하기 위한 것이 목표 입니다
//				동일한 "Write" 를 유지하면서 압축기능의 추가.

// 다양한 디자인 패턴이 유사해 보이면 항상 각 패턴의 "의도"를 파악하세요