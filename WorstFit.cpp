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

void worst_fit(vector<block>& blocks, vector<process>& processes) {
	for (const auto& prc : processes) {
		int worstIdx = -1; // khoi tao vi tri te nhat
		for (int i = 0; i < blocks.size(); i++) {
			if (blocks[i].isFree && blocks[i].size >= prc.size) {
				if (worstIdx == -1 || blocks[i].size > blocks[worstIdx].size) {
					worstIdx = i;
				}
			}
		}
		if (worstIdx != -1) {
			blocks[worstIdx].isFree = false;
            cout << "Tien trinh co kich thuoc " << prc.size << " duoc cap phat vao vung nho co kich thuoc " << blocks[worstIdx].size << endl;
		} else {
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
	worst_fit(blocks, processes);
	
	return 0;
}
