/*
 * Leetcode problem: 9. Add Two Numbers
 * Difficulty: medium
 * Contributor: michael popp
 * Note: This is a c++ solution of the default solutioin
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

ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {

	ListNode* dummyHead = new ListNode;
	ListNode* p = l1;
	ListNode* q = l2;
	ListNode* curr = dummyHead;

	int carry = 0;
	while (p != nullptr || q != nullptr) {
		auto x = (p != nullptr) ? p-> val : 0;
		auto y = (q != nullptr) ? q-> val : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		curr->next = new ListNode {sum % 10};
		curr = curr->next;
		if (p != nullptr) { p = p->next; }
		if (q != nullptr) { q = q->next; }
	}
	//  if carry exist for most significant digit add one more mode
	if (carry > 0) { curr->next = new ListNode(carry); }

	//  preparing results & freeing dynamically allocated memory
	curr = dummyHead->next;
	delete dummyHead;

	return curr;
}

int main(int argc, char* argv[]) {
	//  linked-list 1
	ListNode l1 {3};
	ListNode l2 {4, &l1};
	ListNode l3 {2, &l2};
	
	//  linked-list 2
	ListNode l4 {4};
	ListNode l5 {6, &l4};
	ListNode l6 {5, &l5};
	ListNode* l7 = addTwoNumbers(&l3, &l6);
	
	//  printing result to console for verification
	while (l7 != nullptr) {	std::cout << l7->val << std::endl; l7 = l7->next;}

	return 0;

}
