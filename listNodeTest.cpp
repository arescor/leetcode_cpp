#include <string>
#include <vector>
#include <iostream>
#include "listNode.hpp"

int main() {
    std::vector<int> input; //= {1, 2, 4, 5, 63, 4, 1112, 5};
    ListNode *head = vectorToList(input);
    std::string output = listToString(head);
    std::cout << output << std::endl;
    head = stringToList(output);
    output = listToString(head);
    std::cout << output << std::endl;
    return 0;
}
