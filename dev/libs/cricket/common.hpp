/*
    Cricket
    ------------ common.hpp ------------
    The common set of data structures and functions related to "cricket" are stored here.
*/

#ifndef __COMMON_INCLUDED__
#define __COMMON_INCLUDED__

// Header files to be used.
#include <iostream>
#include <string>

// Structure of the Player Name.
typedef struct Player_Name {
    std::string player_Name; // Name follows <first_name>_<last_name> format.
} Player_Name;

typedef struct Player {
    Player_Name player_name;
    Player *next;
} Player;

// Class to hold the details of the player.
class Cricket_Player_Detail {
    private:
        Player *player;

    public:
        // Setters and Getters functions.
        void set_playerName(const std::string& name) {
            player->player_name.player_Name = name;
        }
        const std::string& get_playerName() {
            return player->player_name.player_Name;
        }

};

#endif