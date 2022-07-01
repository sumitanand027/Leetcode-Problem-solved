class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort( boxTypes.begin() , boxTypes.end() , [] ( const vector<int> &a , const vector<int> &b ) {
            if( a[1] > b[1] )
                return 1;
            return 0;
        } );
        
        int ans = 0;
        for( auto &a : boxTypes ) {
            if( a[0] < truckSize ) {
                ans += ( a[1] * a[0] );
                truckSize -= a[0];
            } else {
                ans += ( a[1] * truckSize );
                break;
            }
        }
            
        return ans;
    }
};