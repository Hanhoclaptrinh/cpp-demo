#include <iostream>
#include <vector>

void Merge(std::vector<int>& A, std::vector<int>& left, std::vector<int>& right, int low) {
	int i = 0, j = 0, k = low;
	
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j]) {
			A[k] = left[i];
			i++;
		} else {
			A[k] = right[j];
			j++;
		}
		k++;
	}
	
	while (i < left.size()) {
		A[k] = left[i];
		i++;
		k++;
	}
	
	while (j < right.size()) {
		A[k] = right[j];
		j++;
		k++;
	}
}

// O(nlogn)
void MergeSort(std::vector<int>& A, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		
		std::vector<int> left(A.begin() + low, A.begin() + mid + 1); // nua mang trai (0 -> mid)
        std::vector<int> right(A.begin() + mid + 1, A.begin() + high + 1); // nua mang phai (mid + 1 -> high)
		
		Merge(A, left, right, low);
	}
}

void input(std::vector<int>& A) {
//	int val;
    int size;
    std::cout << "Size of array: ";
    std::cin >> size;
    A.resize(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> A[i];
//        std::cin >> val;
//        A.push_back(val);
    }
}

void output(std::vector<int>& A) {
	for (auto& x : A) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> A;
	input(A);
	std::cout << "Array: ";
	output(A);
	MergeSort(A, 0, A.size() - 1);
	std::cout << "Sorted array: ";
	output(A);
	
	return 0;
}
