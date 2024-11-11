#include <iostream>
#include <vector>

using namespace std;

struct block {
    int size;
    bool isFree;
};

struct process {
    int size;
};

void first_fit(vector<block>& blocks, vector<process>& processes) {
    for (const auto& prc : processes) {
        bool allocated = false;
        for (auto& blk : blocks) {
            if (blk.isFree && blk.size >= prc.size) {
                blk.isFree = false; 
                cout << "Tien trinh co kich thuoc " << prc.size << " duoc cap phat vao vung nho co kich thuoc " << blk.size << endl;
                allocated = true;
                break;
            }
        }
        if (!allocated) {
            cout << "Tien trinh co kich thuoc " << prc.size << " khong the cap phat vung nho" << endl;
        }
    }
}

void inputBlock(vector<block>& blocks) {
    int sizeOfBlockMemory;
    cout << "Nhap so luong khoi bo nho: ";
    cin >> sizeOfBlockMemory;
    
    for (int i = 0; i < sizeOfBlockMemory; i++) {
        block blk;
        cout << "Nhap kich thuoc khoi bo nho thu " << (i + 1) << ": ";
        cin >> blk.size;
        blk.isFree = true; 
        blocks.push_back(blk);
    }
}

void inputProcess(vector<process>& processes) {
    int sizeOfProcessMemory;
    cout << "Nhap so luong tien trinh can xu ly: ";
    cin >> sizeOfProcessMemory;
    
    for (int i = 0; i < sizeOfProcessMemory; i++) {
        process prc;
        cout << "Nhap kich thuoc tien trinh yeu cau xu ly thu " << (i + 1) << ": ";
        cin >> prc.size;
        processes.push_back(prc); 
    }
}

int main() {
    vector<block> blocks;
    vector<process> processes;
    
    inputBlock(blocks);
    inputProcess(processes);
    first_fit(blocks, processes);
    
    return 0;
}
