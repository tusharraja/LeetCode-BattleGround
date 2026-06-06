class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {

        vector<int> l;
        vector<int> r;

        int s=arr[0];

        l.push_back(0);

        int n=arr.size();

        for(int i=1;i<n;i++){
            l.push_back(s);
            s=s+arr[i];
        }

        s=arr[n-1];

        r.push_back(0);

         for(int i=n-2;i>=0;i--){
            r.push_back(s);
            s=s+arr[i];
        }


        vector<int> ans;

        reverse(r.begin(),r.end());

        for(int i=0;i<n;i++){
            
            ans.push_back(abs(l[i]-r[i]));
        }

        return ans;


        
    }
};