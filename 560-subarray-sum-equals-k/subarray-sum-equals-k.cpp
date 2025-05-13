class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int count=0, sum=0;
        map<int,int> sub;
        sub[0] = 1;

        for(int i=0; i<n; i++)
        {
            sum = sum+nums[i];

            if(sub.find(sum-k) != sub.end())
            {
                count = count+sub[sum-k];
            }
            sub[sum]++;
        }
        return count;
    }
};