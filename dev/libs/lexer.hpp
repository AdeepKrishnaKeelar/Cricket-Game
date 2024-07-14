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
#include <string>

// Define the class Lexer.
typedef class Lexer {
    // so the input command which is passed from the cmd function can be broken and stored
    // as tokens, which can be used appropriately.
    private:
        std::vector <std::string> tokens;
    public:
        void lexer_tokenizer(const Command& cmd) {
            
        }
    
} Lexer;

#endif