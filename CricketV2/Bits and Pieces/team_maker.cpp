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
    std::string line; 
    /* ifstream: Stream class to read from files */
    std::ifstream firstNames_file("Player_Names.txt");
    std::ifstream lastNames_file("Players_Names_Last.txt");
    /* try-catch exception block */
    try {
      /* if file fails to open, throw a value to the catch statement */
      if(!firstNames_file.is_open() && !lastNames_file.is_open()) {
        throw 1;
      } else {
        /* reading the contents of the names of the files. */
        while(getline(firstNames_file,line)) {
          std::cout<<line<<std::endl;
        }
        while(getline(lastNames_file,line)) {
          std::cout<<line<<std::endl;
        }
        firstNames_file.close();
        lastNames_file.close();
      }
    } catch(int n) {
      /* when confirmed file failed to open! */
      std::cout<<"Failed to open file!"<<std::endl;
    }    
    return 0;
 }