/* This piece is set to allow two systems play amongst themselves */
#include<iostream>
#include<random> /* For the mt19937 engine */
#include<iterator>
#include<map>
#include<algorithm>
#include<chrono>
#include<stdlib.h>
#include<time.h>
#include<thread> /* sleep functions */
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
        int chase_score=0;
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
            chase_score=0;
            batting_flag=0;
            bowling_flag=0;
            srand(time(0)); /* The rand function is set up here */
            gen_toss = rand()%2 && (generator()% 2);
        }
        
        /* In this function, the toss is decided between the two teams. */
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

        int bat() {
            int shot=0;
            switch(batting_flag) {
                case 1: shot=rand()%7;
                        break;
                case 2: shot=(generator()%7);
                        break;
                default: shot=-1;   
            }
            return shot;
        }

        int bowl() {
            int ball=0;
            switch(bowling_flag) {
                case 1: ball=rand()%7;
                        break;
                case 2: ball=(generator()%7);
                        break;
                default: ball=-1;   
            }
            return ball;
        }

        void update_score(int shot, int wicket) {
            switch(batting_flag) {
                case 1: s1_batting_score+=shot;
                        s1_wickets=wicket;
                        break;
                case 2: s2_batting_score+=shot;
                        s2_wickets=wicket;
                        break;   
            }
        }

        void summarise_details(std::string batsman) {
            switch(batting_flag) {
                case 1: std::cout<<"Details of Team "<<batsman<<std::endl;
                        std::cout<<"Score - "<<s1_batting_score<<" - "<<s1_wickets<<std::endl;
                        break;
                case 2: std::cout<<"Details of Team "<<batsman<<std::endl;
                        std::cout<<"Score - "<<s2_batting_score<<" - "<<s2_wickets<<std::endl;
                        break;   
            }
        }

        
        void batting_play() {
            int shot=0, ball=0, wicket=0;
            std::string batsman, bowler;
            toss_play();          
            if(batting_flag==1) {
                std::cout<<sys1<<" has begun it's play! "<<std::endl;
                std::cout<<sys2<<" is bowling against "<<sys1<<std::endl;
                batsman=sys1;
                bowler=sys2;

            } else {
                std::cout<<sys2<<" has begun it's play! "<<std::endl;
                std::cout<<sys1<<" is bowling against "<<sys2<<std::endl;
                batsman=sys2;
                bowler=sys1;
            }

            /* The scoring starts here */
                for(int i=0;i<120;i++) {
                    if(wicket!=10) {
                    shot=bat();
                    ball=bowl();
                    std::cout<<"Summary of "<<(i+1)<<" -- "<<std::endl;
                    if(shot==ball) {
                        std::cout<<"The player is out!"<<std::endl;
                        wicket+=1;
                    } else {
                        std::cout<<batsman<<" has scored "<<shot<<" runs "<<std::endl;
                        update_score(shot,wicket);
                        summarise_details(batsman);
                    }
                    std::this_thread::sleep_for(std::chrono::nanoseconds(10)); /* A delay function */
                }
            }
        }
        
};
int main(int argc, char* argv[]) {
    Game_play GP;
    GP.batting_play();
}