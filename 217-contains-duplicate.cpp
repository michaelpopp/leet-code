#include <iostream>
#include <vector>
#include <unordered_map>

bool containsDuplicate(std::vector<int>& nums){

    std::unordered_map<int,int> count;

    for(auto x : nums){
        count[x]++;
        if(count[x] > 1){ return true; }
    }

    return false;
}

int main(){

    std::vector<int> nums = {1,2,3,1};
    std::cout << containsDuplicate(nums) << std::endl;
    return 0;
}
