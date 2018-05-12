#include <vector>
// #include <iostream>
#include "segTree.hpp"

using namespace std;

SegTree::SegTree(const vector<int> &nums) : numSize(nums.size()) {
    if(!nums.empty()) {
        initialTree(numSize-1);
        buildTree(0, 0, numSize-1, nums);
    }
}

void SegTree::initialTree(int sizeMinusOne) {
    int digit=0;
    while(sizeMinusOne!=0) {
        ++digit;
        sizeMinusOne>>=1;
    }
    int maxSize = 1<<(digit+1);
    trees.resize(maxSize);
}

int SegTree::buildTree(int index, int lower, int upper, const vector<int> &nums) {
    if(lower==upper) {
        trees[index] = nums[lower];
    }
    else {
        int mid = lower+(upper-lower)/2;
        int leftSum = buildTree(left(index), lower, mid, nums);
        int rightSum = upper>mid?buildTree(right(index),mid+1, upper, nums):0;
        trees[index] = leftSum+rightSum;
    }
    //cout << lower << " " << upper << " " << index << " " << trees[index] << endl;
    return trees[index];
}

int SegTree::rangeSumHelper(int index, int lower, int upper, int start, int end){
    if(start<=lower && end>=upper)
        return trees[index];
    if(start>upper || end<lower)
        return 0;

    int mid = lower+(upper-lower)/2;
    int leftSum = rangeSumHelper(left(index), lower, mid, start, end);
    int rightSum = 0;
    if(upper>mid) {
        rightSum = rangeSumHelper(right(index), mid+1, upper, start, end);
    }
    // cout << lower << " " << upper << " " << index << " " << leftSum+rightSum << endl;
    return leftSum+rightSum;
}

void SegTree::updateTreeHelper(int index, int lower, int upper, int i, int diff) {
    if(i>upper || i<lower)
        return;

    trees[index] += diff;
    if(upper>lower){
        int mid = lower+(upper-lower)/2;
        if(i<=mid)
            updateTreeHelper(left(index), lower, mid, i, diff);
        else
            updateTreeHelper(right(index), mid+1, upper, i, diff);
    }
}
