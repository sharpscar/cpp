/**
 * 회사정보 등록 시스템 (잡코리아 같은)

    회사명
    회사주소
    회사전화번호

    회사가 만드는것
    직원수
    연봉

    등록하는 함수
    보여주는 함수
    파일에 입력하는 함수
    파일에 있는것을 가져오는 함수

 */

 #include <string>

 class Company{
    private:
        std::string co_name;
        std::string co_address;

        std::string co_phone;
        std::string co_make_what;
        std::string co_memo;

        int employee_count;
        int salary;

    public:
        // 생성자
        Company(
            const std::string &co_name,
            const std::string &co_address,
            const std::string &co_phone,
            const std::string &co_make_what,
            const std::string &co_memo,
            int employee_count,
            int salary
        );
        Company();
        ~Company(); //파괴자
        void show_company();    //등록한 회사정보를 단순히 출력하는 함수
        void record_company();  //특정 파일에 회사정보를 추가하는 함수 매개변수로 클래스한개를 받음
        void read_companys();   //파일에 기록된 회사 정보들을 불러오는 함수 
        void input();
        //세터
        void setCompanyName(const std::string& name);
        //게터
        std::string getCompanyName()const;
        Company createCompanyFromInput();
 };