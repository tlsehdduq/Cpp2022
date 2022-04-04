//-------------------------------------------------------------------------------------------------
//                                                            9주 1일차        
// 
//		string과 같은 기능을 갖는 STRING을 만들며 class 설계에 필요한 것들을 학습
// 
// 
//		class의 멤버변수(기본 private)에 접근하려면 함수를 이용한다. 
//		값을 읽을때는 getter
//		값을 쓸때는 setter 를 사용한다.
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include"save.h"

using namespace std;

// { 문제 ] 다음 main()이 문제없이 실행되도록 class String을 코딩을 하라
// main()이 수정되면 안된다.

class STRING {
	size_t num;			//저장한 글자수
	char* p;			//글자가 있는 메모리
public:
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];

		memcpy(p, str, num);

		cout << "생성자(const char*) - 갯수 " << num << " , 주소: " << (void*)p << endl;
	}
	~STRING() {
		cout << "소멸자 갯수 " << num << " , 주소: " << (void*)p << endl;
		delete[] p;
	}
	STRING(const STRING& other) : num{other.num } {
		p = new char[num];

		memcpy(p, other.p, num * sizeof(char));

	}
	STRING& operator= (const STRING& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "할당연산자 - 갯수 " << num << " , 주소: " << (void*)p << endl;

		return *this;
	}

	//클래스와 바깥 세상이 소통하기 위한 함수들
	void show() {
		for (int i = 0; i < num; i++) {
			cout << p[i];
		}
		cout << endl;
	}

	//글자 수를 알려주는 getter  값을 읽기만 하기 떄문에 class에 위험하지 않다.
	// 다른 말로 하면 멤버변수의 값이 변할 수가 없다는 것
	// 이 상황을 더욱 명확하게 이 함수의 이용에게 알릴 수 있다면 좋겠다.
	// =>멤버 함수에 한정사 const를 붙여 이 함수를 사용하더라도 멤버변수의 값이 변하지
	//않음을 보증한다.
	size_t size() const {
		return num;
	}
};

int main()
{
	string s1{ "안녕하세요." };

	cout << s1;		//꿀문법(syntatic sugar) 
	cout.operator<<()
	save("1.cpp");
}
