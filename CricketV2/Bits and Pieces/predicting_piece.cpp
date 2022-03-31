/* This program learns what the user inputs and tries to mimick their input */
// experiment to work for the game
//Credits to Laksh Shetty for the idea, yo awesome!
//I haven't the brains to think much mathematics
#include<iostream>
#include<map> //STL for MAP functions
#include<iterator> //STL Iterator
//not using the namespace, there's comments for it
int main(void) {
    std::map<int,int> system_array; //MAP STL with syntax map<datatype,datatype> map_variable_name
    std::map<int,int>::iterator it; //MAP STL iterator
    int dummy_score; //player's scores
    //MAP inserting values of predictable scores - 1 2 3 4 5 6
    // Discarding 0 as defence, only a duffer would be inserting his entire life
    system_array.insert(std::pair<int,int>(1,0)); 
    system_array.insert(std::pair<int,int>(2,0));
    system_array.insert(std::pair<int,int>(3,0));
    system_array.insert(std::pair<int,int>(4,0));
    system_array.insert(std::pair<int,int>(5,0));
    system_array.insert(std::pair<int,int>(6,0));
        do  {
            std::cin>>dummy_score; //reading player's scores
            for(it=system_array.begin();it!=system_array.end();++it) { //iterating in the map 
            //using pointer iterator and functions map.begin() and map.end()
                if(dummy_score==it->first) { //if entered score matches with first part of map ie key
                    it->second++; //then increment in second value
                }
            }
        }while(dummy_score!=-1);
        for(it=system_array.begin();it!=system_array.end();++it) { //checking if it is correct
            std::cout<<it->first<<"\t"<<it->second<<std::endl; // key, value printing
        }
        return 0;
    }