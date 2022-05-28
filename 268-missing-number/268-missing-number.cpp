class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        
        for( auto &a : nums ) {
            sum += a;
        }
        
        int n = nums.size();
        
        int xSum = (n * ( n + 1 )) / 2;
        
        return xSum - sum;        
    }
};