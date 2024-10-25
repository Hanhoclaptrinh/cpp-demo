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
    int turnAroundTime;
    int completionTime;
    int waitingTime;

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->remainingTime = burstTime; 
        this->turnAroundTime = 0;        
        this->completionTime = 0;      
        this->waitingTime = 0; 
    }
};

int main() {
    int soLuong;
    cout << "Shortest Remaining Time First\n\n";
    cout << "Nhap so luong tien trinh: ";
    cin >> soLuong;
    
    vector<Process> lst_process;
    
    for (int i = 0; i < soLuong; i++) {
        cout << "Nhap thong tin tien trinh " << (i + 1) << endl;
        int arrivalTime, burstTime;
        cout << "Nhap thoi gian den: "; cin >> arrivalTime;
        cout << "Nhap thoi gian thuc thi: "; cin >> burstTime;
        
        lst_process.emplace_back(i + 1, arrivalTime, burstTime);
    }
    
    int currentTime = 0;
    int completedProcess = 0;
    
    while (completedProcess < soLuong) {
        Process* nextProcess = nullptr;
        for (auto& prc : lst_process) {
            if (prc.arrivalTime <= currentTime && prc.remainingTime > 0) {
                if (nextProcess == nullptr || prc.remainingTime < nextProcess->remainingTime) {
                    nextProcess = &prc;
                }
            }
        }
        
        if (nextProcess == nullptr) {
            currentTime++;
            continue;
        }
        
        nextProcess->remainingTime--;
        currentTime++;
        
        if (nextProcess->remainingTime == 0) {
            nextProcess->completionTime = currentTime;
            nextProcess->turnAroundTime = nextProcess->completionTime - nextProcess->arrivalTime;
            nextProcess->waitingTime = nextProcess->turnAroundTime - nextProcess->burstTime;
            completedProcess++;
        }
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

