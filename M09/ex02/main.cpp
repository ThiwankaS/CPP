#include <iostream>
#include <vector>

#include "sorting.hpp"

using namespace std;

void print(vector<int>& nums){
    for(vector<int>::iterator it = nums.begin(); it != nums.end();it++) {
        cout << "nums [" << distance(begin(nums), it) << "] : " << *it << "\n";
    }
}

int main(void) {
    
    // vector<int> nums = {6, 9, 2, 7, 1, 4, 3, 10, 8, 5};

    // print(nums);
    // binary_insertion_sort(nums);    
    // cout << "\n after :\n";
    // print(nums);
    

    vector source{ 7, 1, 5 };
    vector target{ 1, 2, 3, 4, 5, 6, 8};

    cout << "source : \n";
    print(source);
    cout << "\n target : \n";
    print(target);

    for (auto elem : source)
    {
        auto it = std::lower_bound(begin(target), end(target), elem);
        cout << "it : " << *it << "\n";
        target.insert(it, elem);
    }

    cout << "\n target : \n";
    print(target);

    return (EXIT_SUCCESS);
}
