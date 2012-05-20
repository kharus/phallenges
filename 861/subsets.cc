#include<iostream>
#include<vector>

using namespace std;

bool finished = false;

bool is_a_solution(vector<int> a, int input){
  return (a.size()==input);
}

vector<int> construct_candidates(vector<int> a, int input){
  vector<int> result;
  result.push_back(true);
  result.push_back(false);
  return result;
}

void process_solution(vector<int> a){
  cout<<"{";
  for (int i = 0; i <a.size(); i++)
    if (a[i])
      cout<<" "<<i+1;
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

