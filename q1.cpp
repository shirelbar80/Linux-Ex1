#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the file and check if it is open
    ifstream file("blocks.txt");
    // Check if the file is open
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    string line;
    int currentLine = 0;


    while (getline(file, line)) {
        currentLine++;
       
        if (currentLine % 7 == 0){//between two blocks

            getline(file, line); // Read the next line

            if(line[0]== 'h'){//not the end
                cout << "|\n|\nV\n";
                cout << line << std::endl;
                currentLine++;
            }
            
        }
        else{
            cout << line << std::endl;
        }
        
    }


    file.close();
    return 0;
}