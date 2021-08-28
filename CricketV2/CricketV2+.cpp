#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(void) {
    string name;
    int n=10;
    int num;
    map<string, int> m;
    do {
       cin>>name;
       cin>>num;
       m.insert(pair<string,int>(name,num));
       n-=1;
    }while(n!=0);
    cout<<endl<<"Name\tNumber "<<endl;
    for(auto itr = m.begin(); itr!=m.end(); ++itr) {
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }
    return 0;
}
