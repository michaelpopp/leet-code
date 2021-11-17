/*
 * Problem: 14
 * Difficulty: easy
 * contributor: michael popp
 */

#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        std::string str1 = strs.front();
        std::string empResult ="";
        int min = str1.length();

        //  case where the vector contains only 1 element
        if (strs.size() == 1) {return str1;}
        
        for(std::vector<std::string>::iterator it = strs.begin() + 1; it < strs.end(); it++){

                int counter = 0;
                std::string str2 = *it;
                
                if (str1[0] != str2[0]) {return empResult;}
                for(int i = 0; i < str2.length(); i++){

                        if(i == str1.length() || str1[i] != str2[i]) {
                                if (counter < min) { min = counter;}
                                break;
                        } 
                        
                        //  case where the smallest prefix is a complete subset of str1
                        if (i == str2.length() - 1){
                                counter++;
                                if (counter < min) {min = counter;}
                                break;
                        }

                        counter++;

                 }
        }

        
        std::string result = str1.substr(0,min); 
        return result;
}

int main(int argc, char* argv[]){
        
        //  test case(s)
        std::vector<std::string> strs = {"flower","flow","flight"};
        std::vector<std::string> strs2 = {"dog","racecar","car"};
        std::vector<std::string> strs3 = {"ab","a"};

        std::string result = longestCommonPrefix(strs3);

        std::cout << result << std::endl;

        return 0;
}
