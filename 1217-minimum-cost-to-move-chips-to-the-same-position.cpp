/*
 * Problem: 1217
 * Difficulty: easy
 * contributor: michael popp
 */
#include <iostream>
#include <vector>

int minCostToMoveChips(std::vector<int>& position){

    int oddTotal = 0;
    int evenTotal = 0;

    for(auto const& p : position){
       (p % 2 == 0) ? evenTotal++ : oddTotal++; 
    }

    return (oddTotal > evenTotal) ? evenTotal : oddTotal;
}

int main(int argc, char* argv[]){
    
    std::vector<int> position = {2,2,2,3,3};

    int result = minCostToMoveChips(position);

    std::cout << result << std::endl;

    return 0;
}
