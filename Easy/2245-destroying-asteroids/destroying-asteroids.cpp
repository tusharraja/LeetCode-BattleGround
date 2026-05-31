class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {

        multiset<long long> st;
        for(auto x:arr){
            st.insert(x);
        }

        long long curmass=mass;
        
        //   23
        while(st.size()){
            //auto ptr= upper_bound(st.begin(),st.end(),curmass);
            auto ptr= st.upper_bound(curmass);
            
            // int index= ptr-st.begin();

            if(ptr==st.begin()){
                return false;
            }
            //index--;



            ptr--;

            // if(index==-1 and mass<*st.begin()){
            //     return false;
            // }

            // mass=mass+ *(ptr-1);  //22

         curmass=curmass+ *(ptr);    //22

            st.erase(ptr);


        }

        return true;



    }
};