class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        
        while( l < h ) {
            int mid = ( l + h ) / 2;
            if( nums[mid] < target )l = mid + 1;
            else h = mid;
        }
        
        if( h == -1 || nums[h] != target )
            return {-1 ,-1 };
        vector<int> res(2);
        res[0] = h;
        
        h = nums.size() - 1;
        while( l < h ) {
            int mid = ( l + h )/ 2 + 1;
            if( nums[mid] > target ) h = mid - 1;
            else l = mid;
        }
        res[1] = l;
        return res;
    }
};