//-------------------------------------------------------------------------------------------------
//                                                            3�� 2����                       
//
//������ ����  - 
// C++�� �ڷḦ ��� �����ϴ°�?
// *, & - �������� ���
// �Լ���?
// 
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
#include"save.h"
using namespace std;
int f(const void*, const void*); //void ������ �𸣰ڴ� �ǹ�

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
	//������������ �����Ͻÿ�.:
	//���� - �� �ڵ�� STL�ð��� ������ ������ ��������.
	// 
	//qsort �Լ��� �޸𸮸� �����ϴµ� �ſ� ���� �Լ��̴�. �ð����� �˾Ƶ���.
	//qsort �Լ��� ��ڷ�� �����ϴ� �����Լ��̴�.

	qsort(a, size(a), sizeof(int), f);			//[]�� ���� ���� 
	
	for (int n : a)
		cout << n << " ";
	cout << endl;

	save("1.cpp");
}
