class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bots) {
        
//         unordered_map<int,int> mt , mb ;
//         int n = tops.size();
        
//         for( int i = 0 ; i < n ; i++ )
//         {
//             if( tops[i] == bots[i] ) 
//             {
//                 mt[]
//             }
//             else
//             {
                
//             }
//         }
        
        int ans = INT_MAX;
        int n = tops.size();
        
        for( int i = 1 ; i <= 6 ; i++ )
        {
            int flag = 1;
            int cnt = 0;
            
            for( int j = 0 ; j < n ; j++ )
            {
                if ( tops[j] != i && bots[j] != i )
                {
                    flag = 0;
                }
                
                if( tops[j] != i ) cnt++;
            }
            
            if( flag )
            {
                ans = min( ans , cnt );
            }
            
        }
        
        for( int i = 1 ; i <= 6 ; i++ )
        {
            int flag = 1;
            int cnt = 0;
            
            for( int j = 0 ; j < n ; j++ )
            {
                if ( bots[j] != i && tops[j] != i )
                {
                    flag = 0;
                }
                
                if( bots[j] != i ) cnt++;
            }
            
            if( flag )
            {
                ans = min( ans , cnt );
            }
            
        }
        
        if( ans == INT_MAX ) ans = -1;
        return ans;
    }
};





