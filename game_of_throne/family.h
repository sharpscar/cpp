// family.h
#ifndef FAMILY_H_
#define FAMILY_H_

#include <string>
#include <iostream>

enum character_abilities {
    WISDOM, SWORD, DRAGON, MAGICIAN, SOUL_MANIPULATION
};

class Family {
protected:
    std::string name;
    std::string emblem;
    std::string word;
    std::string castle_name;

public:
    Family();
    Family(const std::string &name, const std::string &emblem,
           const std::string &word, const std::string &castle);

    void speak_house_name();
    void speak_house_word();
    void speak_where_is_their_live();
};

class Character : public Family {
private:
    std::string first_name;
    std::string last_name;
    std::string job;
    character_abilities ca;

public:
    Character(const std::string &f_name, const std::string &l_name,
              const std::string &job, character_abilities ability,
              const std::string &fam_name, const std::string &emblem,
              const std::string &word, const std::string &castle);

    void introduce();
};

#endif


/*
📁 game_of_throne/
├── main.cpp
├── character_info.h     ← 초기화용 struct
├── family.h / .cpp      ← Family 클래스
├── character.h / .cpp   ← Character 클래스 (Family 상속)
├── ability.h            ← 능력 enum 또는 클래스화
├── kingdom.h / .cpp     ← 왕국, 지역 관리 (선택 사항)
├── utils.h / .cpp       ← 공통 유틸 함수


만약 클래스를 구조화 하기 위한 파일구조를 만든다면 이렇게 만든다고하네..


*/