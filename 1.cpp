//-------------------------------------------------------------------------------------------------
//                                                            9�� 2����        
// 
//		ǥ��string�� ������ ����� ���� STRING�� ����� 
//		 class ���迡 �ʿ��� �͵��� �н�
//		STRING -  �ڿ��� �����ϴ� class
//		�̵������� - move constructor
//		�̵� �Ҵ� ������ - move operator = 
// 
//		���� ���� Ŭ������ �ڿ��� �Ҵ�޴� �ٸ� (��� �̾߱�� ���⿡�� ����)
//				1. �����ڿ��� �ڿ��� �Ҵ�޴´� ( RAII )
//				2. �Ҹ��ڿ��� �ڿ��� ��ȯ�Ѵ�.
//				3. ���� �����ڿ��� ����� ���� ���縦 �Ѵ�.
//				4. ���� �Ҵ翬���ڸ� ����� ���� ���縦 �Ѵ�.
//				5. �̵������ڸ� ����� ���纸�� ȿ������ ������ �ǵ����Ѵ�.
//				6.�̵��Ҵ翬���ڸ� �������� ������ �Ѵ�.
//				
//-------------------------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<algorithm>
#include"save.h"

using namespace std;

// { ���� ] ���� main()�� �������� ����ǵ��� class String�� �ڵ��� �϶�
// main()�� �����Ǹ� �ȵȴ�.

class STRING {
	size_t num{};			//������ ���ڼ�
	char* p{};			//���ڰ� �ִ� �޸�
public:

	STRING() {
		cout << "����Ʈ ������() - ���� " << num << " , �ּ�: " << (void*)p << endl;
	}

	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];

		memcpy(p, str, num);

		cout << "������(const char*) - ���� " << num << " , �ּ�: " << (void*)p << endl;
	}
	~STRING() {
		cout << "�Ҹ��� ���� " << num << " , �ּ�: " << (void*)p << endl;
		delete[] p;
	}

	STRING(const STRING& other) : num{ other.num } {
		p = new char[num];

		memcpy(p, other.p, num * sizeof(char));
		cout << "���� ������(const STRING&) - ���� " << num << " , �ּ�: " << (void*)p << endl;
	}
	STRING& operator= (const STRING& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "�����Ҵ翬���� - ���� " << num << " , �ּ�: " << (void*)p << endl;

		return *this;
	}
	//�̵� ������
	STRING(STRING&& other) noexcept: num{ other.num },p{ other.p } {
		other.num = 0;
		other.p = nullptr;
		cout << "�̵������� - ���� " << num << " , �ּ�: " << (void*)p << endl;
	}

	//�̵��Ҵ翬����
	STRING& operator=(STRING&& other)noexcept {
		if (this == &other)
			return *this;

		delete[] p;
		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;

		cout << "�̵��Ҵ翬���� - ���� " << num << " , �ּ�: " << (void*)p << endl;
	}

	// ������ �����ε�
	STRING operator+ (const STRING& rhs) const {

		STRING temp;
		temp.num = num + rhs.num;
		temp.p = new char[temp.num];

		memcpy(temp.p, p, num);
		memcpy(temp.p + num, rhs.p, rhs.num);

		return temp;

	}

	size_t size() const {
		return num;
	}

	friend ostream& operator<<(ostream&, const STRING&);
};

// ������Լ��� firend�� ����Ѵ�.
ostream& operator<<(ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; i++) {
		os << s.p[i];
	}
	return os;
}

//�ڿ��� �����ϴ� Ŭ������
//�ڱⰡ �����ϴ� �ڿ��� �̵� ��ų ���� �ִ�.
// �̵��� ���纸�� ȿ������ ������ �� �� �ִ�.

//[����] name�� ���� ������������ ���� �� �� 
// ȭ�鿡 ����϶�.(20��)

int main()
{
	STRING name[5]{ "����","GIT","â","����","������Ʈ" };
	//3�г� ���� , ���Ͽ� ��ϵǾ��ְ� ����..�߰�����غ� 
	
	sort(begin(name), end(name), [](const STRING& a, const STRING& b) {
		return a.size() > b.size();
		});

	for (const STRING& n : name)
		cout << n << endl;

	

	save("1.cpp");
}
