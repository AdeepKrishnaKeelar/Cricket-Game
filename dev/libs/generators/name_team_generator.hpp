/*
    Cricket
    ------------ name_team_generator.hpp ------------
    The functionality for the name and team generator stored here.
*/

#ifndef __NAME_TEAM_GENERATOR__INCLUDED__
#define __NAME_TEAM_GENERATOR__INCLUDED__

// Header files used
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "../cricket/common.hpp"

std::vector<std::string> random_name_generator() {
    // Will be re-written.
    // 1. Set count of 11 players.
    // 2. Have two random number variables for first and last name.
    // 3. Open the files, go to the file to the variables value and read the names.
    // 4. Concatenate the names, and store them.
    int total_players_count = 11;
    int random_first_name_count=0, random_last_name_count=0;
    std::vector <std::string> players_names;
    const std::string first_name_file_path = "data/name-generator/first-names.txt";
    const std::string last_name_file_path = "data/name-generator/last-names.txt";
    unsigned num = std::chrono::system_clock::now().time_since_epoch().count();
    int n;
    std::mt19937 generator(num);
    
    // 3rd step
    for(int i=0;i<total_players_count;i++) {
        random_first_name_count = generator()%174; // Need to make this value dynamic by size.
        random_last_name_count = generator()%102; // Need to make this value dynamic by size.

        // For first names file.
        std::ifstream first_name_file_ptr(first_name_file_path);
        if(!first_name_file_ptr.is_open()) {
            std::cout<<"Error, first name file does not exist or path incorrect.";
            exit(EXIT_FAILURE);
        }
        std::string str_fname, str_lname;
        for(int j=0;j<random_first_name_count;j++) {
            if(!std::getline(first_name_file_ptr,str_fname)) {
                std::cout<<"Name failed to generate";
                exit(EXIT_FAILURE);
            }
        }
        first_name_file_ptr.close();

        // For last names file.
        std::ifstream last_name_file_ptr(last_name_file_path);
        if(!last_name_file_ptr.is_open()) {
            std::cout<<"Error, last name file does not exist or path incorrect.";
            exit(EXIT_FAILURE);
        }
        for(int j=0;j<random_last_name_count;j++) {
            if(!std::getline(last_name_file_ptr,str_lname)) {
                std::cout<<"Name failed to generate";
                exit(EXIT_FAILURE);
            }
        }
        last_name_file_ptr.close();

        std::string name = str_fname + "_" + str_lname;
        players_names.push_back(name);
    }

    return players_names;
}

std::string random_team_name_generator() {
    // Will be re-vamped later.
    // Similar to the above mentioned algorithm as random_name_generator() 
    int random_first_name_count=0, random_last_name_count=0;
    const std::string first_name_file_path = "data/name-generator/object-descriptors.txt";
    const std::string last_name_file_path = "data/name-generator/object-names.txt";
    std::string team_name;
    unsigned num = std::chrono::system_clock::now().time_since_epoch().count();
    int n;
    std::mt19937 generator(num);

    random_first_name_count=generator()%60; // make value dynamic.
    random_last_name_count=generator()%61; // make value dynamic.

    // For first names file.
    std::ifstream first_name_file_ptr(first_name_file_path);
    if(!first_name_file_ptr.is_open()) {
        std::cout<<"Error, first name file does not exist or path incorrect.";
        exit(EXIT_FAILURE);
    }
    std::string str_fname, str_lname;
    for(int j=0;j<random_first_name_count;j++) {
        if(!std::getline(first_name_file_ptr,str_fname)) {
            std::cout<<"Name failed to generate";
            exit(EXIT_FAILURE);
        }
    }
    first_name_file_ptr.close();

    // For last names file.
    std::ifstream last_name_file_ptr(last_name_file_path);
    if(!last_name_file_ptr.is_open()) {
        std::cout<<"Error, last name file does not exist or path incorrect.";
        exit(EXIT_FAILURE);
    }
    for(int j=0;j<random_last_name_count;j++) {
        if(!std::getline(last_name_file_ptr,str_lname)) {
            std::cout<<"Name failed to generate";
            exit(EXIT_FAILURE);
        }
    }
    last_name_file_ptr.close();

    team_name = str_fname + " " + str_lname;
    return team_name;

}

#endif