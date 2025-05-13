class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,int> freq;
        
        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }

        int cond = n/2;
        int maj = INT_MIN;
        for(auto it:freq)
        {
            if(it.second > n/2)
            {
                maj = max(maj,it.first);
            }
        }
        return maj;
    }
};