#include <iostream>

// O(n^2)
void selection_sort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_idx] > a[j])
				min_idx = j;
		}
		if (min_idx != i) {
			int tmp = a[min_idx];
			a[min_idx] = a[i];
			a[i] = tmp;
		}
	}
}

int main() {
	int a[] = {75, 32, 58, 99, 12, 85, 17, 41, 60, 29};
	int n = sizeof(a) / sizeof(a[0]);
	std::cout << "Array: ";
	for (int x : a) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	
	selection_sort(a, n);
	std::cout << "Sorted array: ";
	for (int x : a) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	return 0;
}
