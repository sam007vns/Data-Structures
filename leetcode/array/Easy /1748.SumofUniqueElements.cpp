#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        int arr[101];
        for(int i =0;i<101;i++){
            arr[i] = 0;
        }
        for(int i = 0;i<n;i++){
            arr[nums[i]]++;
        }
        int sum = 0;
        for(int i =0;i<n;i++){
            if(arr[nums[i]] == 1) sum+=nums[i];
        }
        return sum;
    }
};

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, bool> m;
    int res = 0;
    for (auto n : nums) {
        auto it = m.find(n);
        if (it != end(m)) {
            res -= it->second ? 0 : n;
            it->second = true;
        }
        else {
            m.insert({n, false});
            res += n;
        }
    }
    return res;
}