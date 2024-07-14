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
    VERSION, // Details of the version.
    HELP, // Details of the entire Game.
    EXIT, // Command to exit.
    UNKNOWN_COMMAND // Unknown command handling.
} Commands_Type;

// Class for the input command buffer.
typedef class Input_Command {
    // Properties of the class.
    private:
        Commands_Type command_type;
        std::string command_buffer; 
    // Getters, Setters, etcetera, for Input_Command.
    public:
        // Set the input command buffer.
        void setCommandBuffer(const std::string& buffer) {
            command_buffer = buffer;
        }
        // Set the command type.
        void setCommandSetter(Commands_Type command) {
            command_type = command;
        }
        // Return the command buffer.
        const std::string& getCommandBuffer() const {
            return command_buffer;
        }
        // Return the command type.
        Commands_Type getCommandType() const {
            return command_type;
        }
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
    std::cout<<"Developed by AKK\n";
}


// Setup the terminal for the program.
void terminal_setup() {
    std::cout<<"🏏 ";
}


#endif