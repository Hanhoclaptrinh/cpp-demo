#include <iostream>

// su dung de quy 
// O(2^n)
int fibo(int n) {
	if (n <= 1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}

// khong dung de quy
// O(n)
int fibonacci(int n) {
	int f0 = 0;
	int f1 = 1;
	int fn = 1;
	
	if (n <= 1)
		return n;
	if (n < 0)
		return -1;
	
	for (int i = 2; i < n; i++) {
		f0 = f1;
		f1 = fn;
		fn = f0 + f1;
	}
	return fn;
}

int main() {
	int n;
	std::cout << "n: ";
	std::cin >> n;
	std::cout << "Value at " << n << " (use conquer): " << fibo(n) << std::endl;
	std::cout << "Value at " << n << " (not use conquer): " << fibonacci(n) << std::endl;
	std::cout << "Fibonacci series: ";
	for (int i = 0; i < n; i++) {
		std::cout << fibonacci(i) << " ";
	}
	std::cout << "\n";
	return 0;
}
