/*
 * Problem: 3
 * Difficulty: medium
 * contributor: michael popp
 */

#include <iostream>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    int result = 0;
	
    for(int i = 0; i < s.length(); i++) {

	int length = 0;
	std::unordered_map<char, std::string> charMap;

	for(int j = i; j < s.length(); j++) {
	    char lookup = s[j];
	    std::unordered_map<char, std::string>::const_iterator inSubStr = charMap.find(lookup);
	    
	    // checks if charMap contains char
	    if(inSubStr != charMap.end()) {
		    break;
	    } else {
		std::pair<char, std::string> charValue (lookup, "stored");
		charMap.insert(charValue);
                length++;
	    }
	}

	if(length > result){result = length;}

    }

    return result;	
}


int main(int argc, char* argv[]) {

    if(argc > 2) {fprintf(stderr, "USAGE: %s string\n", argv[0]); exit(-1);}
    std::string s;
    (argc == 2) ? s = argv[1] : s = "";
    int result = lengthOfLongestSubstring(s);
    std::cout << result << std::endl;

    return 0;
}
