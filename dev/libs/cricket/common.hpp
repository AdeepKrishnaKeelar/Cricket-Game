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
    int runs_scored, balls_faced;
    int playing_status;
    std::string wicket_cause, wicket_taken_by;
    Player* next;

    Player() : runs_scored(0), balls_faced(0), playing_status(0), next(nullptr) {}
} Player;

// Class to hold the details of the player.
typedef class Cricket_Player_Detail {
private:
    Player player;

public:
    // Setters and Getters functions.
    void set_playerName(const std::string& name) {
        player.player_name.player_Name = name;
    }

    const std::string& get_playerName() const {
        return player.player_name.player_Name;
    }

    Player* getPlayer() {
        return &player;
    }

    Cricket_Player_Detail() {
        player.player_name.player_Name = "";
        player.balls_faced = 0;
        player.runs_scored = 0;
        player.wicket_cause = "";
        player.wicket_taken_by = "";
        player.next = nullptr;
    }
} Cricket_Player_Detail;

// Basic Team Settings Structure
typedef struct Cricket_Team_Settings {
    Player* Players; // Pointer to the head of the linked list
    int isTeamSet_flag;
    std::string Team_Name;
    std::vector<std::string> Team_List;

    Cricket_Team_Settings() : Players(nullptr), isTeamSet_flag(0) {}
} Cricket_Team_Settings;

// Class to hold the details of the Team.
typedef class Cricket_Team {
public:
    Cricket_Team_Settings team_details;

    // Constructor to setup the team.
    Cricket_Team() {
        team_details.isTeamSet_flag=0;
        team_details.Team_Name = "";
    }

    void AddTeamPlayerDetail(std::string player_name) {
        Player* new_Player = new Player();
        new_Player->player_name.player_Name = player_name;

        if (!team_details.Players) {
            team_details.Players = new_Player;
        } else {
            Player* temp = team_details.Players;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new_Player;
        }
    }

    void DisplayPlayerDetail() {
        // Create a temp linked list to iterate through.
        Player* temp = team_details.Players;
        int count=0;
        while(temp) {
            count+=1;
            std::cout<<"Player - "<<count<<"\n";
            std::cout<<"Name - "<<temp->player_name.player_Name<<"\n";
            temp=temp->next;
        }
    }

    void CreatePlayers() {
        // Using the vector, create the linked list.
        for(int i=0;i<team_details.Team_List.size();i++) {
            AddTeamPlayerDetail(team_details.Team_List[i]);
        }
    }

    void SetTeamName(std::string team_name) {
        team_details.Team_Name = team_name;
    }

    void DisplayTeamName() {
        std::cout<<team_details.Team_Name<<"\n";
    }

}Cricket_Team;


#endif