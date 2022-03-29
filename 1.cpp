//-------------------------------------------------------------------------------------------------
//                                                            6주 2일차                    
// class / struct - 사용자 정의 자료형
//	- struct 와 class의 차이
//    struct는 멤버변수를 감추지 않는다.
//	   class는 멤버변수를 감추어 class  바깥에서 멤버변수에 접근하지 못한다.
//    
//		class - 정보 은닉(information hiding) 캡슐화		
// class에서 멤버를 private으로 해야만 하는것을 이해 할 수 있는 예제 - 다음시간
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<thread>
#include"save.h"

using namespace std;
//[[문제] 다음과 같은 기능을 갖는 class Bell을 코딩하라.
//생성지 정수를 인자로 받아 저장한다.
// play 함수를 호출하면 생성시 저장한 정수의 수만큼 벨소리를 연주한다.
// 벨소리와 벨소리 사이의 간격은 1초로 한다.
// 벨소리는 아스키 코드를 사용한다.

class Bell {

	int num{};

public:
	Bell(int n) :num{ n } {}

	void play() {
		for (int i = 0; i < num; i++) {
			cout << '\7';
			this_thread::sleep_for(1s);
		}
	}
};


int main()
{
	cout << '\7' << endl;
	

	Bell a{ 20 };

	a.play();						//벨소리 - 1초 - 벨소리 - 1초 - 벨소리 - 1초

	save("1.cpp");	
}
