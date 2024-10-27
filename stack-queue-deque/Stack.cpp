#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> myStack;
	
	myStack.push(10);
	myStack.push(20);
	myStack.push(30);
	
	cout << "Element on top " << myStack.top() << endl;
	
	myStack.pop();
	cout << "Element on top after pop " << myStack.top() << endl;
	
	cout << "Size of stack " << myStack.size() << endl;
	
	if (!myStack.empty()) {
		cout << "Non-empty stack" << endl;
	} else {
		cout << "Empty stack" << endl;
	}
	
	while (!myStack.empty()) {
		cout << myStack.top() << " ";
		myStack.pop(); 
	}
	cout << endl;
	return 0;
}
