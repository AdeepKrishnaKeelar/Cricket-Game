/* This program learns what the user inputs and tries to mimick their input */
// experiment to work for the game
//Credits to Laksh Shetty for the idea, yo awesome!
//I haven't the brains to think much mathematics
#include<iostream>
#include<map> //STL for MAP functions
#include<iterator> //STL Iterator
#include<random> //for the mersenne twister engine 
#include<chrono> //time 
//not using the namespace, there's comments for it
int generator() {
    unsigned number = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(number);
    return generator(number%2);
}
int main(void) {
    std::map<int,int> system_array; //MAP STL with syntax map<datatype,datatype> map_variable_name
    std::map<int,int>::iterator it; //MAP STL iterator
    int dummy_score, learning_variable = 12, flag=0; //player's scores
    unsigned number = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned num = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(number), generator1(num); 
    //MAP inserting values of predictable scores - 1 2 3 4 5 6
    // Discarding 0 as defence, only a duffer would be inserting his entire life
    system_array.insert(std::pair<int,int>(1,0)); 
    system_array.insert(std::pair<int,int>(2,0));
    system_array.insert(std::pair<int,int>(3,0));
    system_array.insert(std::pair<int,int>(4,0));
    system_array.insert(std::pair<int,int>(5,0));
    system_array.insert(std::pair<int,int>(6,0));
    /*  do  {
        std::cin>>dummy_score; //reading player's scores
        for(it=system_array.begin();it!=system_array.end();++it) { //iterating in the map 
        //using pointer iterator and functions map.begin() and map.end()
            if(dummy_score==it->first) { //if entered score matches with first part of map ie key
                it->second++; //then increment in second value
            }
        }
    }while(dummy_score!=-1); */
        
    do {
        std::cin>>dummy_score;
        for(it=system_array.begin();it!=system_array.end();++it) { //iterating in the map 
        //using pointer iterator and functions map.begin() and map.end()
            if(dummy_score==it->first) { //if entered score matches with first part of map ie key
                it->second++; //then increment in second value
            }
        }
        learning_variable-=1;
    }while(learning_variable!=0);    
        
/*    for(it=system_array.begin();it!=system_array.end();++it) { //checking if it is correct
        std::cout<<it->first<<"\t"<<it->second<<std::endl; // key, value printing
    } */
    
    // std::cout<<"The computer has learnt a little about your strategy!";
    
    do {
        int decision_variable=0, computer_variable=0;
        std::cin>>dummy_score;
        decision_variable = generator();
        if(decision_variable==0) {
            computer_variable = generator1(num%7);
        }
        else {
            for(it=system_array.begin();it!=system_array.end();++it) {
                auto x = std::max_element(system_array.begin(),system_array.end(),[](const pair<int,int>&p1, const pair<int,int>&p2)) {
                    return p1.second < p2.second; });
                }  
            }
        }
        
    }while(flag!=1);
    
    return 0;
}