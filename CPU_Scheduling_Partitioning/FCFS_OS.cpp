#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class process {
	public:
		int id;
		int arrivalTime;
		int burstTime;
		int turnAroundTime;
		int completionTime;
		int waitingTime;
	
	process(int id, int arrivalTime, int burstTime) {
		this->id = id;
		this->arrivalTime = arrivalTime;
		this->burstTime = burstTime;
	}
};

int main() {
	cout << "First Come First Served\n\n";
	int size;
	cout << "Nhap so luong tien trinh: ";
	cin >> size;
	
	vector<process> lst_process;
	
	for (int i = 0; i < size; i++) {
		cout << "Nhap thong tin tien trinh " << (i + 1) << endl;
		int arrivalTime, burstTime;
		cout << "Nhap thoi gian den: ";
		cin >> arrivalTime;
		cout << "Nhap thoi gian thuc thi: ";
		cin >> burstTime;
		
		// add process into list
		lst_process.emplace_back(i + 1, arrivalTime, burstTime);
	}
	
	// sort process by arrivalTime
	sort(lst_process.begin(), lst_process.end(), [](const process& a, const process& b) {
		return a.arrivalTime < b.arrivalTime;
	});
	
	int currentTime = 0;
	
	for (auto& prc : lst_process) {
		if (currentTime < prc.arrivalTime) 
			currentTime = prc.arrivalTime;
		prc.completionTime = currentTime + prc.burstTime;
		currentTime = prc.completionTime;
		prc.turnAroundTime = prc.completionTime - prc.arrivalTime;
		prc.waitingTime = prc.turnAroundTime - prc.burstTime;
	}
	
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << setw(10) << "ID" << setw(15) << "Arrival Time"
         << setw(15) << "Burst Time" << setw(15) << "Completion Time"
         << setw(15) << "TAT" << setw(15) << "Waiting Time" << endl;

    for (const auto& p : lst_process) {
        cout << setw(10) << p.id
             << setw(15) << p.arrivalTime
             << setw(15) << p.burstTime
             << setw(15) << p.completionTime
             << setw(15) << p.turnAroundTime
             << setw(15) << p.waitingTime << endl;
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
    
    return 0;
}
