"""
CricketV3 --- A Game built on Python!
-------------------------------------
"""
#The main body of the program is built here --
#The Game Play against the system is set here in this program.
#A minimalistic version of the code is set here.

#All libraries are set here.
#Start
import random
import time
#End

"""
Classes for number generators --
1. Random Generation using Rand 
2. Random Generation using time() function
3. 
"""
class Random_Generators_One:
    #Defining the random generator function using random library
    def Generator_One(self):
        Number=random.randint(0,7)
        return Number
    
    #Defining the random generator function using time library
    #This is a slower defination of random number generation but need number generators
    def Random_Generators_Two(self):
        randomTime_Gen= time.time()
        randomTime_Gen=int(str(randomTime_Gen-int(randomTime_Gen))[2:])%7
        return randomTime_Gen

    #Defining the random generator function using a mixture of binary functions and rand
    
class Game_Play:
    pass