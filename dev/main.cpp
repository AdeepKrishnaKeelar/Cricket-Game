/* 
    The beloved Cricket Game is back into action again!! 
    Developed by AKK
    Do whatever you like with my code, just don't mess it up and push it to master lol.
*/

// The HEADERS
#include <iostream>
#include <string>
#include "libs/lexer.hpp"


int main(int argc, char* argv[]) {
    // Defining the class to capture the user input.
    Command cmd;
    Lexer lexer;
    std::string input_command;
    intro_func();
    while(1) {
        try {
            terminal_setup();
            std::getline(std::cin,input_command); // Input command.
            if(input_command.empty()) {
                // If no command is passed, then break as an error.
                throw std::runtime_error(
                    "Input Command is empty, there needs to be an entry.\n"
                );
            }
            cmd.setCommandBuffer(input_command); // Set the input command to the main object.
            
            //Now, pass the cmd object to the lexical analyser and breaker.    
            lexer.lexer_tokenizer(cmd);       
        } catch(const std::exception& e) {
            // Print the exception handed.
            std::cout<<e.what()<<"\n";
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}