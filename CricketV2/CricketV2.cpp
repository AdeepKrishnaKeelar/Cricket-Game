/*This is the Beloved Cricket Game taking a new form.
Here, more updates are added to the C version of the game
Lot of new features and updates.
Preferably tested using Linux, coded on the VS-Code Editor for ease. */
//The header files list 
#include<iostream> //Standard C++ Input-Output Stream Header
#include<string> //For all those string functions I think I'm going to add
#include<fstream> //For all the file operations I think I'm going to do
#include<vector> //I think I may use vectors somewhere
#include<algorithm> //Need this for...stuff.
#include<map> //Map STL for name, run tally.
#include<bits/stdc++.h> //Standard C++ header file containing all the header files, looks neat
//using namespace std;
//not using that to prove a point to some wannabe programmers. Going to take the harsh methods itself

/* The classes I'm going to use ---
1. introduction_check is a class that takes in the basics.
    1.1. I guess, after it takes the name, it's going to set a list of options - Create team or Quick Play.
    Using file operations is essential now.  */
class introduction_check {
    private:
        std::string FirstName; //Name of the person playing this dumbass game
        std::fstream ImportantFile; //This file will be used for writing stuff like team name and saving it.

    public:
        //This function takes the name of the player playing this dumbass game.
        void TakeEntry_details() {
            std::cout<<"Welcome to Cricket!"<<std::endl; //All these are polite output lines.
            std::cout<<"Please enter your name to start: ";
            std::cin>>FirstName;
            std::cout<<"Thank you "<<FirstName<<std::endl;
        }
        //Testing file operations now in a function.
        void WritingIntoFile_StartingDetails() {
            ImportantFile.open("ImportantFile.txt", std::ios::out); /*Using the open function to create a text
            file called ImportantFile.txt with mode ios::out to write into it*/
            if(!ImportantFile) { //Checking if the operation is successful 
                std::cout<<"The records has failed!"<<std::endl; //rEcOrDs indeed
            }
            else {
                std::cout<<"The records have been opened!"<<std::endl; 
                ImportantFile << "Name - " << FirstName <<std::endl; //It writes into the file.
                ImportantFile.close(); //Once a file opened must be closed otherwise life becomes miserable.
            }
        } 

};

//Testing the main function regularly
int main(void) {
    //Here, the object for the first class is made. Since it's in development stage
    //It's being called. Will check and inherit later.
    introduction_check i;
    //calling the function
    i.TakeEntry_details();
    i.WritingIntoFile_StartingDetails();
    return 0;
}
