#include <vector>
#include <iostream>
#include "segTree.hpp"

using namespace std;

class NumArray {
private:
    SegTree segmentTree;
public:
    NumArray(vector<int> nums) : segmentTree(nums) {
    }

    void update(int i, int val) {
        segmentTree.updateTree(i, val);
    }

    int sumRange(int i, int j) {
        return segmentTree.rangeSum(i, j);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray test(nums);
    // for(size_t i=0; i<nums.size(); ++i){
    //     for(size_t j=i; j<nums.size(); ++j){
    //         cout << test.sumRange(i,j) << " ";
    //     }
    //     cout << "\n";
    // }
    cout << test.sumRange(0,2) << "\n";
    cout << test.sumRange(0,0) << "\n";
    test.update(1, 2);
    cout << test.sumRange(0,2) << "\n";
}
