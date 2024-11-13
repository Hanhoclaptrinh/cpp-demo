#include <iostream>
#include <algorithm>
#define MOD 1000000000
#define ll long long

using namespace std;

// O(logn)
int main() {
	ll a, b;
	ll result = 1;
	
	cout << "a & b: ";
	cin >> a >> b;
	
	a %= MOD;
	
	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	
	cout << "Result: " << result << endl;
	
	return 0;
}
