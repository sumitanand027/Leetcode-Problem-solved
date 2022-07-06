class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort( nums.begin() , nums.end() );
        int closest = nums[0] + nums[1] + nums[2];
        int cur = 0;
        
        for( int first = 0 ; first < nums.size() - 2 ; first++ ) 
        {
            if( first > 0 && nums[first] == nums[first-1] ) continue;
            
            int second = first + 1;
            int third = nums.size() - 1;
            
            while( second < third )
            {
                cur = nums[first] + nums[second] + nums[third];
                
                if( abs( cur - target ) < abs( closest - target ) ) {
                    closest = cur;
                }
                
                if( cur > target ) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return closest;
    }
};