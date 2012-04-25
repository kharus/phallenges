#ifndef ONLINE_JUDGE
#include "10138.h"
#endif

#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

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

vector<int> convert(std::string number){
  vector<int> result;
  for (int i = 0; i < number.size(); i++){
    result.push_back(number[i] - '0');
  }
  reverse(result.begin(), result.end());
  return result;
}

vector<int> add(vector<int> x, vector<int> y){
  int total_carries = 0;
  int carry = 0;
  vector<int> result;

  pad_vectors(x, y);

  
  for (int i=0; i<x.size(); i++){
    int sum = x[i]+y[i]+carry;
    if (sum>9){
      sum-=10;
      carry = 1;
    } else {
      carry = 0;
    }
    result.push_back(sum);
  }

  if ( carry == 1 ){
    result.push_back(1);
  }

  return result;
}

int comp(const vector<int>& x, const vector<int>& y){
  if ( x.size() > y.size() )
    return 1;
  else if ( y.size() > x.size() )
    return -1;

  for (int i=(x.size()-1); i>=0; i--){
    if ( x[i] > y[i] )
      return 1;
    else if ( y[i] > x[i] )
      return -1;
  }

  return 0;
}

typedef vector< vector<int> > fib_seq;

fib_seq fib_table(int max){
  vector<int> one(1,1);
  vector<int> two(1,2);
  vector< vector<int> > result;

  result.push_back(one);
  result.push_back(two);

  for(int i = 2; i <= max; i++){
    result.push_back(
		     add(result[i-1], result[i-2]));
  }
  return result;
}

int find_below_index(fib_seq& sequence, vector<int> target){
  int i = 0;
  while ( comp(sequence[i], target) < 1)
    i++;
  return i-1;
}
  
int find_above_index(fib_seq& sequence, vector<int> target){
  int i = 0;
  while ( comp(sequence[i], target) < 0)
    i++;
  return i;
}
  
int numbers_in_interval(fib_seq& sequence, vector<int> low, vector<int> high){
  int low_index = find_above_index(sequence, low);
  int high_index = find_below_index(sequence, high);
  return high_index-low_index+1;
}
    

#ifdef ONLINE_JUDGE
int main(){
  string x,y;
  vector<int> results;
  fib_seq sequence = fib_table(481);
  
  cin>>x>>y;
  while ( x+y != "00" ){
    results.push_back(
		      numbers_in_interval(sequence, convert(x), convert(y)));
    cin>>x>>y;
  }
  
  for (int i=0; i<results.size(); i++){
    cout<<results[i]<<endl;
  }
}
#endif
