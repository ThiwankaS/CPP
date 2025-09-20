#pragma once

template <typename T>
void print(T& numbers) {
    for(auto it = numbers.begin();it != numbers.end(); it++) {
        std::cout << "element : " << *it << std::endl;
    }
}
