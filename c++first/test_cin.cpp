#include <iostream>

int main()
{
    int sum = 0, value = 0;

    while (std::cin >> value)
    {
        sum += value;
    }

    std::cout<< "Sum is:"<< sum << std::endl;

    unsigned u=10, u2 = 42;
    std::cout << u2 -u << std::endl;

    return 0;
}