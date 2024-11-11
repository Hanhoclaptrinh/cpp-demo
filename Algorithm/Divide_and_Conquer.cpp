/*
	Su dung ky thuat divide and conquer 
	de tinh tong mang con lien tiep trong mot mang
	
	chia mang thanh 2 phan
	Tinh tong con lon nhat cua moi phan
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_left(vector<int>& arr, int left, int mid) {
	int sum = 0;
	int max_sum = arr[mid];
	
	for (int i = mid; i >= left; i--) {
		sum += arr[i];
		max_sum = max(max_sum, sum);
	}
	return max_sum;
}

int max_sum_right(vector<int>& arr, int mid, int right) {
	int sum = 0;
	int max_sum = arr[mid + 1];
	
	for (int i = mid + 1; i <= right; i++) {
		sum += arr[i];
		max_sum = max(max_sum, sum);
	}
	return max_sum;
}

int max_sum_subarray(vector<int>& arr, int left, int right) {
	if (left == right) 
		return arr[left];
		
	int mid = (left + right) / 2;
	
	int max_left = max_sum_subarray(arr, left, mid);
	int max_right = max_sum_subarray(arr, mid + 1, right);
	int max_cross = max_sum_left(arr, left, mid) + max_sum_right(arr, mid, right);
	
	return max({max_left, max_right, max_cross});
}

int main() {
	vector<int> arr = {1, -2, 3, 4, -1, 2, 1, -5, 4};
	cout << "Max_Sum: " << max_sum_subarray(arr, 0, arr.size()) << endl;
	
	return 0;
}
