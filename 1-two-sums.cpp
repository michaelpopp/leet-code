/*
 * Problem: 1
 * Difficulty: easy
 * contributor: michael popp
 */
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSumHash(std::vector<int>& nums, int target){

    const int size = nums.size();
    std::unordered_map<int, int> map_nums;
    std::vector<int> result = {-1, -1};

    for(int i = 0; i < size; i++){map_nums[nums[i]] = i;}
    
    for(int i = 0; i < size; i++){
        int diff = target - nums[i];
        auto it = map_nums.find(diff);
        if(it != map_nums.end() && i != it->second){
            result[0] = i;
            result[1] = it->second;
            return result;
        }
    }
    return result;
}
std::vector<int> twoSum(std::vector<int>& nums, int target){

    const int size = nums.size();
    std::vector<int> result = {-1, -1};

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }

    }

    return result;
}

int main(int argc, char* argv[]){

    std::vector<int> nums = {3,2,4};
    const auto result = twoSumHash(nums, 6);

    std::cout<< result[0] << " " << result[1];

    return 0;
}
