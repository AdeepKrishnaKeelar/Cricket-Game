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
file_FirstName = open("Players_Names_First.txt","r")
file_LastName = open("Players_Names_Last.txt","r")

#Store the names in a default list and close existing files
firstnames = file_FirstName.readlines()
lastnames = file_LastName.readlines()
file_FirstName.close()
file_LastName.close()

#The names are in a list, strip them of the '\n' 
firstnames=[s.rstrip() for s in firstnames]
lastnames=[s.rstrip() for s in lastnames]

#Open the main file to have the data written into
file_writeNames = open("PlayersRandomGen.txt","w")

#Iterate 11 times for a combination using random and close file
while N != 0:
    file_writeNames.write(str(random.choice(firstnames)+' '+random.choice(lastnames)+'\n'))
    N -=1
file_writeNames.close()