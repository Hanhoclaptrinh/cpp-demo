#include <iostream>

// O(n^2) O(n)
void Insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int k = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > k) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

int main() {
	int a[] = {34, 86, 12, 97, 76, 67, 23};
	int n = sizeof(a) / sizeof(a[0]);
	Insertion_sort(a, n);
	std::cout << "Sorted array: ";
	for (int x : a) {
		std::cout << x << " ";
	}
	std::cout << '\n';
	return 0;
}
