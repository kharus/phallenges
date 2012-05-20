#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool finished = false;

bool is_a_solution(vector<int> a, int input){
  return (a.size()==input);
}

vector<int> construct_candidates(vector<int> a, int input){
  vector<int> result;
  for (int i=1; i<= input; i++)
    if ( find(a.begin(), a.end(), i) == a.end())
      result.push_back(i);
  return result;
}

void process_solution(vector<int> a){
  cout<<"{";
  for (int i = 0; i <a.size(); i++)
      cout<<" "<<a[i];
  cout<<" "<<"}"<<endl;
}

void backtrack(vector<int> a, int input){
  if (is_a_solution(a,input))
    process_solution(a);
  else {
    vector<int> candidates = construct_candidates(a,input);
    for (int i=0; i<candidates.size(); i++) {
      a.push_back(candidates[i]);
      backtrack(a,input);
      a.pop_back();
      if (finished) return;	/* terminate early */
    }
  }
}

int main(){
  vector<int> a;

  backtrack(a,3);
}

