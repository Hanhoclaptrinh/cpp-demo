#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k_smallest(vector<int>& arr, int n, int k) {
	if (n < k) {
		cout << "Mang phai co it nhat k phan tu\n";
		return -1;
	}
	sort(arr.begin(), arr.end());
	return arr[k - 1];
}

int main() {
	int n, a;
	cout << "n: "; cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	int k;
	cout << "k: "; cin >> k;
	if (result != -1) {
		cout << "Gia tri nho thu " << k << " trong mang la: " << k_smallest(arr, n, k);
	}
	return 0;
}
