#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon _weapon;

    public:
        HumanA();
        ~HumanA();
        
        void setName(std::string name);
        void setWeapon(Weapon weapon);
        void attack();

};


#endif