#include <iostream>

void swap(int &a, int &b) {
	if (a > b) {
		int tmp = a;
		a= b;
		b = tmp;
	}
}

int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	
	for (int j = low; j < high; j++) {
		if (a[j] < pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1;
}

void quick_sort(int a[], int low, int high) {
	if (low < high) {
		int pivotIdx = partition(a, low, high);
		quick_sort(a, low, pivotIdx - 1);
		quick_sort(a, pivotIdx + 1, high);
	}
}

void inputArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> a[i];
    }
}


void outputArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
	int size;
	std::cin >> size;
	int a[size];
	inputArray(a, size);
	quick_sort(a, 0, size - 1);
	outputArray(a, size);
	return 0;
}
