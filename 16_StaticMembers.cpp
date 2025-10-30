#include <iostream>
#include <string>
#include <vector>

class Warrior {
    std::string weapon;

    // int money = 0;
    static int money;
    //static std::vector<std::string>> inventory;

    public:
        Warrior() {
            // money += 500;
            Warrior::money += 500;
        }

        void equip(const std::string& weapon, int cost=0) {
            if (cost > Warrior::money) {
                std::cout << "insufficient money" << std::endl;
                return;
            }
            this->weapon = weapon;
            
            // money -= cost;
            Warrior::money -= cost;
        }

        void printWarrior() const {
            std::cout << weapon << " " << money << std::endl;
        }

        static void addMoney(int money) {
            Warrior::money += money;
        }
};

// cannot initialize static member variable value anywhere inside the class
int Warrior::money = 0;

int main() {
    // Static members (variables, functions) are shared by all instances of the class
    // Exist in static/global memory, created at compile time, and is cleared when program ends

    Warrior warrior1;
    Warrior warrior2;
    Warrior warrior3;

    std::vector<Warrior> team {warrior1, warrior2, warrior3};

    for (const Warrior& warrior : team) {
        warrior.printWarrior();
    }

    team[0].equip("sword", 300);
    team[1].equip("sword", 300);
    team[2].equip("spear", 900);

    // Warrior::addMoney(10000);


    for (const Warrior& warrior : team) {
        warrior.printWarrior();
    }
}

