/*
    Cricket
    ------------ commons.hpp ------------
    The common set of data structures and functions are stored here.
*/

#ifndef __COMMONS_INCLUDED__
#define __COMMONS_INCLUDED__

// Enumerated types that serve as a base for the CLI.
typedef enum {
    CREATE_CUSTOM_TEAM, // Command to create custom team. This command will have sub commands.
    GAME_PLAY, // Command to play the game. This command will have sub commands.
    EXIT // Command to exit.
} Commands_Type;

// Class for the input command buffer.
typedef class Input_Command {
    // Properties of the class.
    private:
        Commands_Type command_type;
        std::string command_buffer; 
    // Getters, Setters, etcetera, for Input_Command.
    public:
        
} Command;

// Intro function.
void intro_func() {
    const char* intro = "\
██████  ██████  ██  ██████ ██   ██ ███████ ████████\n\
██      ██   ██ ██ ██      ██  ██  ██         ██\n\
██      ██████  ██ ██      █████   █████      ██\n\
██      ██   ██ ██ ██      ██  ██  ██         ██\n\
 ██████ ██   ██ ██  ██████ ██   ██ ███████    ██";

    std::cout << intro << "\n";
}


// Setup the terminal for the program.
void terminal_setup() {
    std::cout<<"🏏 ";
}


#endif