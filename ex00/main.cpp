#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void testContainer(T &container, int value)
{
    try
    {
        typename T::iterator it = easyfind(container, value);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    std::vector<int> vectorNumbers;
    vectorNumbers.push_back(10);
    vectorNumbers.push_back(20);
    vectorNumbers.push_back(30);
    vectorNumbers.push_back(20);

    std::list<int> listNumbers;
    listNumbers.push_back(1);
    listNumbers.push_back(2);
    listNumbers.push_back(3);

    std::deque<int> dequeNumbers;
    dequeNumbers.push_back(100);
    dequeNumbers.push_back(200);
    dequeNumbers.push_back(300);

    std::cout << "Vector test:" << std::endl;
    testContainer(vectorNumbers, 20);
    testContainer(vectorNumbers, 99);

    std::cout << "\nList test:" << std::endl;
    testContainer(listNumbers, 3);
    testContainer(listNumbers, 10);

    std::cout << "\nDeque test:" << std::endl;
    testContainer(dequeNumbers, 100);
    testContainer(dequeNumbers, 999);

    return 0;
}