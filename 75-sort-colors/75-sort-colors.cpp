class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int z = 0 , o = 0 , t = n - 1;
        
        int i = 0;
        
        while( o <= t && i < n )
        {
            if( nums[i] == 0 ) {
                swap( nums[z] , nums[i] );
                z++;
                o++;
                i++;
            } else if( nums[i] == 1 ) {
                swap( nums[o] , nums[i] );
                o++;
                i++;
            } else {
                swap( nums[t--] , nums[i]);
            }
        }
        
        
    }
};