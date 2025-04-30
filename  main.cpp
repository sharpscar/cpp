#include "./items.h"

int main(){

    // Item infinity_edge= Item("무한의 대검", 100,"./img/sword.jpg");

    // std::cout << infinity_edge.get_name() << endl;
    // // (string name, int weight, short location, string img_path="", bool state=false):Item(name, weight, img_path){
    // WearableItem Chain_mail = WearableItem("사슬갑옷", 500,5,"./img/Chain_mail.jpg",true);

    // WearableItem leather_mail = WearableItem("가죽갑옷", 200,5,"./img/leather_mail.jpg",true);

    // std::cout << Chain_mail.get_name() << endl;




    // (int attack_damage=1, float attack_speed=1.0,name,  weight,  location,img_path="", state=false)
    // int attack_damage=1, float attack_speed=1.0,string name, int weight, short location, string img_path="", bool state=false
    WeaponItem weapon1 = WeaponItem(10,1.0,"sword", 5, 5,"./img/sword.jpg",false);
    // weapon1.img_path="./img/sword.jpg";
    // weapon1.name = "sword";
    // weapon1.weight = 5;
    // weapon1.location =5;
    // weapon1.state = false;
    std::cout << weapon1.attack() << endl;

    // WeaponItem weapon2 = WeaponItem(15,0.8);
    // weapon1.img_path="./img/sword.jpg";
    // weapon1.name = "bow";
    // weapon1.weight = 5;
    // weapon1.location =5;
    // weapon1.state = false;
    // std::cout << sword.attack() << endl;



    return 0;
}