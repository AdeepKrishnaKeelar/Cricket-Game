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
/* using namespace std; */
/* not using that to prove a point to some wannabe programmers. Going to take the harsh methods itself */

/* The classes I'm going to use ---
1. introduction_check is a class that takes in the basics.
    1.1. I guess, after it takes the name, it's going to set a list of options - Create team or Quick Play.
    Using file operations is essential now.  */
class introduction_check {
    /* All variables are declared here. */
    private:
        int introduction_check_details_option1, runs_total=0, wickets_total=0; /* damn that's one long variable name */
        std::string FirstName=""; /* Name of the person playing this dumbass game */
        std::string ImpFileName_One = "ImportantFile", ResultImportantFile=""; /* For the variables saving*/
        std::string TeamPlayer_name; /* For the team members and their positions*/
        std::fstream ImportantFile; /* This file will be used for writing stuff like team name and saving it. */
        std::map<std::string,std::map<int,int>> T; /* Map STL definition. Temperary definition, might change in case gets hard*/ 
        /* STL Map iterators */
        std::map<std::string,std::map<int,int>>::iterator itr; 
        std::map<int,int>::iterator ptr;

    /* All functions are declared here.*/
    public:
        //This function takes the name of the player playing this dumbass game.
        void TakeEntry_details() {
            std::cout<<"Welcome to Cricket!"<<std::endl; //All these are polite output lines.
            std::cout<<"Please enter your name to start: ";
            std::cin>>FirstName;
            std::cout<<"Thank you "<<FirstName<<std::endl;
            ResultImportantFile = ImpFileName_One + FirstName; //concatenating the strings for a procedure name file
            /*Resulting file name should be of format ImportantFile/NameofPerson/ 
            Like ImportantFileJohn, ImportantFileMadhava, blah blah */
            ImportantFile.open(ResultImportantFile.c_str(), std::ios::out); /*Using the open function to create a file
            with the name of the User so that their records will be saved.*/
            if(!ImportantFile) { //Checking if the operation is successful 
                std::cout<<"The records has failed!"<<std::endl; //rEcOrDs indeed
            }
            else {
                std::cout<<"The records have been opened!"<<std::endl; 
                ImportantFile << "Name - " << FirstName <<std::endl; //It writes into the file.
            }
            /* the starting conditional branching of the game */
            std::cout<<"Welcome to the Game "<<FirstName<<"!"<<std::endl;
            std::cout<<"What would you like to do?"<<std::endl;
            std::cout<<"1.Create your own team for all games\n2.Start Quick Play with System Team"<<std::endl;
            std::cin>>introduction_check_details_option1;
            ImportantFile.close(); //Once a file opened must be closed otherwise life becomes miserable.
        }
        /* This function will create the team given by the player. */
        void CreateTeam_byUser() { 
            int n=11; /* Eleven dummies in a team, right? */
            while(n!=0) {
                /* Input of all dummies */
                std::cin>>TeamPlayer_name;
                T.insert(make_pair(TeamPlayer_name,std::map<int,int>())); /* First you insert the name of the dummy*/
                T[TeamPlayer_name].insert(std::make_pair(runs_total,wickets_total)); /* Then you add their score tally */
                n--; /* Reduce the player's values otherwise it'll go to infinite loop */
            }
            ImportantFile.open(ResultImportantFile.c_str(), std::ios::out); /* Open the file */
            if(!ImportantFile) { /* In case of failure */
                        std::cout<<"Record failed to open!"<<std::endl;
            }
            else {
                for(itr=T.begin();itr!=T.end();itr++) {
                    for(ptr=itr->second.begin();ptr!=itr->second.end();ptr++) {
                        /* In this module, the contents are written into the file, their names and runs and wickets. */
                        /* Beauty of it is that it gets auto-sorted, love C++ */ 
                        ImportantFile << "Player "<<n<<": "<<itr->first<<" Runs: "<<ptr->first<<" Wickets: "<<ptr->second<<std::endl; 
                        n++; /* Player count increment*/
                    }
                }
            }
            ImportantFile.close(); /* Close the damn file otherwise someone will mess it up*/
        } 
};

/* Testing the main function regularly */
int main(void) {
    /*Here, the object for the first class is made. Since it's in development stage
    It's being called. Will check and inherit later. */
    introduction_check i;
    //calling the function
    i.TakeEntry_details();
    i.CreateTeam_byUser();
    return 0;
}
