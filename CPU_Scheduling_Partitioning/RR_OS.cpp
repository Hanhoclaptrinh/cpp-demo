#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Process {
public:
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
    int completionTime;

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->remainingTime = burstTime;
        this->waitingTime = 0;
        this->turnAroundTime = 0;
        this->completionTime = 0;
    }
};

void roundRobin(vector<Process>& processes, int quantum) {
    int currentTime = 0;
    int completedProcesses = 0;
    int n = processes.size();

    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > quantum) {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    currentTime += processes[i].remainingTime;
                    processes[i].completionTime = currentTime;
                    processes[i].turnAroundTime = currentTime - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
                    processes[i].remainingTime = 0;
                    completedProcesses++;
                }
            }
        }
    }
}

int main() {
    int n, quantum;
    cout << "Nhap so luong tien trinh: ";
    cin >> n;
    cout << "Nhap quantum: ";
    cin >> quantum;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        int arrivalTime, burstTime;
        cout << "Nhap thoi gian den va thuc thi cho tien trinh " << (i + 1) << ": ";
        cin >> arrivalTime >> burstTime;
        processes.emplace_back(i + 1, arrivalTime, burstTime);
    }

    roundRobin(processes, quantum);

    cout << "-------------------------------------------------------------------------------------" << endl;
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

    cout << "-------------------------------------------------------------------------------------" << endl;
    
    return 0;
}

