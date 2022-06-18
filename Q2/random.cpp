#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand((unsigned)time(0));
    int randomNumber1, randomNumber2;
    std::cout << 10000 << std::endl;
    for (int index = 0; index < 10000; index++)
    {
        randomNumber1 = (rand() % 100000);
        randomNumber2 = (rand() % 100000);
        std::cout << randomNumber1 << " " << randomNumber2 << std::endl;
    }
}