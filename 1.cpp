//-------------------------------------------------------------------------------------------------
//                                                            9�� 1����        
// 
//		string�� ���� ����� ���� STRING�� ����� class ���迡 �ʿ��� �͵��� �н�
// 
// 
//		class�� �������(�⺻ private)�� �����Ϸ��� �Լ��� �̿��Ѵ�. 
//		���� �������� getter
//		���� ������ setter �� ����Ѵ�.
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include"save.h"

using namespace std;

// { ���� ] ���� main()�� �������� ����ǵ��� class String�� �ڵ��� �϶�
// main()�� �����Ǹ� �ȵȴ�.

class STRING {
	size_t num;			//������ ���ڼ�
	char* p;			//���ڰ� �ִ� �޸�
public:
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];

		memcpy(p, str, num);

		cout << "������(const char*) - ���� " << num << " , �ּ�: " << (void*)p << endl;
	}
	~STRING() {
		cout << "�Ҹ��� ���� " << num << " , �ּ�: " << (void*)p << endl;
		delete[] p;
	}
	STRING(const STRING& other) : num{other.num } {
		p = new char[num];

		memcpy(p, other.p, num * sizeof(char));

	}
	STRING& operator= (const STRING& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "�Ҵ翬���� - ���� " << num << " , �ּ�: " << (void*)p << endl;

		return *this;
	}

	//Ŭ������ �ٱ� ������ �����ϱ� ���� �Լ���
	void show() {
		for (int i = 0; i < num; i++) {
			cout << p[i];
		}
		cout << endl;
	}

	//���� ���� �˷��ִ� getter  ���� �б⸸ �ϱ� ������ class�� �������� �ʴ�.
	// �ٸ� ���� �ϸ� ��������� ���� ���� ���� ���ٴ� ��
	// �� ��Ȳ�� ���� ��Ȯ�ϰ� �� �Լ��� �̿뿡�� �˸� �� �ִٸ� ���ڴ�.
	// =>��� �Լ��� ������ const�� �ٿ� �� �Լ��� ����ϴ��� ��������� ���� ������
	//������ �����Ѵ�.
	size_t size() const {
		return num;
	}
};

int main()
{
	string s1{ "�ȳ��ϼ���." };

	cout << s1;		//�ܹ���(syntatic sugar) 
	cout.operator<<()
	save("1.cpp");
}
