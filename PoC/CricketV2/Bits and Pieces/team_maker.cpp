/* Aim of this program is to randomly assign random names as players for the team 
   The names of the players are regardless, it is a secular team with all names.
   There is no gender, hence one must not be surprised to find female names in the
   team ;)  
   A semiversion using the Boost Libraries will be done soon! */
 #include<iostream>
 #include<fstream>
 #include<string>
 #include<random>
 #include<chrono>
 /* Global variables */
 unsigned number=std::chrono::system_clock::now().time_since_epoch().count();
 /* Global file pointers for easy reference */
 /* ifstream: Stream class to read from files */
 std::string file1="Player_Names.txt";
 std::string file2="Players_Names_Last.txt";
 std::ifstream firstNames_file(file1.c_str());
 std::ifstream lastNames_file(file2.c_str());
 int FirstName_SizeDetector() {
      int count=0;
      std::string l;
      try {
        if(!firstNames_file.is_open()) {
          throw 1;
        } else {
          while(firstNames_file.peek()!=EOF) {
            getline(firstNames_file,l);
            count++;
          }
          firstNames_file.close();
        }
      } catch(int n) {
        std::cout<<"File failed to open!"<<std::endl;
      }
      return count;
  }
  int LastName_SizeDetector() {
      int count=0;
      std::string l;
      try {
        if(!lastNames_file.is_open()) {
          throw 1;
        } else {
          while(lastNames_file.peek()!=EOF) {
            getline(lastNames_file,l);
            count++;
          }
          lastNames_file.close();
        }
      } catch(int n) {
        std::cout<<"File failed to open!"<<std::endl;
      }
      return count;
  }
 
 class team_maker {
  private:
      std::string line;
      int FirstName_size, LastName_size;
  public:
    team_maker() {
      FirstName_size=FirstName_SizeDetector();
      LastName_size=LastName_SizeDetector();
      std::cout<<FirstName_size<<" "<<LastName_size<<std::endl;
    }
    void check_file() {
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
  }
  std::string Read_First_Name(int N) {
    std::string s;
    for(int i=0;i<N;i++) {
      getline(firstNames_file,s);
    }
    std::cout<<s;
    return s;
    /*char firstName[FirstName_size][N];
    int a=0;
    while((a<N)&&firstNames_file.getline(firstName[a][N])) {
      ++a;
    }
    return firstName[a][N]; */
  }
  std::string Read_Last_Name(int M) {
    std::string s;
    for(int i=0;i<M;i++) {
      getline(lastNames_file,s);
    }
    std::cout<<s;
    return s;
  }
  /* Function generates the random team names */
  void generateTeamNames() {
    /* Setting up mt19337 engine */
    std::mt19937 generator(number);
    /* ofstream: Stream class to write on files */
    std::ofstream Player_Team;
    int team_size=11;
    std::cout<<"Let the System decide your team!"<<std::endl;
    Player_Team.open("Players_Team.txt");
    while(team_size!=0) {
      int n,m;
      std::string first, last, combo;
      n=generator()%FirstName_size;
      m=generator()%LastName_size;
      std::cout<<n<<" "<<m<<std::endl;
      first=Read_First_Name(n);
      last=Read_Last_Name(m);
      std::cout<<first<<std::endl;
      std::cout<<last<<std::endl;
      combo=first+" "+last;
      std::cout<<combo<<std::endl;
      Player_Team << combo <<std::endl;
      team_size--;
    }
    Player_Team.close();
  }
 };
 int main(int argc, char* args[]) {
   team_maker t;
   t.generateTeamNames();
   return 0;
 }