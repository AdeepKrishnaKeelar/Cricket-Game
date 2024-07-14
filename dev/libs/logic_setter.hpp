/*
    Cricket
    ------------ logic_setter.hpp ------------
    This header file sets the logic for the various commands.
*/

#ifndef __LOGIC_SETTER__INCLUDED__
#define __LOGIC_SETTER__INCLUDED__

//Pre-required Header files.
#include "lexer.hpp"

typedef class Logic_Setter {
    public:
        void Logic_Brancher(Command& cmd,Lexer& lexer) {
            Commands_Type temp_cmd_type = cmd.getCommandType();
            switch(temp_cmd_type) {
                // EXIT Logic.
                case EXIT:
                    std::cout<<"Bye.\n";
                    exit(EXIT_SUCCESS);
                    break;

                // UNKNOWN_COMMAND Logic.
                case UNKNOWN_COMMAND:
                    std::cout<<"Unknown command.\nPlease refer the HELP manual.\n";
                    exit(EXIT_FAILURE);
                    break;
            }
        }
} Logic_Setter;

#endif