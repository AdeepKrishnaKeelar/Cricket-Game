"""

    CricketV3 -- Python3 Edition
    This is the entry and toss function for the game
    Written in Bits and Pieces before clubbing everything together
    Former versions removed, tried to minimize code.

    In this piece of the game, 4 players will be playing against the System.
    4 players are randomly chosen, 2 batsmen and 2 bowlers.
    Their match play will be 'recorded' for no reference whatsoever.
    4 players can be either manually entered or System provided.
    First way by manually entering the names.
    Purpose of this game is to show switching of batsmen and bowlers and 
    the opponent teams players.

"""
# All Python libraries and modules entered here.
# ----------------------------------------------
import random
import numpy #Numpy library for numbers
import matplotlib #For the graphical representation
# -----------------------------------------------

'''
Functions List --
---------------
1. Game_Startup(): Function to take the name of the user and welcome him
2. Game_Toss(): Function to take up the toss. 
'''

#Universal variables 
#-------------------------------------------
class Basic_GamePlay:
    global Game_User #Variable to keep User's Name
    global System_User #Permanent Saving of System Name as System
    System_User = "System"
    Game_Mode=0 #Variable to select Game Mode
    Game_User_Team={} #Dictionary to keep track of User's Team
    Computers_Team={} #Dictionary to keep track of Computer/System's Team
    Game_State={} #Dictionary to keep track of Games Batting and Bowling
    Toss_Choice=0 #Keeps track of who is Batting
    Later_Choice=0 #Keeps track of who is Bowling
    #ends here ---------------------------------

    #Function to take the name of the user and welcome him
    #Function Game_startup() should also take which mode user wants to play in
    #GUI method to be added soon
    def Game_Startup():
        global Game_User,System_User
        print("Welcome to CricketV3!\n")
        print(Game_User+", Enter the mode of play!\n")
        #using a while loop until user enters something valid
        while True:
            Game_Mode=input("1.Versus System\n2.Watch a Game\n3.Multiplayer\n4.Tournament\n")
            #Exception handling for proper results
            try:
                Game_Mode=int(Game_Mode)
            except ValueError:
                #Incase of wrong entries
                print("Valid Entries please!\n")
                continue
            if Game_Mode>4 or Game_Mode<0:
                #incase of invalid numerical entries
                print("Valid entry please!\n")
            else:
                #incase of correct valid entry
                print(Game_User+", you've chosen option "+str(Game_Mode)+"\n")
                break

    def Game_Toss():
        #global Game_User,System_User
        try:
            #Try catch to make sure User uses valid input
            UserToss=int(input("Enter the toss: 1.Heads \n0. Tails\n"))
        except:
            #Exceptions
            print("Invalid Entry") 
        SystemToss=random.random() #Here, System picks some random value for its toss
        #Rather a biased approach, System must remember who is superior 
        if UserToss>SystemToss:
            print("You have won the toss!")
            Toss_Choice=input("Do you chose to Bat or Bowl? ")
            Later_Choice= "Bowl" if Toss_Choice == "Bat" else "Bat" #Decision to choose who bats and who bowls
            print("Team ",Game_User," has decided to "+Toss_Choice+" and The System will "+Later_Choice)
            Game_State={Toss_Choice:Game_User,Later_Choice:System_User}
        else: #Here the System wins the toss
            print("The System has won the choice")
            Toss_Choice=random.randrange(0,2)
            if(Toss_Choice==1):
                Toss_Choice="Bat"
                Later_Choice="Bowl"
            else:
                Toss_Choice="Bowl"
                Later_Choice="Bat"
            print("The System has decided to "+Toss_Choice+" and Team "+Game_User+" will "+Later_Choice)
            Game_State={Toss_Choice:System_User,Later_Choice:Game_User}

#main function
def main():
    Obj = Basic_GamePlay()
    Obj.Game_Startup()
    Obj.Game_Toss()


if __name__ == "__main__":
    main()
    