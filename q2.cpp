#include "q2.h"
#include <iostream>
#include <fstream>

using namespace std;

void findHashAndPrintBlock (const string& nameOfFile, const string& hashToFind)
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
}

void findHeightAndPrintBlock (const string& nameOfFile, const string& heightToFind)
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
}
