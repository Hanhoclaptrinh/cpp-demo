#include <iostream>
#include <vector>

using namespace std;

// su dung quy hoach dong
// O(n)
int max_sum(vector<int>& a, int n) {
	int current_sum = a[0];
	int max_sum = a[0];
	for (int i = 0; i < n; i++) {
		current_sum = max(a[i], current_sum + a[i]);
		max_sum = max(max_sum, current_sum);
	}
	return max_sum;
}

int main() {
	int n, k;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a.push_back(k);
	}
	cout << "max_sum: " << max_sum(a, n) << endl;
	return 0;
}
