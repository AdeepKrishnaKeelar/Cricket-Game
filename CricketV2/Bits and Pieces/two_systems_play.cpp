/* This piece is set to allow two systems play amongst themselves */
#include<iostream>
#include<random> /* For the mt19937 engine */
#include<iterator>
#include<map>
#include<algorithm>
#include<chrono>
#include<stdlib.h>
#include<time.h>
/* Global defination of the Mersenne Twister Random Engine */
unsigned number = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(number);

class Game_play {
    /* List of variables */
    private:
        const std::string sys1 = "Rand System"; /* A const string as a name for sys1, that is the
        Random Function using seed function Srand() */
        const std::string sys2 = "Mersenne Twister System"; /* A const string as a name for sys2, that
        is the Mersenne Twister Engine from the random header file */
        int s1_toss_choice, s2_toss_choice, gen_toss, toss_flag;
        int s1_batting_score, s2_batting_score;
        int s1_wickets, s2_wickets;
        int sample_score, shot, ball;
        int game_flag, batting_flag, bowling_flag;
        const int system_one = 1, system_two = 2; 
        const int batting_choice=1, bowling_choice=0;

    /* All functions are mentioned here */
    public:
        Game_play() {
            s1_toss_choice=0;
            s1_batting_score=0;
            s1_wickets=0;
            s2_batting_score=0;
            s2_toss_choice=0;
            s2_wickets=0;
            toss_flag=0;
            game_flag=0;
            batting_flag=0;
            bowling_flag=0;
            srand(time(0)); /* The rand function is set up here */
            gen_toss = rand()%2 && (generator()% 2);
        }
        
        void toss_play() {
            std::cout<<sys1<<" V/S "<<sys2<<std::endl;
            std::cout<<"The systems are setting up the toss!"<<std::endl;
            s1_toss_choice = rand()%2;
            std::cout<<sys1<<" has called "<<s1_toss_choice<<std::endl;
            s2_toss_choice = generator()%2;
            std::cout<<sys2<<" has called "<<s2_toss_choice<<std::endl;
            try {
                if(s1_toss_choice == s2_toss_choice) {
                    std::cout<<"Both cannot call the same!"<<std::endl;
                    throw s2_toss_choice;
                }
            }
            catch(int s2_toss_choice) {
                s2_toss_choice = ~(s2_toss_choice);
            }
            gen_toss==s1_toss_choice? toss_flag = system_one : toss_flag = system_two; 
            if(toss_flag==1) {
                std::cout<<sys1<<" has won the toss!"<<std::endl;
                s1_toss_choice = rand()%2 && (generator()% 2);
                if(s1_toss_choice==1) {
                    std::cout<<sys1<<" has decided to bat first!"<<std::endl;
                    batting_flag = system_one;
                    bowling_flag = system_two;
                }
                else {
                    std::cout<<sys1<<" has decided to bowl first!"<<std::endl;
                    batting_flag = system_two;
                    bowling_flag = system_one;
                }
            } else {
                std::cout<<sys2<<" has won the toss!"<<std::endl;
                s2_toss_choice = rand()%2 && (generator()% 2);
                if(s2_toss_choice==1) {
                    std::cout<<sys2<<" has decided to bat first!"<<std::endl;
                    batting_flag = system_two;
                    bowling_flag = system_one;
                }
                else {
                    std::cout<<sys2<<" has decided to bowl first!"<<std::endl;
                    batting_flag = system_one;
                    bowling_flag = system_two;
                }
            } 
        }  
};
int main(int argc, char* argv[]) {
    Game_play GP;
    GP.toss_play();
}