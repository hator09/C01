#include "Zombie.hpp"

int main()
{
    std::cout << "New Zombie function:" << std::endl;
    Zombie* myzombie = newZombie("Martin");
    myzombie->announce();
    delete myzombie;

    std::cout << "Random Chump function:" << std::endl;
    randomChump("Tomas");

    return 0;
}