class Solution {
public:

long long solve(vector<int> &s1,vector<int>& d1,vector<int>& s2,vector<int>& d2){
     int n = s1.size();
        int m = s2.size();
  
      vector<long long> f1;
     for (int i = 0; i < n; ++i) {
            f1.push_back((long long)s1[i] + d1[i]);
        }
    sort(f1.begin(), f1.end());
    vector<pair<int, int>> p2;
     for (int i = 0; i < m; ++i) {
         p2.push_back( {s2[i] , d2[i]} );
        }
    sort(p2.begin(), p2.end());
    
    
    vector<long long> suf(m);
    suf[m - 1] = (long long)p2[m - 1].first + p2[m - 1].second;
     for (int i = m - 2; i >= 0; --i) {
         suf[i] = min(suf[i + 1], (long long)p2[i].first + p2[i].second);
     }
    long long res = LLONG_MAX;
    long long pre = LLONG_MAX;

    int j=0;
    for(auto x:f1){
        while(j<m and p2[j].first <=x){
             pre = min(pre, (long long)p2[j].second);
            j++;
        }
         long long c1 = LLONG_MAX;
          if (pre != LLONG_MAX) {
                c1 = x
                    + pre;
            }
        long long c2 = LLONG_MAX;
          if (j<m) {
               // c1 = t1 + pre;
              c2=suf[j];
            }
         res = min(res, min(c1, c2));
        
    }
    return res;
    
    
}    
int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
     long long res1 = solve(ls, ld, ws, wd);
     long long res2 = solve( ws,wd,ls,ld);
    return min(res1,res2);
      
        
    }
};