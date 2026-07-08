class Solution {
public:
    int PosSum(vector<int> &nums, long long sum){
        int arr = 1;
        int split = 0;
        for(int i = 0; i < nums.size(); i++){
            if(split + nums[i] <= sum){
                split += nums[i];
            }
            else{
                arr++;
                split = nums[i];
            }
        }
        return arr;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(),nums.end());
        long long high = 0;
        for(int i = 0; i < nums.size(); i++) high += nums[i];
        long long sum = low;
        if(k > nums.size()) return -1;
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            int posArr = PosSum(nums, mid);
            if(posArr <= k){
                sum = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return sum;
        
    }
};