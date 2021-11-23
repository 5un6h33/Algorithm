// text.hpp

#ifndef TEXT_H_
#define TEXT_H_
#include<string>
using namespace std;

class Text {
private:
	string text;
public:
	Text(string _t);
    virtual string get();
	virtual void append(string _extra);
};

#endif

// text.cpp

#include"Text.hpp"

Text::Text(string _t) : text(_t) {}
string Text::get() { return text; }
void Text::append(string _extra) { text += _extra; }

// fancytext.hpp

#ifndef FANCYTEXT_H_
#define FANCYTEXT_H_
#include<string>
#include"Text.hpp"
using namespace std;

class FancyText : public Text {
private:
	// string text;b접근이 안됨, Base Class에서 private
	string left_brac;
	string right_brac;
	string connector;
public:
	// initialization list는 생성자를 호출할 수 있게 해준다.
	FancyText(string _t, string _lb, string _rb, string _con);
    //override 키워드 사용한 get()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
    string get () override;
    //override 키워드 사용한 append()함수 구현
    void append(string extra_) override;
};

#endif

// fancytext.cpp

#include"FancyText.hpp"

FancyText::FancyText(string _t, string _lb, string _rb, string _con) :
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
    //override 키워드 사용한 get()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
string FancyText::get () { 
        return left_brac + Text::get() + right_brac;
    }
    //override 키워드 사용한 append()함수 구현
void FancyText::append(string extra_){
        Text::append(connector + extra_);
    }

// fixedtext.hpp

#ifndef FIXEDTEXT_H_
#define FIXEDTEXT_H_
#include"Text.hpp"
#include<string>

class FixedText : public Text {
public:
	FixedText();
    void append(string extra_) override;
};

#endif

// fixedtext.cpp

#include"FixedText.hpp"

FixedText::FixedText() : Text::Text("FIXED") {}
void FixedText::append(string extra_) {}

// main.cpp

#include <iostream>
#include <string>
#include"Text.hpp"
#include"FancyText.hpp"
#include"FixedText.hpp"

using namespace std;

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
	// t2 = t1; // Derived <- Base 불가능

	return 0;
}