#include <iostream>
#include <mariadb/conncpp.hpp>

// DELETE문 실행 함수(이름을 이용한)
void deleteTask(std::unique_ptr<sql::Connection> &conn, std::string name) {
    try {
        // PreparedStatement 객체 생성
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("delete from TASKS where name = ?"));
        // 객체에 값을 전달
        stmnt->setString(1, name);
        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error deleting task: " << e.what() << std::endl;
   }
}

// UPDATE문 실행 함수(이름을 이용하여 성별을 바꿈)
void updateTask(std::unique_ptr<sql::Connection> &conn, std::string name, bool gender) {
    try {
        // PreparedStatement 객체 생성
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("update TASKS set gender = ? where name = ?"));
        // 객체에 값을 전달
        stmnt->setBoolean(1, gender);
        stmnt->setString(2, name);
        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error updating task status: " << e.what() << std::endl;
   }
}

// Insert문 실행 함수
// 인자로 값을 넣는다. (id값은 AUTO_INCEREMENT이기 때문에 없어도 상관 없다.)
void addTask(std::unique_ptr<sql::Connection> &conn, std::string name, int age, bool gender) {
    try {
        // PreparedStatement 객체 생성
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("insert into TASKS values (default, ?, ?, ?)"));
        // 객체에 값을 전달
        stmnt->setString(1, name);
        stmnt->setInt(2, age);
        stmnt->setBoolean(3, gender);
        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error inserting new task: " << e.what() << std::endl;
   }
}

// SELECT문 실행 함수
void showTasks(std::unique_ptr<sql::Connection> &conn) {
    try {
        // createStaemet 객체 생성
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
        // 쿼리를 실행
        sql::ResultSet *res = stmnt->executeQuery("select * from TASKS");
        // 반복문을 통해서 내부의 값을 반환
        while (res->next()) {
            std::cout << "id = " << res->getInt(1);
            std::cout << ", name = " << res->getString(2);
            std::cout << ", age = " << res->getInt(3);
            std::cout << ", gender = ";
            if (res->getBoolean(4)) {
                std::cout << "Male" << std::endl;
            } else {
                std::cout << "Female" << std::endl;
            }
                
        }
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error selecting tasks: " << e.what() << std::endl;
   }
}

