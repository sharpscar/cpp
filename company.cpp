#include <iostream>
#include "./company.h"
#include <fstream>
#include <string>

Company::Company(
    const std::string &co_name,
    const std::string &co_address,
    const std::string &co_phone,
    const std::string &co_make_what,
    const std::string &co_memo,
    int employee_count,
    int salary
){
    this->co_name = co_name;
    this->co_address = co_address;
    this->co_phone = co_phone;
    this->co_make_what = co_make_what;
    this->co_memo = co_memo;
    this->employee_count = employee_count;
    this->salary = salary;

} 

Company::~Company(){

}

Company::Company(){
    this->co_name = "";
    this->co_address = "";
    this->co_phone = "";
    this->co_make_what = "";
    this->co_memo = "";
    this->employee_count = 0;
    this->salary = 0;
}

void Company::show_company(){
    std::cout << "회사명 : " << this->co_name;
    std::cout << "회사주소 : " << this->co_address;
    std::cout << "회사 전화번호 : " << this->co_phone;
    std::cout << "회사 만드는것? : " << this->co_make_what;
    std::cout << "회사원 총원 : " << this->employee_count;
    std::cout << "지급 연봉 : " << this->salary;
    std::cout << "회사 기타정보 : " << this->co_memo;

}

void Company::record_company(){
    std::ofstream writeFile("company.txt", std::ios::app);
    if(!writeFile.is_open()){
        std::cerr <<"파일을 열수 없습니다."<<std::endl;
        return ;
    }

    writeFile <<"\n"; //기존 내용과 구분을 위한 한칸띄기
    
    writeFile <<"회사명 :" <<this->co_name << "\n";
    writeFile <<"회사주소 :" <<this->co_address << "\n";
    writeFile <<"회사 전화번호  :" <<this->co_phone << "\n";
    writeFile <<"회사 만드는것? :" <<this->co_make_what << "\n";
    writeFile <<"회사원 총원  :" <<this->employee_count << "\n";
    writeFile <<"지급 연봉 :" <<this->salary << "\n";
    writeFile <<"회사 기타정보 :" <<this->co_memo << "\n";

    writeFile.close();
    
}

void Company::read_companys(){
    std::ifstream readFile("company.txt");

    if(!readFile.is_open()){
        std::cerr<<"파일을 열수 없습니다."<<std::endl;
        return;
    }
    std::string str;
    while(std::getline(readFile, str)){
        std::cout <<str <<std::endl;
    }
    readFile.close();
}


// 회사정보 한방에 입력받기
void Company::input() {
    std::cout << "회사명을 입력해주세요: ";
    std::getline(std::cin, this->co_name);

    std::cout << "주소: ";
    std::getline(std::cin, this->co_address);

    std::cout << "전화번호: ";
    std::getline(std::cin, this->co_phone);

    std::cout << "만드는 것: ";
    std::getline(std::cin, this->co_make_what);

    std::cout << "기타 정보: ";
    std::getline(std::cin, this->co_memo);

    std::cout << "직원 수: ";
    std::cin >> this->employee_count;

    std::cout << "연봉: ";
    std::cin >> this->salary;
}

// set, get method 로 입력받기
void Company::setCompanyName(const std::string& name) {
    this->co_name = name;
}

std::string Company::getCompanyName() const {
    return this->co_name;
}

/** 입력을 받아서 회사 정보 객체를 반환하는 함수  */
Company createCompanyFromInput() {
    std::string name, address, phone, make_what, memo;
    int employee_count, salary;

    std::cout << "회사명을 입력하세요: ";
    std::getline(std::cin, name);
    std::cout << "주소: ";
    std::getline(std::cin, address);
    std::cout << "전화번호: ";
    std::getline(std::cin, phone);
    std::cout << "무엇을 만드는지: ";
    std::getline(std::cin, make_what);
    std::cout << "기타 정보: ";
    std::getline(std::cin, memo);
    std::cout << "직원 수: ";
    std::cin >> employee_count;
    std::cout << "연봉: ";
    std::cin >> salary;
    std::cin.ignore(); // 개행문자 제거

    return Company(name, address, phone, make_what, memo, employee_count, salary);
}