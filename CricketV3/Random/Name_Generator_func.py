"""
CricketV3 --- The Python version
"""
#This script is the random Name Generator
#A brute force approach to generate random names for the team
#All names are stored in a file
#Imported libraries list --
#start
from ntpath import join
import random #random library
#end
N=11 #11 Players in a Team
#Read the names of the file
file = open("Players_Names_First.txt","r")
file2 = open("Players_Names_Last.txt","r")

#Store the names in a default list
firstnames = file.readlines()
lastnames = file2.readlines()

#The names are in a list, strip them of the '\n' 
firstnames=[s.rstrip() for s in firstnames]
lastnames=[s.rstrip() for s in lastnames]

#Iterate 11 times for a combination using random
while N != 0:
    print(random.choice(firstnames)+' '+random.choice(lastnames))
    N -=1