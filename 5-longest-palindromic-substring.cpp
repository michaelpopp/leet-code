/*
 * Problem: 5
 * Difficulty: medium
 * Contributor: michael popp
 * Note: based on apoorva dave solution.
 */

#include <iostream>
#include <string>

std::string longestPalindrome(std::string s){

    const int s_len = s.length();

    // initalize table with all elements false
    int start = 0;
    int max_len = 1;
    bool table[s_len][s_len] = {{false}};
    
    // leetcode may not allow initizilation too false
    //for( auto &row : table){
    //    for(auto &col : row){
    //        col = false; 
    //    }

    // all substrings of length 1 are palindromes
    for(int i = 0; i < s_len; i++){
        table[i][i] = true;
    }

    //checks to see if pairs are palindrome (are identical)
    for(int i = 0; i < s_len-1; i++){
        if(s[i] == s[i+1]){
            table[i][i+1] = true;
            max_len = 2;
            start = i;
        }

    }

    // case: for all substrings of length 3 or greater
    // k determines size of sub string
    // i and j are index's of sub string
    for(int k = 3; k <= s_len; k++){
        for(int i = 0; i < s_len - k + 1; i++){
            // 
            int j = i + k - 1;
            // this is where the dynamic programming happens (looks at inner sub-strings bool)
            if(table[i+1][j-1] && s[i] == s[j]){
                table[i][j] = true;
                if(k > max_len){ max_len = k; start = i;}
            }
        }
    }
   return s.substr(start, max_len);


}

int main(int argc, char* argv[]){
    if(argc != 2) {fprintf(stderr, "USAGE: %s string\n", argv[0]); exit(-1);}
    std::string s = argv[1];
    std::cout << longestPalindrome(s) << "\n";
    return 0;
}
