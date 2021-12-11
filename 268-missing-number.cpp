#include <iostream>
#include <vector>
#include <queue>

int missingNumber(std::vector<int>& nums){

    std::priority_queue<int> nums_q {std::less<int>(), nums};
    for(int i = nums.size(); i >= 0; i--){
        if(nums_q.top() != i || nums_q.empty()){ return i;}
        nums_q.pop();
    }
    return -1;
}

int main(){
    std::vector<int>test = {9,6,4,2,3,5,7,0,1};
    std::cout << missingNumber(test) << std::endl;

    return 0;
}
