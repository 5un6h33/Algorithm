#include <iostream>
#include <string>
using namespace std;



// 함수 오버로딩: int    sum(int x, int y), 
//                double sum(double x, double y)
//                float  sum(float x, float y, float z)
// 함수 오버라이딩 (상속의 특수한 경우 사용)
//void Text::append(string _extra)
//void Fancy::append(string _extra)

class Text {
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	/*구현*/ //get()함수 virtual 로 구현
	virtual void append(string _extra) { text += _extra; }
};

class FancyText : public Text {
private:
	// string text;b접근이 안됨, Base Class에서 private
	string left_brac;
	string right_brac;
	string connector;
public:
	// initialization list는 생성자를 호출할 수 있게 해준다.
	FancyText(string _t, string _lb, string _rb, string _con) :
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	/*구현*/ //override 키워드 사용한 get()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
	/*구현*/ //override 키워드 사용한 append()함수 구현
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("FIXED") {}
	/*구현*/ //override 키워드 사용한 append()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
};

int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2; // Base <- Derived 가능
	//t2 = t1; // Derived <- Base 불가능

	return 0;
}