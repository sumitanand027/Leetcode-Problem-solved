class KthLargest {
public:
    
    priority_queue< int , vector<int> , greater<int> > pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        for( auto x : nums ) {
            pq.push( x );
            if( pq.size() > k )
                pq.pop();
        }    
        kk = k;
    }
    
    int add(int x) {
        pq.push( x );
        if( pq.size() > kk )
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */