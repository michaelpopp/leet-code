/*
 * problem: 19
 * difficulty: medium
 * contributor: michael popp
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
   
    if(head->next == nullptr) {return nullptr;}

    int count = 0;
    ListNode* front = head;
    ListNode* rear = head;
    
    //get node count
    while(front != nullptr){
        front = front->next;
        count++;
    }

    front = head->next;
    // nth node from front of list
    int n2 = count - n + 1;
    
    // delete front-node
    if(n2 == 1){
        head = head->next;
        return head;
    }

    for(int i = 1; i < n2; i++){
        if(i == n2 - 1){
            rear->next = front->next;
        }
        rear = rear->next;
        front = front->next;
    }

    return head;
}

int main(){

//  linked-list 1
	ListNode l1 {5};
	ListNode l2 {4, &l1};
	ListNode l3 {3, &l2};
	ListNode l4 {2, &l3};
	ListNode l5 {1, &l4};
	
    ListNode* l7 = removeNthFromEnd(&l5, 2);
	
	//  printing result to console for verification
	while (l7 != nullptr) {	std::cout << l7->val << std::endl; l7 = l7->next;}
}
