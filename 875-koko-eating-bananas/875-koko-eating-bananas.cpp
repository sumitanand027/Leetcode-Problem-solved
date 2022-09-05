class Solution {
public:
    
    int check( vector<int> &piles, int k ) {
        int ans = 0;
        
        for( auto &p : piles ){
            ans += ( p + k - 1 ) / k ;
        }
        
        return ans;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, high = 0;
        int ans = INT_MAX;
        
        for( auto &p : piles ) {
            high = max( high , p );
        }
        
        while( l < high )
        {
            int m = ( high - l )/2 + l;
            
            int newH = check( piles, m );     
            
            if( newH > h ) 
                l = m + 1;
            else
                high = m;               
        }
        
        return l;
    }
};