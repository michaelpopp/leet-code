/*
 * problem: 53
 * difficulty: easy
 * contributor: michael popp
 */
#include <iostream>
#include <vector>

// time complexity: O(n), memory complexity: O(1)
int maxSubArray(std::vector<int>& nums){
    
    const int SIZE = nums.size();
    
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    // based on kadane's algorithm
    for(int i = 1; i < SIZE; i++){
       
       // option 1: cleaner code, uses slightly more memory
       current_sum = (current_sum + nums[i] > nums[i]) ? current_sum + nums[i] : nums[i];
       if(current_sum > max_sum){max_sum = current_sum;}

       // option 2: more code, uses slightly less memory
       //if(current_sum + nums[i] >= nums[i]){
       //    current_sum += nums[i];
       //    if(current_sum > max_sum){max_sum = current_sum;}
       //} else {
       //    current_sum = nums[i];
       //    if(current_sum > max_sum){max_sum = current_sum;}
       //}

    }

    return max_sum;
}

int main(){
    
    std::vector v = {5,4,-1,7,8};

    std::cout << maxSubArray(v) << "\n";

    return 0;
}
