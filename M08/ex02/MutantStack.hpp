#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        using container_type            = typename std::stack<T>::container_type;
        using iterator                  = typename container_type::iterator;
        using const_iterator            = typename container_type::const_iterator;
        using reverse_iterator          = typename container_type::reverse_iterator;
        using const_reverse_iterator    = typename container_type::const_reverse_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"
