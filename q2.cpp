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
        if(line.find(hashToFind) != string::npos)
        {
            cout << line << endl;
            for(i = 0; i < 6; i++)
            {
                if(getline(file,line))
                {
                    cout << line << endl;
                }
                else
                {
                    break;
                }
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
            for(i = 0; i < 5; i++)
            {
                if(getline(file,line))
                {
                    cout << line << endl;
                }
                else
                {
                    break;
                }
            }
            file.close();
            return;
        }
        prevLine = line;
    }

    file.close();
}
