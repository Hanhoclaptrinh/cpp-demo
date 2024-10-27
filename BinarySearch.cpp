#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& a, int left, int right, int target) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (a[mid] == target) {
			return mid;
		}
		
		if (mid < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	vector<int> a = {423, 458, 534, 978, 345, 123};
	sort(a.begin(), a.end());
	int target = 534;
	int res = binary_search(a, 0, a.size() - 1, target);
	if (res != -1) {
		cout << "Element " << target << " found at index " << res << endl;
	} else {
		cout << "Element " << target << " not found in the vector"  << endl;
	}
	
	return 0;
}
