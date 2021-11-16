/*
 * Problem: 20. 
 * Difficulty: easy
 * Contributor: michael popp
 */

#include <iostream>
#include <stack>
#include <string>

bool isValid (std::string s) {

	//  Validating parentheses
	std::stack<char> ss;
	
	for (int i = 0; i < s.length(); i++){
		char debug = s.at(i);

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
	std::string testCase2 = "{{{[][]}}";
	std::string testCase3 = "]";
	bool test = isValid(testCase3);

	std::cout << test << std::endl;

	return 0;
}
