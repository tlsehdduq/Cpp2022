//-------------------------------------------------------------------------------------------------
//                                                            4�� 2����         
//   -----------------------------------------------------------------------------------------------            
// C/C++ - ���α׷��Ӱ� �޸𸮸� ������ �ٷ� �� �ְ� ���ش�. 
// 
// CODE
// DATA
// STACK
// Free Store(HEAP) - �����Ҵ�
//				Ű���� new�� �޸𸮸� ��û�Ѵ�.
//										�Ҵ���� �޸𸮸� ����Ѵ�.(read/write)
//				Ű���� delete�� �޸𸮸� ��ȯ�Ѵ�.
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<random>
#include"save.h"
using namespace std;

//[����] ����ڰ� �Է��� ������ŭ �޸𸮸� Ȯ���϶�.  (�����Ҵ�)
//			 Ȯ���� �޸𸮸� ���������� ä���� (����/����)
//			 ���� ū ���� ã�� ȭ�鿡 ����϶�/
//			 �� ������ ����ڰ� 0������ ���� �Է��Ҷ� ���� �ݺ��϶�.			(20��)
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
		
		cout << "������ �Է��Ͻÿ�. : ";
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