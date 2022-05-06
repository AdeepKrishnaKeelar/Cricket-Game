/* Aim of this program is to randomly assign random names as players for the team 
   The names of the players are regardless, it is a secular team with all names.
   There is no gender, hence one must not be surprised to find female names in the
   team ;)  
   A semiversion using the Boost Libraries will be done soon! */
 #include<iostream>
 #include<fstream>
 #include<string>
 #include<random>
 #include<algorithm>
 #include<map>
/* not using namespaces, screw the team! */
 int main(int argc, char* args[]) {
     
     std::fstream fin;
     fin.open("Player_Names.txt",std::ios::in);
     
     return 0;
 }