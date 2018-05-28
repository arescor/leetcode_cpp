// defintions and methods for binary tree node.

// I use raw pointers here and do not care memory leak.
// This issue will be addressed in future improvements.

#include <string>
#include <queue>
#include <stdexcept>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// take the root of a tree, and return the string representation.
std::string treeToString(TreeNode *root) {
    std::queue<TreeNode*> nodeQueue;
    std::string res;
    nodeQueue.push(root);
    while(!nodeQueue.empty()) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        if(!node) {
            res += "n,";
        }
        else {
            res += std::to_string(node->val) + ",";
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        }
    }
    res.pop_back();
    return res;
}

TreeNode* stringToTreeHelper(const std::string &input, std::size_t &pos) {
    if (pos==std::string::npos)
        throw std::invalid_argument("reached the end of the input string before tree building completes.");

    const std::string delim = ",";
    size_t newPos=input.find(delim,pos);
    const std::string res = input.substr(pos, newPos-pos);
    pos = newPos==std::string::npos?newPos:newPos+1;
    if(res=="n")
        return nullptr;
    else
        return new TreeNode(stoi(res));
}

TreeNode* stringToTree(const std::string &input) {
    std::size_t pos=0;
    TreeNode *root = stringToTreeHelper(input, pos);
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        if(node) {
            TreeNode *leftNode = stringToTreeHelper(input, pos);
            TreeNode *rightNode = stringToTreeHelper(input, pos);
            node->left = leftNode;
            node->right = rightNode;
            nodeQueue.push(leftNode);
            nodeQueue.push(rightNode);
        }
    }
    if(pos!=std::string::npos)
        throw std::invalid_argument("does not reach the end of the input string when tree building completes.");
    return root;
}
