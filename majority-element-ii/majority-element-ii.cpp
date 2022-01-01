class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        int c1 = 0;
        int c2 =0;
        
        for( int i = 0 ; i < nums.size(); i++ ) 
        {
            int val = nums[i];
            if( num1 == val ) {
                c1++;
            } else if( num2 == val ) {
                c2++;
            } else if( c1 == 0 ) {
                num1 = val;
                c1++;
            } else if( c2 == 0 ) {
                num2 = val;
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        
        c1 = 0;
        c2 = 0;
        for( int i = 0; i < nums.size(); i++ ) {
            if( nums[i] == num1 ) c1++;
            if( nums[i] == num2 ) c2++;
        }
        
        vector<int> ans;
        if( c1 > nums.size() / 3 )
            ans.push_back( num1 );
        
        if( c2 > nums.size() / 3 )
            ans.push_back( num2 );
        
        return ans;
    }
};
