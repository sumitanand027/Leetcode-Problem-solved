class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        if( n2.size() < n1.size() ) return findMedianSortedArrays( n2 , n1 );
        int s1 = n1.size();
        int s2 = n2.size();
        
        int low = 0 , high = s1; // IMP
        // num of elements taking in the section
        // so range is 0 to s1
        
        while( low <= high ) {
            int cut1 = ( low + high ) >> 1;
            int cut2 = ( s1 + s2 + 1 ) / 2 - cut1;
            
            int left1 = ( cut1 == 0 ) ? INT_MIN : n1[cut1-1];
            int left2 = ( cut2 == 0 ) ? INT_MIN : n2[cut2-1];
            int right1 = ( cut1 == s1 ) ? INT_MAX : n1[cut1];
            int right2 = ( cut2 == s2 ) ? INT_MAX : n2[cut2];
            
            if( left1 <= right2 && left2 <= right1 ) {
                if( (s1 + s2) % 2 == 0 )
                    return ( max(left1 , left2 ) + min(right1 , right2 ) ) / 2.0;
                else
                    return max( left1 , left2 );
            } else if( left1 > right2 ) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};