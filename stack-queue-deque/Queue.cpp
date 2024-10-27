#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> myQueue;
	
	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30);
	
	cout << "Element in front " << myQueue.front() << endl;
	
	cout << "Element at back " << myQueue.back() << endl;
	
	myQueue.pop();
	cout << "Element in front after pop " << myQueue.front() << endl;
	
	cout << "Size of queue " << myQueue.size() << endl;
	
	if (!myQueue.empty()) {
		cout << "Non-empty queue" << endl;
	} else {
		cout << "Empty queue" << endl;
	}
	
	while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
	
	return 0;
}
