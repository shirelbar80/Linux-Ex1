#include "utils.h"
#include "printer.h"
#include <iostream>
#include <fstream>

using namespace std;




int main(int argc, char* argv[]) {


    if (argc != 3) {
        print_error("Usage: " + string(argv[0]) + " --hash <value> OR --height <value>\n");
        return 1;
    }

    string option = argv[1];
    string value = argv[2];
    vector<Block> blocks = load_db();

    if (option == "--hash") {
        findAndPrintBlockByField("hash", value, blocks);
    } else if (option == "--height") {
        findAndPrintBlockByField("height", value, blocks);
    } else {
        print_output("Invalid option: " + option + "\nUse --hash or --height\n");
        return 1;
    }

    return 0;
}



/////////// NEW FUNCTIONS IN UTILS ///////////

/*void findHashAndPrintBlock (const string& nameOfFile, const string& hashToFind)
{
    int i;
    string line;

    ifstream file(nameOfFile);
    if(!file.is_open())
    {
        cout << "couldnt open "<< nameOfFile << endl;
    }

    while(getline(file,line))
    {
        if(line.find("hash: " + hashToFind) != string::npos)
        {
            cout << line << endl;
            while (getline(file, line))
            {
                if (line.empty())
                {
                    break;
                }
                cout << line << endl;
            }
            file.close();
            return;
        }
    }

    file.close();
}*/

/*void findHeightAndPrintBlock (const string& nameOfFile, const string& heightToFind)
{
    int i;
    string prevLine, line;

    ifstream file(nameOfFile);
    if(!file.is_open())
    {
        cout << "couldnt open "<< nameOfFile << endl;
    }

    while(getline(file,line))
    {
        if(line.find(heightToFind) != string::npos)
        {
            cout << prevLine << endl;
            cout << line << endl;
            while (getline(file, line))
            {
                if (line.empty())
                {
                    break;
                }
                cout << line << endl;
            }            
            file.close();
            return;
        }
        prevLine = line;
    }

    file.close();
}*/
