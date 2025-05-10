class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> hash(n+1,0);
        for(int i=0; i<n; i++)
        {
            hash[nums[i]] = 1;
        }
        int number=0;
        for(int i=0; i<n; i++)
        {
            if(hash[i] != 1)
            {
                return number;
                break;
            }
            number++;
        }
        return number;
    }
};