/*This is the Beloved Cricket Game taking a new form.
Here, more updates are added to the C version of the game
Lot of new features and updates.
Preferably tested using Linux, coded on the VS-Code Editor for ease. */
//The header files list 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>

//using namespace std;
//not using that to prove a point to some wannabe programmers. Going to take the harsh methods itself

/* The classes I'm going to use ---
1. introduction_check is a class that takes in the basic details. */
class introduction_check {
    private:
        std::string FirstName;
    public:
        //This function takes the name of the player playing this dumbass game.
        void TakeEntry_details() {
            std::cout<<"Welcome to Cricket!"<<std::endl;
            std::cout<<"Please enter your name to start: ";
            std::cin>>FirstName;
            std::cout<<"Thank you "<<FirstName<<std::endl;
        }
};

//Testing the main function regularly
int main(void) {
    //Here, the object for the first class is made. Since it's in development stage
    //It's being called. Will check and inherit later.
    introduction_check i;
    //calling the function
    i.TakeEntry_details();
    return 0;
}
