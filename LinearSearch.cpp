#include<iostream>
#include<vector>
using namespace std;
int linear_search(vector<int>&a, int target){
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == target)
			return 1;
	}
	return -1;
}

int main() {
	vector<int> a = {234, 567, 4353, 78678, 32455, 2342};
	int target = 567;
	if(linear_search(a, target) != -1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}
