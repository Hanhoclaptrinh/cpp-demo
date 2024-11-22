#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main() {
	int n = 100000;
	auto start = high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
		cout << i << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Thoi gian thuc thi la " << duration.count() << " ms" << endl;
	return 0;
}
