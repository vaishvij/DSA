class Solution {
public:
    void reverse(vector<int>& nums, int start, int end)
    {
        while (start <= end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) 
    {
        int s = nums.size();
        int r = k%s;
        reverse(nums,0,s-r-1);
        reverse(nums,s-r,s-1);
        reverse(nums,0,s-1);
    }
};