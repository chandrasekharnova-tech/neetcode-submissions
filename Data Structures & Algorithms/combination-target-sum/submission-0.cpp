class Solution {
public:

    vector<int> subset;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int index, int target)
    {
        if(target < 0)
        {
            return;
        }

        if(target==0)
        {
            res.push_back(subset);
            return;
        }

        if(index == nums.size())
        {
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index, target-nums[index]);

        subset.pop_back();
        dfs(nums, index+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        dfs(nums, 0, target);
        return res;
    }
};
