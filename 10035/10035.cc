#ifndef ONLINE_JUDGE
#include "10035.h"
#endif

#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

bool is_carry(int x, int y, int carry){
  return (x+y+carry) > 9;
}

vector<int> split(int x){
  vector<int> result;
  do{
    result.push_back(x % 10);
    x = x/10;
  } while ( x > 0);
  return result;
}

void pad_vector(vector<int>& a, int size){
  for (int i=a.size(); i<size; i++){
    a.push_back(0);
  }
}

void pad_vectors(vector<int>& x, vector<int>& y){
  if ( x.size() > y.size() ){
    pad_vector(y, x.size() );
  } else if ( y.size() > x.size() ){
    pad_vector(x, y.size());
  }
}

int number_of_carries(int x, int y){
  vector<int> vector_x = split(x);
  vector<int> vector_y = split(y);
  int total_carries = 0;
  int carry = 0;

  pad_vectors(vector_x, vector_y);

  for (int i=0; i<vector_x.size(); i++){
    if (is_carry(vector_x[i], vector_y[i], carry)){
      total_carries++;
      carry = 1;
    } else {
      carry = 0;
    }
  }
  return total_carries;
}

string carries_message(int number_of_carries){
  stringstream oss;
  oss<<number_of_carries<<" carry operations.";
  return oss.str();
}

string result_message(int number_of_carries){
  switch (number_of_carries) {
  case 0: return "No carry operation.";
  case 1: return "1 carry operation.";
  default: return carries_message(number_of_carries);
  }
}

#ifdef ONLINE_JUDGE
int main(){
  int x,y;
  vector<string> results;

  cin>>x>>y;
  while ( x+y > 0){
    results.push_back(
		      result_message(
				     number_of_carries(x,y)));
    cin>>x>>y;
  }
  
  for (int i=0; i<results.size(); i++){
    cout<<results[i]<<endl;
  }
}
#endif
