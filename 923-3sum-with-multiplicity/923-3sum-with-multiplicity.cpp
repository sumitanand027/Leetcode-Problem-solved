class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long> m;
        for( auto &x : arr ) {
            m[ x ]++;
        }
        
        int mod = 1000000007;
        long res = 0;
        
        for( auto &it : m ) {
            for( auto &it2 : m ) {
                int i = it.first , j = it2.first , k = target - i - j ;
                if (!m.count(k)) continue;
                if( i == j && j == k )
                    res += ( m[i] * (m[i] - 1) * (m[i] - 2) ) / 6;
                else if( i == j && j != k ){
                    cout << "YES" << " ";
                    res += ( m[i] * (m[i] - 1) / 2 * m[k]);
                }
                else if( i < j && j < k )
                    res += ( m[i] * m[j] * m[k] );
                res = res % mod;
                cout << m[i] << " " << m[j] << " "<< m[k] << " ";
                cout << res << endl;
            }
        }
        return (int) res;
    }
};