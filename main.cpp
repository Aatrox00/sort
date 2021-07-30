#include <bits/stdc++.h>
using namespace std;

//bubble sort ----------------------------------------------------------------------

void bubble_sort(vector<int> nums) {
    int n = nums.size();
    bool swaped = false;
    for(int i = 0; i < n-1; ++i) {
        swaped = false;
        for(int j = 0; j < n-1-i; ++j) {
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                swaped = true;
            }
        }
        if(!swaped) break; 
    }
    cout << "bubble sort: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

//end of bubble sort-----------------------------------------------------------

//qsort------------------------------------------------------------------------

int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[r];
    int i = l-1;
    for(int j = l; j < r; ++j) {
        if(nums[j] <= pivot) {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i+1;
}

void qsort_(vector<int>& nums, int l, int r) {
    if(l < r){
        int pivot = partition(nums, l, r);
        qsort_(nums,l, pivot-1);
        qsort_(nums, pivot+1, r);
    }
}

void qsort(vector<int> nums){
    qsort_(nums, 0, nums.size()-1);
    cout << "quick  sort: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}


//end of qsort----------------------------------------------------------------------

//merge sort------------------------------------------------------------------------


void merge(vector<int>& nums, int l, int mid, int r) {
    // left sub l--->mid, lens = mid - l + 1
    // right sub mid + 1--->r, lens = r - (mid+1) + 1 = r - mid
    vector<int> left_sub(nums.begin()+l, nums.begin() + mid  + 1);
    //right_sub len = r - mid
    vector<int> right_sub(nums.begin() + mid + 1, nums.begin()+r+1);
    int n2 = left_sub.size(), n3 = right_sub.size();
    int idx1 = l, idx2 = 0, idx3 = 0;
    while(idx2 < n2 and idx3 < n3) {
        if(left_sub[idx2] < right_sub[idx3]) {
            nums[idx1] = left_sub[idx2++];
        }else{
            nums[idx1] = right_sub[idx3++];
        }
        idx1++;
    }
    while(idx2 < n2) nums[idx1++] = left_sub[idx2++];
    while(idx3 < n3) nums[idx1++] = right_sub[idx3++];
}

void merge_sort_(vector<int>& nums, int l, int r) {
    if(l < r){
        int mid = (l+r) / 2;
        merge_sort_(nums, l, mid);
        merge_sort_(nums, mid+1, r);
        merge(nums,l, mid, r);
    }
}


void merge_sort(vector<int> nums) {
    merge_sort_(nums, 0, nums.size()-1);
    cout << "merge  sort: ";
    for(int num : nums) {
        cout << num  << " ";
    }
    cout << endl;
}

//end of merge sort-----------------------------------------------------------------


//heap sort-------------------------------------------------------------------------

void heapify(vector<int>& nums, int i, int sz) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < sz and nums[l] > nums[largest])
        largest = l;
    if(r < sz and nums[r] > nums[largest])
        largest = r;

    if(largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, largest, sz);
    }
}

void heap_sort_(vector<int>& nums, int sz) {
    for(int i = sz / 2 - 1; i >= 0; --i){
        heapify(nums, i, sz);
    }
    for(int i = sz - 1; i >= 1; --i) {
        swap(nums[0], nums[i]);
        heapify(nums,0, i);
    }
}

void heap_sort(vector<int> nums) {
    heap_sort_(nums, nums.size());
    cout << "heap   sort: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

//end of heap sort------------------------------------------------------------------

int main() {
    vector<int> nums{10,21,1,-1,-321,3213123,2,0,-1,321,321,20};
    bubble_sort(nums);
    qsort(nums);
    merge_sort(nums);
    heap_sort(nums);
    return 0;
}