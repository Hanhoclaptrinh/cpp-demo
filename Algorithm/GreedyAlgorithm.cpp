#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> greedy_change(int amount, vector<int>& denominations) {
	vector<int> coins;
	
	sort(denominations.rbegin(), denominations.rend());
	
	for (int coin : denominations) {
		while (amount >= coin) {
			amount -= coin;
			coins.push_back(coin);
		}
	}
	return coins;
}

int main() {
	int amount;
	cout << "amount: ";
	cin >> amount;
	
	vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500};
	
	vector<int> result = greedy_change(amount, denominations);
	
	cout << "result: ";
	for (int coin : result) {
		cout << coin << " ";
	}
	cout << endl;
	
	return 0;
}
