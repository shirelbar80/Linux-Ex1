#include "utils.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintMenu();
void RunQ5();
void ExecuteChoice(int choiceNum, vector<Block> blocks);

int main() {
    RunQ5();
    return 0;
}

void PrintMenu()
{
    cout << "Choose an option:" << endl;
    cout << "1. Print db" << endl;
    cout << "2. Print block by hash" << endl;
    cout << "3. Print block by height" << endl;
    cout << "4. Export data to csv" << endl;
    cout << "5. Refresh data" << endl;
    cout << "Enter your choice: ";
}

void RunQ5() {

    vector<Block> blocks = load_db();
    cout << "Loaded " << blocks.size() << " blocks." << endl;  // <-- add this

    PrintMenu();
    int choice;
    cin >> choice;
    ExecuteChoice(choice, blocks);
}

void ExecuteChoice (int choiceNum, vector<Block> blocks)
{
    if (choiceNum == 1)
    {
        printBlocks(blocks);
    }
    else if (choiceNum == 2)
    {
        string hashNumber;
        cout << "Enter block hash: " << endl;
        cin >> hashNumber;
        findAndPrintBlockByField("--hash", hashNumber, blocks);
    }
    else if (choiceNum == 3)
    {
        string heightNumber;
        cout << "Enter block height: " << endl;
        cin >> heightNumber;
        findAndPrintBlockByField("--height", heightNumber, blocks);
    }
    else if (choiceNum == 4)
    {
        ExportTxtToCSV();
    }
    else if (choiceNum == 5)
    {
        //add after shirel fix
    }
}