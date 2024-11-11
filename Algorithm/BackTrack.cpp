#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, vector< vector<int>>& result, int start) {
	if (start == nums.size()) {
		result.push_back(nums);
		return;
	}
	
	for (int i = start; i < nums.size(); i++) {
		swap(nums[start], nums[i]);
		
		backtrack(nums, result, start + 1);
		
		swap(nums[start], nums[i]);
	}
}

int main() {
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> result;
	
	backtrack(nums, result, 0);
	
	for (const auto& n : result) {
		for (int i : n) {
			cout << i << " ";
		}
		cout << endl;
	}
	
	return 0;
}
