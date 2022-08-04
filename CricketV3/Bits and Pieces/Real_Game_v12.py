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
1.1. Game_Startup(): Function to take the name of the user and welcome him
1.2. Game_Toss(): Function to take up the toss. 
'''

'''
Class List --
---------------
1. BasicSetup: Here, in this class, the basic functions of toss and startup is done.
'''

class BasicSetup: 
    def __init__(self,name):
        global Game_User, System_User #Variable to keep User's Name and 
        self.Game_User=name
        self.System_User = "System" #Permanent Saving of System Name as System
        self.Game_Mode=0 #Variable to select Game Mode
        self.Game_User_Team={} #Dictionary to keep track of User's Team
        self.Computers_Team={} #Dictionary to keep track of Computer/System's Team
        self.Game_State={} #Dictionary to keep track of Games Batting and Bowling
        self.Toss_Choice=0 #Keeps track of who is Batting
        self.Later_Choice=0 #Keeps track of who is Bowling

    #Function to take the name of the user and welcome him
    #Function Game_startup() should also take which mode user wants to play in
    #GUI method to be added soon
    def Game_Startup(self):
        global Game_User,System_User
        print("Welcome to CricketV3!\n")
        print(self.Game_User,", Enter the mode of play!\n")
        #using a while loop until user enters something valid
        while True:
            self.Game_Mode=input("1.Versus System\n2.Watch a Game\n3.Multiplayer\n4.Tournament\n")
            #Exception handling for proper results
            try:
                self.Game_Mode=int(self.Game_Mode)
            except ValueError:
                #Incase of wrong entries
                print("Valid Entries please!\n")
                continue
            if self.Game_Mode>4 or self.Game_Mode<0:
                #incase of invalid numerical entries
                print("Valid entry please!\n")
            else:
                #incase of correct valid entry
                print(self.Game_User+", you've chosen option "+str(self.Game_Mode)+"\n")
                break

    def Game_Toss(self):
        global Game_User,System_User
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
            self.Toss_Choice=input("Do you chose to Bat or Bowl? ")
            self.Later_Choice= "Bowl" if self.Toss_Choice == "Bat" else "Bat" #Decision to choose who bats and who bowls
            print("Team ",self.Game_User," has decided to "+self.Toss_Choice+" and The System will "+self.Later_Choice)
            self.Game_State={self.Toss_Choice:self.Game_User,self.Later_Choice:self.System_User} #Setting the status of the games
        else: #Here the System wins the toss
            print("The System has won the choice")
            toss=random.randrange(0,10)%2
            self.Toss_Choice="Bat" if toss==1 else "Bowl"
            self.Later_Choice="Bowl" if self.Toss_Choice=="Bat" else "Bat"
            print("The System has decided to "+self.Toss_Choice+" and Team "+self.Game_User+" will "+self.Later_Choice)
            self.Game_State={self.Toss_Choice:self.System_User,self.Later_Choice:self.Game_User} #Setting the status of the games

def main(): #Definition of the main function
    name = input("Enter your name -- ")
    Obj = BasicSetup(name)
    Obj.Game_Startup()
    Obj.Game_Toss()
    print(Obj.Game_State)

if __name__ == "__main__": #Main()
    main()