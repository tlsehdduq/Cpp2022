//-------------------------------------------------------------------------------------------------
//                                                            10�� 2����        
//	
//		class �� �� ģ��������.			
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

//[����] ���� main()�� �������� ����ǵ��� class

int main()
{
	INT a = 1;
	
	++a;				//a.operator++()
	a++;				//a.operator++( int )

	cout << a << endl;

	
	save("1.cpp");

}
