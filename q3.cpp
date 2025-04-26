#include <iostream>
#include <fstream>
#include <string>

int main() {
    //opening the input and output files
    std::ifstream inputFile("blocks.txt");
    std::ofstream outputFile("blocks.csv");
    
    // Check if the files are open
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error in opening input or output file!" << std::endl;
        return 1;
    }

    // Write CSV header
    outputFile << "hash,height,total,time,relayed_by,previous_block\n";

    std::string line;
    std::string hash, height, total, time, relayed_by, previous_block;

    while (std::getline(inputFile, line)) {//gets the line
        if (line.empty()) {//if the line is empty
            // End of one block: write to CSV all the details
            outputFile << hash << "," << height << "," << total << "," << time << "," << relayed_by << "," << previous_block << "\n";
            continue;
        }

        // Find the delimiter ':' and split the line into key and value
        size_t delimiterPos = line.find(':');
        if (delimiterPos != std::string::npos) {//if the delimiter is found
            // Extract key and value
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);

            // Remove spaces from the value
            size_t firstNonSpace = value.find_first_not_of(' ');
            if (firstNonSpace != std::string::npos) {//if there are leading spaces
                // Remove spaces
                value = value.substr(firstNonSpace);
            }

            // Assign the value to the appropriate variable based on the key
            if (key == "hash") hash = value;
            else if (key == "height") height = value;
            else if (key == "total") total = value;
            else if (key == "time") time = value;
            else if (key == "relayed_by") relayed_by = value;
            else if (key == "previous_block") previous_block = value;
        }
    }

    //closing the files
    inputFile.close();
    outputFile.close();

    return 0;
}
