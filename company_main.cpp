#include "./company.cpp"
#include <string>


int main(){
    Company a_company ;
    // std::string co_name;
    // std::cout<<"회사명을 입력해주세요";
    // std::cin >> co_name ;
    // a_compay.setCompanyName(co_name);

    a_company = createCompanyFromInput();
    a_company.show_company();
    a_company.record_company();
    a_company.read_companys();
}