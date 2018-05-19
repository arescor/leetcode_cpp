// defintions and methods for singly linked list.

//I use raw pointers here and do not care memory leak.
//This issue will be addressed in future improvements.

#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *vectorToList(const std::vector<int> &input) {
    ListNode *preHead = new ListNode(0);
    ListNode *prev = preHead;
    for(const auto & value : input) {
        ListNode *cur = new ListNode(value);
        prev->next = cur;
        prev = cur;
    }
    return preHead->next;
}

std::string nodeToString(ListNode *head) {
    std::string res;
    while(head) {
        res += std::to_string(head->val) + "->";
        head = head->next;
    }
    res += "null";
    return res;
}



//for test
