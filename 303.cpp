#include <vector>
#include <iostream>

using namespace std;

class NumArray {
private:
    vector<int> sums;

public:
    NumArray(vector<int> nums) {
        sums.resize(nums.size()+1, 0);
        for(size_t i=1; i<sums.size(); ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray test(nums);

    cout << test.sumRange(0,2) << " " << test.sumRange(2,5) << " "
        << test.sumRange(0,5) << "\n";
    return 0;
}
