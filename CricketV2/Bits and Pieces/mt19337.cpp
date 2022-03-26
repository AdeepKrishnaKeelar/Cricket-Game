/* Program to demonstrate the working the mt19937 random engine */
#include<iostream>
#include<random>
#include<chrono> // providing clocks 
int main(void) {
    unsigned number = std::chrono::system_clock::now().time_since_epoch().count();
    int n;
    std::mt19937 generator (number);
    std::cin>>n;
    while(n!=0) {
    std::cout<<(generator()%1000)<<std::endl;
    n--;
    }
    return 0;
}