class Solution {
public:

    int findSum(int num){
        //O(log10(num))
        int sum=0;
        while(num>0){
            int lastDig=num%10;
            num=num/10;
            sum=sum+ lastDig;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {

        int answerSum=9*6;
        int answer=-1;
        for(auto num:nums){
            //O(nums.size())
            int sum=findSum(num); //O(log10(num))
            if(sum<answerSum){
                answerSum=sum;
                answer=num;
            }
        }
        return answerSum;
        
    }
};