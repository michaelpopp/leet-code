/*
 * Problem: 27
 * Difficulty: easy
 * contributor: michael popp
 */

#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val){
    
    if(nums.empty()){return 0;}

    for (auto i = nums.begin(); i != nums.end(); i++){
        if(*i == val){
            nums.erase(i); 
            i--;
            continue;
        }
    }

    return nums.size();
}


int main(int argc, char *argv[]){

    std::vector<int> testCase = {0,1,2,2,3,0,4,2};
    int val = 2;
    auto result = removeElement(testCase, val);

    std::cout << result << ": ";
    for (const auto& i : testCase){std::cout << i;}
    std:: cout << std::endl;

    return 0;
}
