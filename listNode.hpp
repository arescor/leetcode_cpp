// defintions and methods for singly linked list.

// I use raw pointers here and do not care memory leak.
// This issue will be addressed in future improvements.

#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

// take a vector, convert to a singly linked list, and return the head.
ListNode *vectorToList(const std::vector<int> &input) {
    ListNode *preHead = new ListNode;
    ListNode *prev = preHead;
    for(const auto & value : input) {
        ListNode *cur = new ListNode(value);
        prev->next = cur;
        prev = cur;
    }
    return preHead->next;
}

// take a head of a singly linked and list, and return a string.
// the output has the format of 1->2->3->.....->n
std::string listToString(ListNode *head) {
    std::string res;
    while(head) {
        res += std::to_string(head->val) + "->";
        head = head->next;
    }
    if(!res.empty()) {
        res.pop_back();
        res.pop_back();
    }
    return res;
}

// take a string, convert to a singly linked list, and return the head.
// the input is required to have the same format of the previous function's output.
ListNode* stringToList(const std::string &input) {
    ListNode *preHead = new ListNode;
    ListNode *prev = preHead;
    const std::string delim = "->";
    std::size_t curPos=0;
    while(curPos != input.size()) {
        std::size_t nextPos=input.find(delim, curPos);
        int value = std::stoi(input.substr(curPos, nextPos-curPos));
        ListNode *cur = new ListNode(value);
        prev->next = cur;
        prev = prev->next;
        curPos = nextPos==std::string::npos?input.size():nextPos+delim.size();
    }
    return preHead->next;
}
