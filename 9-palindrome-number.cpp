/* 
 * Problem: Leetcode: 9. Palindrome Number
 * Difficulty: easy
 * Contributor: michael popp
 */

#include <iostream>
#include <string>

bool isPalindrome(int x){
	
	if (x < 0){ return false; }

	auto str_x = std::to_string(x);
	auto size = str_x.length();
	auto max_index = size - 1;

	for(auto i = 0; i < size; i++){ 
	
		if(i == max_index - i){ return true; } 
		if(str_x[i] != str_x[max_index - i]){ return false; } 

	}

	return true;

}

int main(int argc, char* argv[]) {

	if (argc != 2){fprintf(stderr, "USAGE: %s number\n", argv[0]); exit(-1);}
	auto num = atol(argv[1]);
	auto result = isPalindrome(num);

	std::cout << result << "\n";

	return 0;


}
