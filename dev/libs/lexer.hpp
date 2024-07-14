/*
    Cricket
    ------------ lexer.hpp ------------
    The lexer header helps to break the input command into lexical tokens.
    Based on the tokens, the logical functions are called for the game.
*/

#ifndef __LEXER__INCLUDED__
#define __LEXER__INCLUDED__

// Some pre-required headers. 
#include "commons.hpp"
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>

// Define the class Lexer.
typedef class Lexer {
    // so the input command which is passed from the cmd function can be broken and stored
    // as tokens, which can be used appropriately.
    private:
        std::vector <std::string> tokens;
    public:
        Commands_Type set_command_type(const std::string& token) {
            // Here, the token is passed, match the token as per the enum set commands, and return the type.
            // Convert the token to upper case.
            std::string temp_token = token;
            std::transform(temp_token.begin(),temp_token.end(),temp_token.begin(),::toupper);
            switch(temp_token.at(0)) {
                case 'C':
                    if(temp_token == "CREATE_CUSTOM_TEAM") return CREATE_CUSTOM_TEAM;
                    break;
                case 'E':
                    if(temp_token == "EXIT") return EXIT;
                    break;
                default:
                    return UNKNOWN_COMMAND;
            }
            return UNKNOWN_COMMAND;
        }

        void lexer_tokenizer(Command& cmd) {
            // Break the input buffer into tokens and store them for use.
            Commands_Type temp_cmd;
            std::string input = cmd.getCommandBuffer();
            std::stringstream tokenizer_state(input);
            std::string intermediate_state;
            while(std::getline(tokenizer_state,intermediate_state,' ')) {
                tokens.push_back(intermediate_state);
            }
            temp_cmd=set_command_type(tokens[0]);
            cmd.setCommandSetter(temp_cmd);
        }
    
} Lexer;

#endif