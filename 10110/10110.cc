#ifndef ONLINE_JUDGE
#include "10110.h"
#endif

#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

bool check_bulb(unsigned long length){
  unsigned long root = sqrt(length);
  return root*root == length;
}


#ifdef ONLINE_JUDGE
int main(){
  unsigned long input;
  vector<bool> results;
   
  cin>>input;
  while ( input != 0 ){
    results.push_back(
		      check_bulb(input));
    cin>>input;
  }
  
  for (int i=0; i<results.size(); i++){
    if (results[i])
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
}
#endif
