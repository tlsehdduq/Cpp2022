//-------------------------------------------------------------------------------------------------
//                                                            3주 2일차                       
//
//공부할 내용  - 
// C++은 자료를 어떻게 정렬하는가?
// *, & - 원격조작 기능
// 함수란?
// 
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
#include"save.h"
using namespace std;
int f(const void*, const void*); //void 형식을 모르겠단 의미

int f(const void* a, const void* b) //const        
{
	int* p = (int*)a;
	int* q = (int*)b;

	if (*p < *q)
		return -1;

	else if (*p > *q)
		return 1;

	return 0;
}

int main()
{	
	int a[]{ 3,1,2};
	//오름차순으로 정렬하시오.:
	//주의 - 이 코드는 STL시간에 배울것임 지금은 감상만하자.
	// 
	//qsort 함수는 메모리를 이해하는데 매우 좋은 함수이다. 시간내서 알아두자.
	//qsort 함수는 어떤자료든 정렬하는 만능함수이다.

	qsort(a, size(a), sizeof(int), f);			//[]만 정렬 가능 
	
	for (int n : a)
		cout << n << " ";
	cout << endl;

	save("1.cpp");
}
