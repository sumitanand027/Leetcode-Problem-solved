class Solution {

    int count = 0;
    void merge( vector<int> &nums , int l, int mid, int h )
    {
        
        int i = l;
        int j = mid + 1;
        
        while( i <= mid && j <= h )
        {
            if( (long) nums[i] > (long) 2 * nums[j] ) {
                count += ( mid - i + 1 );
                j++;
            } else {
                i++;
            }
        }
                
        sort(nums.begin() + l, nums.begin() + h + 1);      
    }
    
    void mergeSort( vector<int> &nums, int l, int h ) 
    {
        if( l == h ) return ;
        
        int mid = ( l + h ) / 2;
        mergeSort( nums , l, mid );
        mergeSort( nums, mid + 1, h );
        
        merge( nums, l, mid, h );
    }
    public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        count = 0;       
        mergeSort( nums , 0 , nums.size() - 1 );
        return count;
    }
};