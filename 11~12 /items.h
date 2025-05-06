#include <iostream>
#include <string>
using namespace std;

class Item{
    public:
    string name;
    int weight;
    string img_path;

    Item(string name, int weight, string img_path=""){
        this->name = name;
        if(weight>0){
            this->weight = weight;
        }else{
            this->weight=0;
        }
        this->img_path= img_path;
    }

    string get_name(){
        return this->name;
    }

    int get_weight(){
        return this->weight;
    }
    void show_image(){
        // cout << this->img_path <<endl;
        std::cout<<this->img_path<< std::endl;

    }

};

class WearableItem : public Item{
    public:
        short location;
        bool state;

        WearableItem(string name, int weight, short location, 
            string img_path="", 
            bool state=false):Item(name, weight, img_path){
            this->location = location;
            this->state = state;
        }

        string get_name() {
            return "장비: " + this->name;
        }
        short get_location(){
            return this->location;
        }
        bool get_state(){
            return this->state;
        }
    

};


class WeaponItem : public WearableItem {
    public:
        int attack_damage;
        float attack_speed;
    
    /**
     * attack_damage
     * attck_speed
     */
    WeaponItem(int attack_damage=1, float attack_speed=1.0, string img_path="",string name, int weight, short location, bool state=false):
    WearableItem(name,  weight,  location,img_path="", state=false){
        this->attack_damage = attack_damage;
        this->attack_speed = attack_speed;
    }

    /**
     * 데미지와 공격속도를 곱하여 반환하는 함수
     * attack_damage *attck_speed
     */
     int attack()
     {
        return (int)(this->attack_damage * this->attack_speed);
     }
   
};


class MeleeWeapon :public WeaponItem {

};


class RangeWeapon :public WeaponItem {

};