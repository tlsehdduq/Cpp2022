//-------------------------------------------------------------------------------------------------
//                                                            10주 2일차        
//	
//		class 와 더 친해저보자.			
//		1. Dog
//		2. INT
// 
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include"save.h"

using namespace std;

class INT {
	int num;
public:
	INT() :num{} {};
	INT(int n) : num{ n } {};


	friend ostream& operator<<(ostream& os, const INT& n);
};
ostream& operator<<(ostream& os, const INT& n) {
	os << n.num;
	return os;
}

//[문제] 다음 main()이 문제없이 실행되도록 class

int main()
{
	INT a = 1;
	
	++a;				//a.operator++()
	a++;				//a.operator++( int )

	cout << a << endl;

	
	save("1.cpp");

}
