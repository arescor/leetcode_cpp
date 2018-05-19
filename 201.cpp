#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=0 && n!=0) {
            if(m==n){
                return m<<count;
            }
            else {
                m >>= 1;
                n >>= 1;
                ++count;
            }
        }
        return 0;
    }
};


int main() {
    Solution sol;
    int m=101, n=45;
    cout << bitset<32>(m) << " " << bitset<32>(n) << endl;
    cout << sol.rangeBitwiseAnd(101, 45) << endl;
}
