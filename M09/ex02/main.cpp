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

    vector<int> nums = {6, 9, 2, 7, 1, 4, 3, 10, 8, 5};
    int lenght = nums.size() - 1;
    cout << "before : \n";
    print(nums);
    merge_sort(nums, lenght);
    cout << "\n after : \n";
    print(nums);
    return (EXIT_SUCCESS);
}

