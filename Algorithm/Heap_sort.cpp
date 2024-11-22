#include <iostream>
#include <chrono>
using namespace std::chrono;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heapify(int a[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && a[left] > a[largest]) 
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void buildMaxHeap(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
}

void heapSort(int a[], int n) {
	buildMaxHeap(a, n);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int main() {
	int a[] = {4, 6, 2, 5, 1, 3};
	int n = sizeof(a) / sizeof(a[0]);
	
	auto start = high_resolution_clock::now();
	heapSort(a, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	
	std::cout << "Sorted array: ";
	for (int i : a) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Thoi gian thuc thi: " << duration.count() << " nanoseconds" << std::endl;
	return 0;
}
