//-----------------------------------------------------------------------------
// 전달된 파일이름에 있는 글자를 읽어 "C++ 강의저장.txt"에 저장한다.
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
	std::ofstream out{ "C++ 강의저장.txt",std::ios::app };

	time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	out.imbue(std::locale("korean"));

	out << "------------------------------------------------" << std::endl;
	out << "저장시간 - " << std::put_time(localtime(&t), "%c %A") << std::endl;

	while (in >> ch) {

		out << ch;
	}
	std::cout << std::endl;
	std::cout << filename << "- 저장하였습니다." << std::endl;
}