#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== Basic stack test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "elements: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "=== Iterator modification test ===" << std::endl;

    it = mstack.begin();
    *it = 42;

    std::cout << "first element: " << *mstack.begin() << std::endl;

    std::cout << "=== Const iterator test ===" << std::endl;

    const MutantStack<int> constStack(mstack);

    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();

    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    std::cout << "=== Copy test ===" << std::endl;

    MutantStack<int> copied(mstack);
    copied.push(100);

    std::cout << "original size: " << mstack.size() << std::endl;
    std::cout << "copied size: " << copied.size() << std::endl;

    std::cout << "=== Assignment test ===" << std::endl;

    MutantStack<int> assigned;
    assigned = mstack;

    std::cout << "assigned top: " << assigned.top() << std::endl;

    std::cout << "=== List container test ===" << std::endl;

    MutantStack<int, std::list<int> > listMstack;

    listMstack.push(12);
    listMstack.push(24);
    listMstack.push(36);

    std::cout << "top: " << listMstack.top() << std::endl;
    std::cout << "size: " << listMstack.size() << std::endl;

    std::cout << "elements: ";

    MutantStack<int, std::list<int> >::iterator listIt
        = listMstack.begin();

    MutantStack<int, std::list<int> >::iterator listIte
        = listMstack.end();

    while (listIt != listIte)
    {
        std::cout << *listIt << " ";
        ++listIt;
    }

    std::cout << std::endl;

    std::cout << "=== List iterator modification test ===" << std::endl;

    listIt = listMstack.begin();
    *listIt = 100;

    std::cout << "first element: "
              << *listMstack.begin()
              << std::endl;

    std::cout << "=== List const iterator test ===" << std::endl;

    const MutantStack<int, std::list<int> > constListMstack(listMstack);

    MutantStack<int, std::list<int> >::const_iterator listCit = constListMstack.begin();

    MutantStack<int, std::list<int> >::const_iterator listCite = constListMstack.end();

    while (listCit != listCite)
    {
        std::cout << *listCit << " ";
        ++listCit;
    }

    std::cout << std::endl;

    std::cout << "=== List copy test ===" << std::endl;

    MutantStack<int, std::list<int> > listCopied(listMstack);
    listCopied.push(48);

    std::cout << "original size: " << listMstack.size() << std::endl;
    std::cout << "copied size: " << listCopied.size() << std::endl;

    std::cout << "=== List assignment test ===" << std::endl;

    MutantStack<int, std::list<int> > listAssigned;
    listAssigned = listMstack;

    std::cout << "assigned top: " << listAssigned.top() << std::endl;

    std::cout << "=== Conversion to std::stack with list ===" << std::endl;

    std::stack<int, std::list<int> > normalListStack(listMstack);

    std::cout << "top: " << normalListStack.top() << std::endl;
    std::cout << "size: " << normalListStack.size() << std::endl;

    return 0;
}