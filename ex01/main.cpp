#include "Span.hpp"

#include <iostream>
#include <vector>

static void testSubjectExample()
{
    std::cout << "===== Subject example =====" << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortest: " << sp.shortestSpan() << " (expected: 2)" << std::endl;
    std::cout << "longest : " << sp.longestSpan() << " (expected: 14)" << std::endl;
}

static void testExceptions()
{
    std::cout << "\n===== Exceptions =====" << std::endl;
    Span sp(1);
    try
    {
        sp.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Not enough numbers: " << e.what() << std::endl;
    }

    sp.addNumber(42);
    try
    {
        sp.addNumber(100);
    }
    catch (const std::exception& e)
    {
        std::cout << "Capacity exceeded: " << e.what() << std::endl;
    }
}

static void testRangeInsertion()
{
    std::cout << "\n===== Range insertion =====" << std::endl;

    std::vector<int> numbers;
    numbers.push_back(-10);
    numbers.push_back(-3);
    numbers.push_back(5);
    numbers.push_back(20);

    Span sp(4);
    sp.addNumbers(numbers.begin(), numbers.end());

    std::cout << "shortest: " << sp.shortestSpan() << " (expected: 7)" << std::endl;
    std::cout << "longest : " << sp.longestSpan() << " (expected: 30)" << std::endl;
}

static void testCopy()
{
    std::cout << "\n===== Copy =====" << std::endl;

    Span original(3);
    original.addNumber(10);
    original.addNumber(20);

    Span copy(original);
    original.addNumber(100);

    std::cout << "original longest: " << original.longestSpan() << " (expected: 90)" << std::endl;
    std::cout << "copy longest    : " << copy.longestSpan() << " (expected: 10)" << std::endl;
}

static void testLargeSpan()
{
    std::cout << "\n===== 10,000 numbers =====" << std::endl;

    const unsigned int size = 10000;
    std::vector<int> numbers;
    numbers.reserve(size);

    for (unsigned int i = 0; i < size; ++i)
        numbers.push_back(static_cast<int>(i * 2));

    Span sp(size);
    sp.addNumbers(numbers.begin(), numbers.end());

    std::cout << "shortest: " << sp.shortestSpan() << " (expected: 2)" << std::endl;
    std::cout << "longest : " << sp.longestSpan() << " (expected: 19998)" << std::endl;
}

int main()
{
    try
    {
        testSubjectExample();
        testExceptions();
        testRangeInsertion();
        testCopy();
        testLargeSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}