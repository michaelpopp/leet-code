/*
 * problem: 11
 * difficulty: medium
 * contributor: michael popp
 */
#include <iostream>
#include <vector>

// note: this solution uses the two pointer/iterator pattern (i/j)
// time complexity, memory complexity: O(n), O(1)
int maxArea(std::vector<int>& height){

    int i = 0;
    int j = height.size() - 1;
    int curr_area = 0;
    int max_area = 0;

    while (i < j){
        if(height[i] < height[j]){
             curr_area = height[i]*(j - i);
             max_area = (curr_area > max_area) ? curr_area : max_area;
             i++;
        }else{
             curr_area = height[j]*(j - i);
             max_area = (curr_area > max_area) ? curr_area : max_area;
             j--;
        }
    }

    return max_area;
}

int main(){
    std::vector v = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(v) << "\n";
    return 0;
}
