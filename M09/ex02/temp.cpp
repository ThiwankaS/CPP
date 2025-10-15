#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void print(string str, vector<int>& nums){
    cout << str << "("
         << nums.size()
         << ") <";
    for(auto it = nums.begin(); it != nums.end();it++) {
        cout << *it << ",";
    }
    cout << "> \n";
}

void setHeads(vector<int>& nums, vector<vector<int>::iterator>& heads) {
    for(auto it = nums.begin() + 1; it < nums.end(); it += 2){
        heads.push_back(it);
    }
}

void rearrange(vector<int>& nums) {
    for(auto it = nums.begin() + 1; it < nums.end(); it+= 2){
        if(*(it-1) > (*it)){
            swap(*(it-1), *it);
        }
    }
}

void swap_numbers(vector<int>& nums, auto it1, auto it2, int size) {
    vector<int>temp((it1 - (size - 1)), (it1 + 1));
    nums.erase((it1 - (size - 1)), (it1 + 1));
    nums.insert((it2 - (size - 1)), temp.begin(), temp.end());
    print("temp", temp);
}

void sort_pairs(
    vector<int>& nums,
    vector<vector<int>::iterator>heads,
    vector<int>main,
    vector<int>pend
) {
    int i;
    for(i = 2; nums.begin() + i < nums.end(); i *= 2){
        for(auto key = heads.begin() + (i - 1); key < heads.end(); key+= i) {
            if(**(key - (i/2)) > **(key)) {
                swap_numbers(nums, *(key - (i/2)), *key, i);
            }
        }
        heads.clear();
        setHeads(nums, heads);
    }
    for(;(i > 2); i /= 2){

    }
}

void setMain(vector<int>& nums, vector<int>& main, int size) {
    main.insert(main.begin(), nums.begin(), nums.begin() + size + 1);
    for(auto it = nums.begin();it < nums.end();it += size) {
    }
}

void setPend(vector<int>& nums, vector<int>& pend) {
    for(auto key = nums.begin() + 2; key < nums.end();key += 2){
        pend.push_back(*key);
    }
}

int main(void) {
    vector<int> nums = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
    //vector<int> nums = {37,12,46,29,15,23,48,32,19,41,27,44,11,35,26,17,50,39,24,13,31,47,20,28,42,16,25,30,45,14,33,18,40,22,43};
    vector<vector<int>::iterator>heads;
    vector<int>main;
    vector<int>pend;
    print("nums", nums);
    rearrange(nums);
    print("nums", nums);
    setHeads(nums, heads);
    // for(auto it = heads.begin(); it != heads.end(); it++){
    //     cout << "value : " << **it << "\n";
    // }
    sort_pairs(nums, heads, main, pend);
    print("nums", nums);
    print("Main", main);
    print("pend", pend);
    return (EXIT_SUCCESS);
}

