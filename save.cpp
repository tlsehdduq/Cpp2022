//-----------------------------------------------------------------------------
// ���޵� �����̸��� �ִ� ���ڸ� �о� "C++ ��������.txt"�� �����Ѵ�.
//
//C++														2022.03.14
//-----------------------------------------------------------------------------
#include<string>
#include<fstream>
#include<chrono>
#include<iomanip>
#include<iostream>

void save(std::string filename)
{
	std::ifstream in{ filename };
	char ch;
	in >> std::noskipws;
	std::ofstream out{ "C++ ��������.txt",std::ios::app };

	time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	out.imbue(std::locale("korean"));

	out << "------------------------------------------------" << std::endl;
	out << "����ð� - " << std::put_time(localtime(&t), "%c %A") << std::endl;

	while (in >> ch) {

		out << ch;
	}
	std::cout << std::endl;
	std::cout << filename << "- �����Ͽ����ϴ�." << std::endl;
}