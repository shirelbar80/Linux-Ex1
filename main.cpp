#include <iostream>
#include <string>
#include "q2.h"

using namespace std;

int main (int argc, char* argv[])
{

    if(argc == 3 && ("--hash" == string(argv[1])))
    {
        findHashAndPrintBlock("blocks.txt", argv[2]);
    }

    if(argc == 3 && ("--height" == string(argv[1])))
    {
        findHeightAndPrintBlock("blocks.txt", argv[2]);
    }

    return 0;
}