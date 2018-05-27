// 92. Reverse Linked List II
// Reverse a linked list from position m to n. Do it in one-pass.
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

#include <string>
#include <iostream>
#include "listNode.hpp"

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;

        ListNode *start = nullptr, *preStart = nullptr;
        ListNode *prev = nullptr, *cur = preHead;

        int count = 0;
        while(count<=n) {
            if(count==m-1){
                start = cur->next;
                preStart = cur;
                cur = cur->next;
            }
            else if(count>=m){
                ListNode *next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            else{
                cur = cur->next;
            }
            ++count;
        }
        preStart->next = prev;
        start->next = cur;
        return preHead->next;
    }
};

int main() {
    Solution sol;
    string input = "1->2->3->4->5";
    ListNode *oldHead = stringToList(input);
    ListNode *newHead = sol.reverseBetween(oldHead, 2, 2);
    cout << listToString(newHead) << endl;
    return 0;
}
