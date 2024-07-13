'''
    In this piece of the game, 4 players will be playing against the System.
    4 players are randomly chosen, 2 batsmen and 2 bowlers.
    Their match play will be 'recorded' for no reference whatsoever.
    4 players can be either manually entered or System provided.
    First way by manually entering the names.
    Purpose of this game is to show switching of batsmen and bowlers and 
    the opponent teams players.
'''
# All Python libraries and modules entered here.
# ----------------------------------------------
import random
# -----------------------------------------------
Team={}
Computers_Team={}
toss = 0
Bat_flag = 0
Bowl_flag = 0

def ComputerTeam_set_up_team():
    n = 4
    file_FirstName = open("Players_Names_First.txt","r") #Read the names of the file
    firstnames = file_FirstName.readlines() #Saving all the names read in the form of a list
    file_FirstName.close() #Close file
    firstnames=[s.rstrip() for s in firstnames] #Remove the lines
    #Four names for the game
    while n!=0:
        #Here, PlayerFactor decides who should be batsmen and bowlers
        PlayerFactor=random.randrange(0,100)%2
        ComputerPlayerName=str(random.choice(firstnames)) #Picks the nth number chosen as the PlayerFactor
        Computers_Team[ComputerPlayerName]={}
        if PlayerFactor == 1:
            Computers_Team[ComputerPlayerName]["Designation"]="Batsman"
            Computers_Team[ComputerPlayerName]["Batsman_runs"]=0
        else:
            Computers_Team[ComputerPlayerName]["Designation"]="Bowler"
            Computers_Team[ComputerPlayerName]["Bowler_wickets"]=0
        n-=1
    print("System Team ---\n")
    print(Computers_Team)

def set_up_team(name,desg):
    Team[name]={}
    if desg == 1:
        Team[name]["Designation"]="Batsman"
        Team[name]["Batsman_runs"]=0
    else:
        Team[name]["Designation"]="Bowler"
        Team[name]["Bowler_wickets"]=0

def Details_take():
    for i in range(4):
        name = input('Enter the name of the player - ')
        desg = int(input('1 - Batsmen\n0 - Bowler\n'))
        set_up_team(name,desg)
    print("User Team --- \n")
    print(Team)

def AnnounceToss_result(Bat_flag):
    if(Bat_flag=="User"):
        print("Team User will be batting first")
    else:
        print("Team System will be batting first")

def Toss_function():
    print("Time for the toss!")
    TossFlag=True
    while TossFlag:
        try:
            UserToss=int(input("Enter toss - 1.Heads 0. Tails"))
            ComputerToss=random.randrange(0,100)%2
            if(UserToss==ComputerToss):
                ComputerToss=(lambda: 1, 0)[ComputerToss==0]()
            if(UserToss==(random.randrange(0,100)+(ComputerToss+UserToss)%2)):
                print("Congratulations, you have won the toss!")
                decision=int(input("1. Batting \n2. Bowling"))
                Bat_flag = "User" if decision == 1 else "System"
                AnnounceToss_result(Bat_flag)
                TossFlag=False

            else:
                print("The System has won the Toss!")
                decision=random.randrange(1,100)%2
                Bat_flag = "System" if decision == 2 else "User"
                AnnounceToss_result(Bat_flag)
                TossFlag=False

        except:
            print("Invalid Choice")
            TossFlag=True
    

Details_take()
ComputerTeam_set_up_team()
Toss_function()