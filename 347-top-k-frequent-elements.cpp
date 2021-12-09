/*
 * problem: 347
 * difficulty: medium
 * contributor: michael popp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<queue>

std::vector<int> topKFrequent(std::vector<int>& nums, int k){
    std::vector<int> result;
    
    //map: key - unique digit, value - frequency
    std::unordered_map<int, int> freq_map;
    for(auto i: nums){
        freq_map[i]++;
    }
    //p_queue<pair> key - frequency, value - unique digit
    std::priority_queue<std::pair<int,int>> freq_queue;
    for(auto it = freq_map.begin(); it != freq_map.end(); it++){
        freq_queue.push(std::make_pair(it->second, it->first));
    }

    for (int i = 0; i < k; i++){
        result.push_back(freq_queue.top().second);
        freq_queue.pop(); 
    }

    return result;
}

int main(){
    
    std::vector<int> nums = {7,7,7,7,7,7,10,10,10,10,10,10,1,1,1,2,2,3};
    std::vector<int> nums2 = {1};
    auto result = topKFrequent(nums, 3);

    for(auto& i : result){
        std::cout << i << std::endl;
    }

    return 0;
}
