// family.cpp
#include "./family.h"

// Family class
Family::Family() : name(""), emblem(""), word(""), castle_name("") {}

Family::Family(const std::string &name, const std::string &emblem,
               const std::string &word, const std::string &castle)
    : name(name), emblem(emblem), word(word), castle_name(castle) {}

void Family::speak_house_name() {
    std::cout << "House: " << name << "\n";
}

void Family::speak_house_word() {
    std::cout << "Words: " << word << "\n";
}

void Family::speak_where_is_their_live() {
    std::cout << "Castle: " << castle_name << "\n";
}

// Character class
Character::Character(const std::string &f_name, const std::string &l_name,
                     const std::string &job, character_abilities ability,
                     const std::string &fam_name, const std::string &emblem,
                     const std::string &word, const std::string &castle)
    : Family(fam_name, emblem, word, castle), first_name(f_name),
      last_name(l_name), job(job), ca(ability) {}

void Character::introduce() {
    std::cout << "I am " << first_name << " " << last_name << ", the " << job << ".\n";
    speak_house_name();
    speak_house_word();
    speak_where_is_their_live();
}
