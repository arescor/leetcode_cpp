#include <string>
#include <iostream>
#include "listNode.hpp"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    Solution sol;
    string input = "1->2->3->4->5";
    ListNode *oldHead = stringToList(input);
    ListNode *newHead = sol.reverseList(oldHead);
    cout << listToString(newHead) << endl;
}
