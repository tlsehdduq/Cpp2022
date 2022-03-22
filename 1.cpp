//-------------------------------------------------------------------------------------------------
//                                                            3주 2일차                       
//
//공부할 내용  - 
//	const의 의미 - 메모리를 읽을 수는 있지만 쓸 수는 없다. 
// void* - 메모리에 있는 원소의 자료형이 무엇인지 모를 때 사용한다.
// 
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
#include<random>
#include"save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution<int>uid{1, 1000};

int main()
{	
	int a[1000];
	for (int& num : a)
		num = uid(dre);

	cout << "원래 데이터" << endl;

	for (int num : a)
		cout << num << " ";
	cout << endl;
	cout << endl;

	qsort(a, size(a), sizeof(int), [](const void* a, const void* b) {
		return *(int*)a - *(int*)b;
		});
	cout << "오름차순 정렬 후 " << endl;
	cout << endl;

	for (int num : a)
		cout << num << " ";
	cout << endl << endl;
	save("1.cpp");
}
