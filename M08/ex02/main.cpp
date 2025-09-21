#include <iostream>
#include <list>

#include "MutantStack.hpp"
#include "test.hpp"

int main(void) {

    test("test with MutantStack");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    LINE_DATA;
    std::cout << "top : " << mstack.top() << std::endl;
    NEW_LINE;

    mstack.pop();
    LINE_DATA;
    std::cout << "size : " << mstack.size() << std::endl;
    NEW_LINE;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    LINE_DATA;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << "item : " << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    test("test the same with list");
    std::list<int> ls;

    ls.push_back(5);
    ls.push_back(17);
    LINE_DATA;
    std::cout << "top : " << ls.back() << std::endl;
    NEW_LINE;

    ls.pop_back();
    LINE_DATA;
    std::cout << "size : " << ls.size() << std::endl;
    NEW_LINE;

    ls.push_back(3);
    ls.push_back(5);
    ls.push_back(737);
    ls.push_back(0);

    LINE_DATA;
    std::list<int>::iterator it_ls = ls.begin();
    std::list<int>::iterator ite_ls = ls.end();
    ++it_ls;
    --it_ls;

    while (it_ls != ite_ls)
    {
        std::cout << "item : " << *it_ls << std::endl;
        ++it_ls;
    }

    return (EXIT_SUCCESS);
}
