import random
def print_decision(decision):
    if decision == 1:
        print("Decision is to bat!")
    elif decision == 0:
        print("Decision is  to bowl!")
    else:
        print("Invalid call")
        decision = random.randrange(0,2)
        print_decision(decision)

toss=int(input("It's time for the toss!1 for Heads/0 for Tails "))
coin = random.randrange(0,2)
if toss == coin:
    print("The coin fell at ",coin);
    print("You've won!")
    flag = 1
else:
    print("The coin fell at ",coin);
    print("You've lost!")
    flag = 0

#defining the status of player's fate
if flag == 1:
    print("Congratulations, you've won the toss!")
    print("What do you wish to do? 1 for Batting/0 for Bowling ")
    decision = int(input())
    print_decision(decision)
else:
    print("Alas, the System has won the toss!")
    print("What is the system going to do?")
    decision = random.randrange(0,2)
    print_decision(decision)


