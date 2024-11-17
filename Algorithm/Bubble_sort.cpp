#include <iostream>

using namespace std;

// O(n^2)
void bubble_sort(int a[], int n) {
	bool flag;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
}

int main() {
	int a[] = {-2, 11, -4, 13, -5, 2};
	int n = sizeof(a) / sizeof(a[0]);
	bubble_sort(a, n);
	for (auto& i : a) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
