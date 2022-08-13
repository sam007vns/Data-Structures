class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) return (nums[0] == target) ? 0 : -1;
        int l = 0, h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] < target) l = mid+1;
            else if(nums[mid] > target) h = mid-1;
            else return mid;
        }
        return -1;
    }
};