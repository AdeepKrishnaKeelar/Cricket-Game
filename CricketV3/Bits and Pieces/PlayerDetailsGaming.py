'''
    In this piece of the game, 4 players will be playing against the System.
    4 players are randomly chosen, 2 batsmen and 2 bowlers.
    Their match play will be 'recorded' for no reference whatsoever.
    4 players can be either manually entered or System provided.
    First way by manually entering the names.
'''
# All Python libraries and modules entered here.
# ----------------------------------------------
import random
# -----------------------------------------------
Team={}
toss = 0
def set_up_team(name,desg):
    Team[name]={}
    if desg == 1:
        Team[name][desg]="Batsman"
        Team[name]["batsman_runs"]=0
    else:
        Team[name][desg]="Bowler"
        Team[name]["bowler_wickets"]=0

def details_take():
    for i in range(4):
        name = input('Enter the name of the player - ')
        desg = int(input('1 - Batsmen\n0 - Bowler\n'))
        set_up_team(name,desg)
    print(Team)



details_take()