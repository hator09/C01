#include "Zombie.hpp"

int main()
{
    std::cout << "Zombie Horde function:" << std::endl;
    Zombie* horde = zombieHorde(8,"Martin");
    for(int x=0;x < 8;x++)
    {
        horde[x].announce();
    }
    delete[] horde;
    return 0;
}