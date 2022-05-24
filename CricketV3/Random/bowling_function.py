#This happens to be the bowling function of the game.
#Basic test case version built for chasing. 
#Additions will be made in due time.
import random
def print_score(sys_score,chase_score,wicket):
    print("Score: {} - {}".format(sys_score,wicket))
    print("{} runs to win in {} wickets!".format((chase_score-sys_score),(10-wicket)))

print("Alright, it is time to bowl!")
print("The System is ready! Are you?")
print("Invalid entering will cost you badly!")
main_score = random.randrange(100,200) #As this is a basic function, a random score is being placed
chase_score = main_score + 1
print("The Chasing Score is {}".format(chase_score))
wickets = 10
wicket = sys_score = 0
while(wickets != 0):
    print("The System is ready! Are you ready?\nBowl: ")
    ball = int(input())
    shot = random.randrange(0,7)
    if ball > 6:
        print("No Ball!")
        sys_score += 7
    
    if shot == ball:
        print("Out!")
        wicket += 1
        wickets -= 1
        print_score(sys_score,chase_score,wicket)
    elif shot != ball:
        sys_score += shot
        print_score(sys_score,chase_score,wicket)
    
    if(wicket == 10 or wickets == 0):
        print("Match Over!")
        print("You've won!")
        print("You've won by {} runs".format(main_score-sys_score))
        break
    elif (sys_score >= chase_score):
        print("Match Over!")
        print("You've lost!")
        print("You've lost by {} wickets".format(wickets))
        break
