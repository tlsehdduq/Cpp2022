//-------------------------------------------------------------------------------------------------
//                                                            3�� 2����                       
//
//������ ����  - 
//	const�� �ǹ� - �޸𸮸� ���� ���� ������ �� ���� ����. 
// void* - �޸𸮿� �ִ� ������ �ڷ����� �������� �� �� ����Ѵ�.
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

	cout << "���� ������" << endl;

	for (int num : a)
		cout << num << " ";
	cout << endl;
	cout << endl;

	qsort(a, size(a), sizeof(int), [](const void* a, const void* b) {
		return *(int*)a - *(int*)b;
		});
	cout << "�������� ���� �� " << endl;
	cout << endl;

	for (int num : a)
		cout << num << " ";
	cout << endl << endl;
	save("1.cpp");
}
