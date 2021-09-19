#defining the Batting Function, first a trail version! 
import random
def show_score(main_score,wicket):
    print("The score is %d - %d" %(main_score, wicket))
print("Are you ready to bat?")
print("Invalid shots will cost you wickets")
main_score = wicket = 0
wickets = 10
while wickets!=0:
    print("The bowler is ready!")
    print("Play the shot: ")
    ball = random.randrange(0,7)
    shot = int(input())
    if shot == ball:
        print("Out!")
        wickets-=1
        wicket+=1
        show_score(main_score,wicket)
    elif shot>6: 
        print("Invalid shot!")
        print("And it's caught!")
        wickets-=1
        wicket+=1
        show_score(main_score,wicket)
    else:
        main_score += shot
        show_score(main_score,wicket)

if wicket==10 or wickets==0:
    show_score(main_score,wicket)

