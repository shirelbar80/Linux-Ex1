#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Block {
    string hash;
    int height;
    long long total;
    string time;
    string relayed_by;
    string previous_block;
};

vector<Block> load_db() {
    ifstream file("blocks.txt");
    vector<Block> blocks;

    if (!file) {
        cerr << "Failed to open file: blocks.txt" << endl;
        return blocks;
    }

    string line;
    Block current;

    while (getline(file, line)) {
        if (line.rfind("hash: ", 0) == 0)
            current.hash = line.substr(6);
        else if (line.rfind("height: ", 0) == 0)
            current.height = stoi(line.substr(8));
        else if (line.rfind("total: ", 0) == 0)
            current.total = stoll(line.substr(7));
        else if (line.rfind("time: ", 0) == 0)
            current.time = line.substr(6);
        else if (line.rfind("relayed_by: ", 0) == 0)
            current.relayed_by = line.substr(12);
        else if (line.rfind("previous_block: ", 0) == 0) {
            current.previous_block = line.substr(16);
            blocks.push_back(current);  // Only push after full block is read
        }
    }

    return blocks;
}


