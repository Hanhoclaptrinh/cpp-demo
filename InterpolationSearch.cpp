#include <iostream>
#include <algorithm>

using namespace std;

int interpolation_search(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	
	while (left <= right && target >= arr[left] && target <= arr[right]) {
		int pos = left + ((double) (right - left) / (arr[right] - arr[left]) * (target - arr[left]));
		
		if (arr[pos] == target) {
			return pos;
		}
		
		if (arr[pos] < target) {
			left = pos + 1;
		} else {
			right = pos - 1;
		}
	}
	return -1;
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 70;
	int res = interpolation_search(arr, size, target);
	if (res != -1) {
		cout << "Element " << target << " found at index " << res << endl;
	} else {
		cout << "Element " << target << " not found in the array" << endl;
	}
	
	return 0;
}
