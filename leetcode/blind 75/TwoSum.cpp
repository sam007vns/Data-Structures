class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        for(int x=0;x<nums.size()-1;x++){
            for(int y=1;y<nums.size();y++){
                if(x==y){
                    continue;
                }
                if(nums[x]+nums[y] == target){
                    sol.push_back(x);
                    sol.push_back(y);
                    return sol;
                }
            }
        }
        return sol;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};