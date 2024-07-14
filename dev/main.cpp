/* 
    The beloved Cricket Game is back into action again!! 
    Developed by AKK
    Do whatever you like with my code, just don't mess it up and push it to master lol.
*/

// The HEADERS
#include <iostream>
#include <string>
#include "libs/commons.hpp"


int main(int argc, char* argv[]) {
    // Defining the class to capture the user input.
    Command cmd;
    std::string input_command;
    intro_func();
    while(1) {
        try {
            terminal_setup();
            std::getline(std::cin,input_command);
            if(input_command.empty()) {
                throw std::runtime_error(
                    "Input Command is empty, there needs to be an entry."
                );
            }
            
        } catch(const std::exception& e) {
            // Print the exception handed.
            std::cout<<e.what()<<"\n";
        }
    }
    return EXIT_SUCCESS;
}