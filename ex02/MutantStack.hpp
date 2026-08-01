#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &source) : std::stack<T>(source) {}
    virtual ~MutantStack() {}
    MutantStack &operator=(const MutantStack &source) {
        if (this != &source)
            std::stack<T>::operator=(source);
        return *this;
    }


};


#endif