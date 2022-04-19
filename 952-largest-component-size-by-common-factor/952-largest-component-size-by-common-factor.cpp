class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find( int x ) {
        if( parent[x] == x ) return x;
        return parent[x] = find( parent[x] );
    }
    
    int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a); }
    
    void uni( int x , int y ) {
        x = find( x );
        y = find( y );
        
        if( rank[x] < rank[y] ) {
            parent[x] = y;
        } else if( rank[y] < rank[x] ) {
            parent[y] = x;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        
        for( int i = 0 ; i < 100005; i++ ) {
            parent.push_back( i );
            rank.push_back( i );
        }
        
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            for(int k=2;k<=sqrt(nums[i]);k++)
            {
                if(nums[i] %k == 0)
                {
                    uni(nums[i],k);
                    uni(nums[i],nums[i]/k);
                }
            }
        }
        
        unordered_map<int,int> mp;
        
        for( int i = 0 ; i < nums.size() ; i++ ) {
            mp[ find(nums[i]) ]++;
        }
        
        int ans = 0;
        for( auto &x : mp ) {
            ans = max( ans , x.second );
        }
        return ans;
    }
};