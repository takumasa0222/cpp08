#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
public:
    Span(unsigned int maxSize);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &src);
    void addNumber(int num);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    template <typename T>
    void addNumbers(T first, T last);

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

};

template <typename T>
void Span::addNumbers(T first, T last)
{
    std::vector<int> values(first, last);

    std::vector<int>::size_type remaining = static_cast<std::vector<int>::size_type>(_maxSize) - _numbers.size();

    if (values.size() > remaining)
        throw std::length_error("Span capacity exceeded");
    _numbers.insert(_numbers.end(), values.begin(), values.end());
}
#endif