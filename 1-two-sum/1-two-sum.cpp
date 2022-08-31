class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        

        
        for( int i = 0 ; i < nums.size() ; i++ ) {
            int test1 = target - nums[i];
            // int test2 = nums[i] - target;
            
            if( m.find( test1 ) != m.end() && m[test1] != i ) {
                return { m[test1] , i };
            }
            // if( m.find( test2 ) != m.end() && m[test2] != i ) {
            //     return { m[test2] , i };
            // }
            m[ nums[i] ] = i;
        }
        
        return { -1, -1 };
    }
};