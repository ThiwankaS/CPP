#include "sorting.hpp"

void selection_sort(vector<int>& nums){
    for(long unsigned int i = 0; i < nums.size();i++) {
        vector<int>::iterator it = nums.begin() + i;
        auto result = minmax_element(begin(nums) + i, end(nums));
        swap(*it, *result.first);
    }
}

void bubble_sort(vector<int>& nums){
    for(long unsigned int i = 0; i < nums.size();i++) {
        for(long unsigned int j = 1; j < nums.size() - i;j++){
            if(nums[j] < nums[j - 1]){
                swap(nums[j], nums[j - 1]);
            }
        }
    }
}

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
            int value = *it;
            auto index = lower_bound(begin(nums), it, value);
            rotate(index, it, it + 1);
        }
    }
}

static void merge_sorted(vector<int>& nums, int left, int middle, int right) {
    vector <int> temp_left(
        nums.begin() + left,
        nums.begin() + middle + 1
    );
    vector <int> temp_right(
        nums.begin() + middle + 1,
        nums.begin() + right + 1
    );
    vector <int> buffer;
    buffer.reserve(right - left + 1);
    merge(
        temp_left.begin(),
        temp_left.end(),
        temp_right.begin(),
        temp_right.end(),
        back_inserter(buffer)
    );
    copy(buffer.begin(), buffer.end(), nums.begin() + left);
}

static void merge_sort_recursion(vector<int>& nums, int left, int right) {
    if(left >= right) {
        return ;
    }

    int middle = left + (right - left)/2;
    merge_sort_recursion(nums, left, middle);
    merge_sort_recursion(nums, middle + 1, right);
    merge_sorted(nums, left, middle, right);
}

void merge_sort(vector<int>& nums, int lenght) {
    merge_sort_recursion(nums, 0, lenght);
}
