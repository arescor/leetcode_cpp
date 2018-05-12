#ifndef SEG_TREE
#define SEG_TREE

#include <vector>

using namespace std;

class SegTree {
private:
    vector<int> trees;
    int numSize;

    int left(int index){
        return 2*index+1;
    }

    int right(int index){
        return 2*index+2;
    }

    void initialTree(int sizeMinusOne);
    int buildTree(int index, int lower, int upper, const vector<int>& nums);
    int rangeSumHelper(int index, int lower, int upper, int start, int end);
    void updateTreeHelper(int index, int lower, int upper, int i, int diff);

public:
    SegTree(const vector<int> &nums);
    int rangeSum(int start, int end){
        return rangeSumHelper(0, 0, numSize-1, start, end);
    }
    void updateTree(int i, int val){
        int oldVal = rangeSum(i, i);
        updateTreeHelper(0, 0, numSize-1, i, val-oldVal);
    }
};

#endif
