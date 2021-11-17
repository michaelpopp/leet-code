/*
 * Problem: 14
 * Difficulty: easy
 * contributor: michael popp
 */

#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        std::string result;

        return result;
}

int main(int argc, char* argv[]){
        
        //  test case(s)
        std::vector<std::string> strs = {"flower","flow","flight"};
        std::vector<std::string> strs2 = {"dog","racecar","car"};

        std::string result = longestCommonPrefix(strs);

        std::cout << result << std::endl;

        return 0;
}
