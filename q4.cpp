#include <iostream>
#include <cstdlib> // for system()

int main() {

    int numBlocks = 5; // Number of blocks to create
   // Prepare the command string
   std::string command = "./get_blocks.sh " + std::to_string(numBlocks);


  // Run the command
  system(command.c_str());

    return 0;

}
