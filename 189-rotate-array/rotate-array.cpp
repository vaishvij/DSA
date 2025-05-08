class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> extra;
        int s = nums.size();
        int r = k%s;
        int point = s-r;
        for(int i=point; i<s; i++)
        {
            extra.push_back(nums[i]);
        }
        for(int i=0; i<point; i++)
        {
            extra.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0; i<extra.size(); i++)
        {
            nums.push_back(extra[i]);
        }
    }
};