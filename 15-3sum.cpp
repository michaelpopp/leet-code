/*
 * problem: 15
 * difficulty: medium
 * contributor: michael popp
 */
#include <iostream>
#include <vector>
#include <algorithm>

// time complexity, space complexity: O(n), O(1)
std::vector<std::vector<int>> threeSum(std::vector<int>& nums){

    const int SIZE = nums.size();
    std::vector<std::vector<int>> result;

    std::sort(nums.begin(), nums.end());
    
    for(int i = 0; i < SIZE - 2; i++){

        // condition prevents duplication
        if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
            int l = i + 1;
            int r = SIZE - 1;
            int sum = 0 - nums[i];
            std::vector<int>temp;

            // find two sum using double pointer/iterator pattern
            while(l < r){
                if(nums[l] + nums[r] > sum){r--;continue;}
                else if(nums[l] + nums[r] < sum){l++;continue;}

                temp.push_back(nums[i]);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                result.push_back(temp);
                temp.clear();
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
                l++;
                r--;
            }
        }
    }
    return result;
}

int main(){

    std::vector nums = {1, -1, -1, 0};

    auto result = threeSum(nums);

    for(auto vector : result){
        for(auto x : vector){
            std::cout << x << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
