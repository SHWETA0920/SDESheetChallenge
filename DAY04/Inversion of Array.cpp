class Solution {
public:
    long long merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long inv = 0;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
                inv += (mid - left + 1); 
            }
        }

        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }

        return inv;
    }

    long long mergeSort(vector<int>& nums, int low, int high){
        if(low >= high) return 0;

        int mid = (low + high) / 2;
        long long inv = 0;

        inv += mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid + 1, high);
        inv += merge(nums, low, mid, high);

        return inv;
    }

    long long int numberOfInversions(vector<int> nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
