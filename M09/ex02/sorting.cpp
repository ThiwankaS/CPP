#include "sorting.hpp"

void insertion_sort(vector<int>& nums) {
    for(vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++) {
        for(vector<int>::iterator mit = it; mit != nums.begin();mit--) {
            if(*mit < *(mit - 1)) {
                swap(*(mit - 1), *mit);
            }
        }
    }
}

void binary_insertion_sort(vector<int>& nums) {
    for(vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++) {
        if(*it < *(it - 1)) {
            auto index = lower_bound(begin(nums), end(nums), *it);
            nums.insert(index, *it);    
        }
    }
}

