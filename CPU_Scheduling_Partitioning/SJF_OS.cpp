#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cassert>

using namespace std;

struct process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;

    process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), 
          completionTime(0), waitingTime(0), turnAroundTime(0) {}
};

bool compare(process a, process b) {
	return a.burstTime < b.burstTime;
}

void SJF_Scheduling(vector<process>& processes) {
	int n = processes.size();
	vector<bool> isCompleted(n, false);
	int completed = 0;
    int currentTime = 0;
	
	while (completed < n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !isCompleted[i]) {
                if (idx == -1 || processes[i].burstTime < processes[idx].burstTime) {
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            currentTime++;
        } else {
            currentTime += processes[idx].burstTime; 
            processes[idx].completionTime = currentTime;
            processes[idx].turnAroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnAroundTime - processes[idx].burstTime;
            isCompleted[idx] = true; 
            completed++;
        }
    }
    
    cout << "Shortest Job First (non-preemptive)\n\n\n";
    cout << setw(10) << "ID" << setw(15) << "Arrival Time"
         << setw(15) << "Burst Time" << setw(15) << "Completion Time"
         << setw(15) << "TAT" << setw(15) << "Waiting Time" << endl;

    for (const auto& p : processes) {
        cout << setw(10) << p.id
             << setw(15) << p.arrivalTime
             << setw(15) << p.burstTime
             << setw(15) << p.completionTime
             << setw(15) << p.turnAroundTime
             << setw(15) << p.waitingTime << endl;
    }
}

void _test_() {
	vector<process> processes = {
        {1, 0, 8},
        {2, 1, 4},
        {3, 2, 9},
        {4, 3, 5}
    };
    
    SJF_Scheduling(processes);
    
    assert(processes[0].completionTime == 8); 
    assert(processes[1].completionTime == 12);
    assert(processes[2].completionTime == 26); 
    assert(processes[3].completionTime == 17);
    
    assert(processes[0].turnAroundTime == 8); 
    assert(processes[1].turnAroundTime == 11); 
    assert(processes[2].turnAroundTime == 24); 
    assert(processes[3].turnAroundTime == 14);

    assert(processes[0].waitingTime == 0); 
    assert(processes[1].waitingTime == 7); 
    assert(processes[2].waitingTime == 15); 
    assert(processes[3].waitingTime == 9); 	
    
    cout << "All tests passed!" << endl;
}

int main() {
	_test_();
    return 0;
}
