/*
 * Problem: 20. 
 * Difficulty: easy
 * Contributor: michael popp
 */

#include <iostream>
#include <stack>
#include <string>

bool isValid (std::string s) {

	std::stack<char> ss;

	//  Validating parentheses
	for (int i = 0; i < s.length(); i++){

		if (s.at(i) == '{' || s.at(i) == '[' || s.at(i) == '('){
			ss.push(s.at(i));
		} else {
			if (ss.empty()) {return false;}
			if (s.at(i) == '}') {
				if (ss.top() != '{') {return false;}
				ss.pop();
			} else if (s.at(i) == ']') {
				if (ss.top() != '[') {return false;}
				ss.pop();
			} else {
				if (ss.top() != '(') {return false;}
				ss.pop();
			}
		}
	}

	bool result = (ss.empty()) ? true : false;
	return result;
}

int main (int argc, char* argv[]){
	//  true test case
	std::string testCase1 = "[{}]";
	//  false test case
	std::string testCase2 = "{{{[][]}}";
	//  false test case
	std::string testCase3 = "]";

	bool test = isValid(testCase1);
	
	//  verifying the test cast on the terminal
	std::cout << test << std::endl;

	return 0;
}
