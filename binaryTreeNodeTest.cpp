#include <iostream>
#include <string>
#include "binaryTreeNode.hpp"

int main() {
    std::string input = "4,2,7,1,n,n,9,n,n,n,n";
    TreeNode *root = stringToTree(input);
    std::string output = treeToString(root);
    std::cout << output << std::endl;
}
