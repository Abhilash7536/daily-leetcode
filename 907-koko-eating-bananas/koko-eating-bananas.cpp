#include<algorithm>
class Solution {
public:

    long long countHrs(vector<int> &piles, int k){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += (piles[i] + k - 1) / k ;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int k = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long hours = countHrs(piles, mid);
            if(hours <= h){
                k = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return k;
    }
};