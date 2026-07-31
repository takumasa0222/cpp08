#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span(unsigned int maxSize) : _maxSize(maxSize), _numbers(){}

Span::Span(const Span& src) : _maxSize(src._maxSize), _numbers(src._numbers){}

Span& Span::operator=(const Span& src)
{
    if (this != &src)
    {
        _maxSize = src._maxSize;
        _numbers = src._numbers;
    }

    return *this;
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::length_error("Span is full");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate a span");
    std::vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    unsigned int shortest;

    for (std::vector<int>::size_type i = 1; i < sortedNumbers.size(); ++i)
    {
        unsigned int current = static_cast<unsigned int>(sortedNumbers[i]) - static_cast<unsigned int>(sortedNumbers[i - 1]);
        if (current < shortest || i == 1)
            shortest = current;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate a span");

    int minimum = *std::min_element(_numbers.begin(), _numbers.end());
    int maximum = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(maximum) - static_cast<unsigned int>(minimum);
}