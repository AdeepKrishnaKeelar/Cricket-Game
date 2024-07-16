/*
    Cricket
    ------------ logic_setter.hpp ------------
    This header file sets the logic for the various commands.
*/

#ifndef __LOGIC_SETTER__INCLUDED__
#define __LOGIC_SETTER__INCLUDED__

//Pre-required Header files.
#include "lexer.hpp"
#include "generators/name_team_generator.hpp"
#include "cricket/common.hpp"

typedef class Logic_Setter {
    private:
        const float version = 1.0;
    public:

        // Helper functions.
        void logic_brancher_help() {
            intro_func();
            std::cout<<"-----------------------------------------------------------------\n";
            std::cout<<"|  Commands ----                                                |\n";
            std::cout<<"|  CREATE_CUSTOM_TEAM - Create a custom team.                   |\n";
            std::cout<<"|  GAME_PLAY - Play the game in various modes                   |\n";
            std::cout<<"|  HELP - Help Manual                                           |\n";
            std::cout<<"|  VERSION - Display version.                                   |\n";
            std::cout<<"|  EXIT - End Game                                              |\n";
            std::cout<<"-----------------------------------------------------------------\n";    
        }
        
        // The main logic branching function.
        void Logic_Brancher(Command& cmd,Lexer& lexer) {
            Commands_Type temp_cmd_type = cmd.getCommandType();
            switch(temp_cmd_type) {
                
                // The Easier functions
                // HELP Logic.
                case HELP:
                    logic_brancher_help();
                    break;        
                
                // EXIT Logic.
                case EXIT:
                    std::cout<<"Bye.\n";
                    exit(EXIT_SUCCESS);
                    break;

                case VERSION:
                    intro_func();
                    std::cout<<"Version -- "<<version<<"\n";
                    break;

                // UNKNOWN_COMMAND Logic.
                case UNKNOWN_COMMAND:
                    std::cout<<"Unknown command.\nPlease refer the HELP manual.\n";
                    exit(EXIT_FAILURE);
                    break;

                // Building the complex commands.
                // CREATE_CUSTOM_TEAM Logic.
                case CREATE_CUSTOM_TEAM: {
                    /* 
                        CREATE_CUSTOM_TEAM [-n|--name](random/custom) [-t|--type](random/custom) [-f|--file](file with names)
                        -n|--name ---> Set the name of the team. If random, system chooses name. Else, file is mandatory.
                        -t|--type ---> Set the players of the team. If random, system chooses names, else file is mandatory.
                        -f|--file ---> File Path with name of team and team players.   
                    */
                    random_name_generator();
                    break;
                }
            }
        }
} Logic_Setter;

#endif