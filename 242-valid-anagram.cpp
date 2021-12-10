/*
 * problem: 242
 * difficulty: easy
 * contributor: michael popp
 */
#include <iostream>
#include <string>
#include <unordered_map>

// time complexity, space complexity: O(n), O(1)
bool isAnagram(std::string s, std::string t) {
    
    //key - character, value - frequency
    const int size_s = s.size();
    std::unordered_map<char, int>map;

    if(size_s != t.size()){return false;}

    for(int i = 0; i < size_s; i++){
        map[s[i]]++;
        map[t[i]]--;
    }

    for(auto it= map.begin(); it != map.end(); it++) {
        if(it->second != 0){return false;}
    }
    
    return true;
}

int main(int argc, char* argv[]){

    if(argc != 3){fprintf(stderr, "USAGE: %s string string", argv[0]); exit(-1);}
    
    std::cout << isAnagram(argv[1], argv[2]) << std::endl;

    return 0;
}
