#include <iostream>
#include <deque>
 
int main() {
	std::deque<int> myDeque;
	
	myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_back(30);
    
    myDeque.push_front(5);
    
    std::cout << "Deque: ";
    for (int num : myDeque) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    myDeque.pop_front();
    std::cout << "Element in front after pop front " << myDeque.front() << std::endl;
    
    myDeque.pop_back();
    std::cout << "Element at back after pop back " << myDeque.back() << std::endl;
    
    std::cout << "Size of deque " << myDeque.size() << std::endl;
    
    if (!myDeque.empty()) {
    	std::cout << "Non-empty deque" << std::endl;
	} else {
		std::cout << "Empty deque" << std::endl;
	}
	
	return 0;
}
