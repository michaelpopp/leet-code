/*
 * Leetcode problem: 9. Add Two Numbers
 * Difficulty: medium
 * Contributor: michael popp
 * Currently in progress not finished yet
 */ 

#include <iostream>
#include <string>


struct ListNode {
	int val;
	ListNode *next;

	ListNode() { val = 0; next = nullptr; }
	ListNode(int x) { val = x; next = nullptr;}
	ListNode(int x, ListNode *next__) { val = x; next = next__; }

};

int linkListToInt (ListNode* x){
	
	std::string result;
	ListNode* curr = x;

	do {
		result.insert(0, std::to_string(curr->val));
		curr = curr->next;
	} 
	while (curr != nullptr);
	return std::stoi(result);
}

ListNode* intToLinkList (int x){
	
	std::string str_x = std::to_string(x);
	auto index = str_x.length() - 1;
	auto initNode = true;
	
	for (index; index >= 0; index--){

		int val = str_x[index] - '0';

		if(initNode){
			ListNode ln_x {str_x[index] - '0'};
			initNode = false;
			continue;
		}

		//  https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		ListNode ln_x { (str_x[index] - '0'), &ln_x};

		if (index == 0){return &ln_x;}
	}

	return nullptr;

}

ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
	
	auto i_l1 = linkListToInt (l1);
	auto i_l2 = linkListToInt (l2);
	return intToLinkList(i_l1 + i_l2);
}

int main(int argc, char* argv[]) {
	
	ListNode l1 {3};
	ListNode l2 {4, &l1};
	ListNode l3 {2, &l2};

	ListNode l4 {4};
	ListNode l5 {6, &l4};
	ListNode l6 {5, &l5};
	ListNode* l7 = addTwoNumbers(&l3, &l6);
	
	ListNode* curr = l7;
	
	do {
		std::cout << curr->val << std::endl;
		curr = curr->next;
	} 
	while (curr != nullptr);

	return 0;

}
