"""

CricketV3 -- Python3 Edition
This is the entry and toss function for the game
Written in Bits and Pieces before clubbing everything together
Former versions removed, tried to minimize code

"""
#all modules imported to be mentioned here
#start



#end

#global variables 
Game_User=" "
Game_Mode=0
#function to take the name of the user and welcome him
#function game_startup() should also take which mode user wants to play in
#GUI method to be added soon
def game_startup():
    print("Welcome to CricketV3!\n")
    Game_User=input("Enter the User Name:- ")
    flag = True
    while flag != False:
        try:
            Game_Mode=(Game_User+", enter the Game-Mode-\n1.Play Against System\n2.Multiplayer\n3.Tournament")
            if int(Game_Mode) > 3:
                raise Exception("Please enter valid option!")
        finally:
            print("Everything is taken!")
            flag = False


def main():
    game_startup()

if __name__ == "__main__":
    main()