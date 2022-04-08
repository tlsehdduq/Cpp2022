//-------------------------------------------------------------------------------------------------
//                                                            9주 2일차        
// 
//		표준string과 유사한 기능을 갖는 STRING을 만들며 
//		 class 설계에 필요한 것들을 학습
//		STRING -  자원을 관리하는 class
//		이동생성자 - move constructor
//		이동 할당 연산자 - move operator = 
// 
//		내가 만든 클래스가 자원을 할당받는 다면 (모든 이야기는 여기에서 시작)
//				1. 생성자에서 자원을 할당받는다 ( RAII )
//				2. 소멸자에서 자원을 반환한다.
//				3. 복사 생성자에서 만들어 깊은 복사를 한다.
//				4. 복사 할당연산자를 만들어 깊은 복사를 한다.
//				5. 이동생성자를 만들어 복사보다 효율적인 동작이 되도록한다.
//				6.이동할당연산자를 잊지말고 만들어야 한다.
//				
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<algorithm>
#include"save.h"

using namespace std;

// { 문제 ] 다음 main()이 문제없이 실행되도록 class String을 코딩을 하라
// main()이 수정되면 안된다.

class STRING {
	size_t num{};			//저장한 글자수
	char* p{};			//글자가 있는 메모리
public:

	STRING() {
		cout << "디폴트 생성자() - 갯수 " << num << " , 주소: " << (void*)p << endl;
	}

	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];

		memcpy(p, str, num);

		cout << "생성자(const char*) - 갯수 " << num << " , 주소: " << (void*)p << endl;
	}
	~STRING() {
		cout << "소멸자 갯수 " << num << " , 주소: " << (void*)p << endl;
		delete[] p;
	}

	STRING(const STRING& other) : num{ other.num } {
		p = new char[num];

		memcpy(p, other.p, num * sizeof(char));
		cout << "복사 생성자(const STRING&) - 갯수 " << num << " , 주소: " << (void*)p << endl;
	}
	STRING& operator= (const STRING& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "복사할당연산자 - 갯수 " << num << " , 주소: " << (void*)p << endl;

		return *this;
	}
	//이동 생성자
	STRING(STRING&& other) noexcept: num{ other.num },p{ other.p } {
		other.num = 0;
		other.p = nullptr;
		cout << "이동생성자 - 갯수 " << num << " , 주소: " << (void*)p << endl;
	}

	//이동할당연산자
	STRING& operator=(STRING&& other)noexcept {
		if (this == &other)
			return *this;

		delete[] p;
		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;

		cout << "이동할당연산자 - 갯수 " << num << " , 주소: " << (void*)p << endl;
	}

	// 연산자 오버로딩
	STRING operator+ (const STRING& rhs) const {

		STRING temp;
		temp.num = num + rhs.num;
		temp.p = new char[temp.num];

		memcpy(temp.p, p, num);
		memcpy(temp.p + num, rhs.p, rhs.num);

		return temp;

	}

	size_t size() const {
		return num;
	}

	friend ostream& operator<<(ostream&, const STRING&);
};

// 입출력함수는 firend로 사용한다.
ostream& operator<<(ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; i++) {
		os << s.p[i];
	}
	return os;
}

//자원을 관리하는 클래스는
//자기가 관리하는 자원을 이동 시킬 수도 있다.
// 이동은 복사보다 효율적인 동작이 될 수 있다.

//[문제] name을 길이 내림차순으로 정렬 한 후 
// 화면에 출력하라.(20분)

int main()
{
	STRING name[5]{ "파일","GIT","창","도움말","프로젝트" };
	//3학년 기출 , 파일에 기록되어있고 정렬..중간고사준비 
	
	sort(begin(name), end(name), [](const STRING& a, const STRING& b) {
		return a.size() > b.size();
		});

	for (const STRING& n : name)
		cout << n << endl;

	

	save("1.cpp");
}
