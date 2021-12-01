#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){

    ListNode* head;
    ListNode* curr;
    ListNode* p = list1;
    ListNode* q = list2;
    
    // Testing for atleast 1 empty linked list
    if (list1 == nullptr || list2 == nullptr){
        (list1 == nullptr) ? head = list2 : head = list1;
        return head;
    }
    // Determines Head of list
    (p->val > q->val) ? head = q : head = p;
    (p->val > q->val) ?  q = q->next : p = p->next;
    curr = head;

    while(p != nullptr || q != nullptr){
        
        // end cases first
        if (p == nullptr || q == nullptr){
            (p == nullptr) ? curr->next = q : curr->next = p;
            return head;
        }
        
        
        // determing next node
        (p->val > q->val) ? curr->next = q : curr->next = p;
        (p->val > q->val) ?  q = q->next : p = p->next;
        curr = curr->next;
    }

    return head;
}

int main(int argc, char* argv[]){
    ListNode l1 {4};
	ListNode l2 {2, &l1};
	ListNode l3 {1, &l2};
	
	//  linked-list 2
	ListNode l4 {4};
	ListNode l5 {3, &l4};
	ListNode l6 {1, &l5};
	ListNode* l7 = mergeTwoLists(&l3, &l6);
	
	//  printing result to console for verification
	while (l7 != nullptr) {	std::cout << l7->val << std::endl; l7 = l7->next;}
    return 0;
}
