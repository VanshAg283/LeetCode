class Solution {
private: 
    void merge(vector<int>& arr, int start, int end, int mid) {
        int left = mid - start + 1;
        int right = end - mid;
        vector<int> leftarr(left);
        vector<int> rightarr(right);
        for (int i = 0; i < left; ++i) {
            leftarr[i] = arr[start + i];
        }
        for (int i = 0; i < right; ++i) {
            rightarr[i] = arr[mid + i + 1];
        }
        int l = 0, r = 0;
        int idx = start;
        while (l < left && r < right) {
            if(leftarr[l] <= rightarr[r]) {
                arr[idx] = leftarr[l];
                l++;
            } else {
                arr[idx] = rightarr[r];
                r++;
            }
            idx++;
        }
        while (l < left) {
            arr[idx] = leftarr[l];
            l++;
            idx++;
        }
        while (r < right) {
            arr[idx] = rightarr[r];
            r++;
            idx++;
        }
    }
    void mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end, mid);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};