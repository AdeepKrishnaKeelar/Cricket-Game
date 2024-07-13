"""

CricketV3 -- Python3 Edition
This is the entry and toss function for the game
Written in Bits and Pieces before clubbing everything together
Former versions removed, tried to minimize code

"""
#all imported valid libraries imported to be mentioned here
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

#main function
def main():
    game_startup()

if __name__ == "__main__":
    main()