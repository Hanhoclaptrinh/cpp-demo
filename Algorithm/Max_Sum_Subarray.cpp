/*
	Tinh tong con lon lien tiep lon nhat trong mang
	Thuat toan: Kadane's Algorithm
	Do phuc tap: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_subarray(vector<int>& arr, int n) {
	if (n < 1) 
		return 0; // mang khong co phan tu nao
		
	int max_sum = arr[0];
	int current_sum = arr[0];
	
	for (int i = 1; i < n; i++) {
		current_sum = max(arr[i], current_sum + arr[i]); // tinh tong con lon nhat bang cach them phan tu hien tai
		
		max_sum = max(max_sum, current_sum); // cap nhat max_sum
	}
	return max_sum;
}

int main() {
	vector<int> arr = {1, -2, 3, 4, -1, 2, 1, -5, 4};
	cout << "Max_sum: " << max_sum_subarray(arr, arr.size()) << endl;
	
	return 0;
}
