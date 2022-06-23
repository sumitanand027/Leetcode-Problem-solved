class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort( courses.begin() , courses.end() , []( const vector<int> &a , const vector<int> &b ) {
            return a[1] < b[1];
        } );
        
        priority_queue<int> q;
        
        int sum = 0;
        
        for( auto a : courses )
        {
            sum += a[0];
            q.push( a[0] );
            
            if( sum > a[1] ) {
                sum -= q.top();
                q.pop();
            }
        }
        
        return q.size();        
    }
};