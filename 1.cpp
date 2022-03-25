//-------------------------------------------------------------------------------------------------
//                                                            4주 2일차         
//   -----------------------------------------------------------------------------------------------            
// C/C++ - 프로그래머가 메모리를 마음껏 다룰 수 있게 해준다. 
// 
// CODE
// DATA
// STACK
// Free Store(HEAP) - 동적할당
//				키워드 new로 메모리를 요청한다.
//										할당받은 메모리를 사용한다.(read/write)
//				키워드 delete로 메모리를 반환한다.
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<random>
#include"save.h"
using namespace std;

//[문제] 사용자가 입력한 정수만큼 메모리를 확보하라.  (동적할당)
//			 확보한 메모리를 랜덤값으로 채워라 (엔진/분포)
//			 가장 큰 값을 찾아 화면에 출력하라/
//			 이 과정을 사용자가 0이하의 수를 입력할때 까지 반복하라.			(20분)
//

default_random_engine dre;
uniform_int_distribution<int> uie;

int main()
{
		int num{};
		int* p;		
		int maxValue{ 0 };
	while (true)
	{
		
		cout << "정수를 입력하시오. : ";
		cin >> num;
		if (num <= 0)
			break;
	  p = new int[num];

		for (int i = 0; i < num; i++)
		{
			p[i] = uie(dre);
		}
		maxValue = 0;
		for (int i = 0; i < num; ++i)
			if (maxValue < p[i])
				maxValue = p[i];
		cout << maxValue << endl;
		delete[] p;
	}

	save("1.cpp");
}