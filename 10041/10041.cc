#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

int min_distance(vector<int>& addresses);

int main(){
  vector<int> results;
  int number_of_cases;
  cin>>number_of_cases;


  for(int i=1; i<=number_of_cases; i++){
    int number_of_relatives;
    vector<int> relatives_addresses;
    cin>>number_of_relatives;
    for(int n=1; n<=number_of_relatives; n++){
      int relative_address;
      cin>>relative_address;
      relatives_addresses.push_back(relative_address);
    }
    results.push_back(min_distance(relatives_addresses));
  }

  for(int i=0; i<number_of_cases; i++){
    cout<<results[i]<<endl;
  }
      
}

int min_distance(vector<int>& addresses){
  sort(addresses.begin(), addresses.end());
  int target_index = addresses.size()/2;
  int target_distance=0;
  for (int i=0; i<addresses.size(); i++){
    target_distance+=abs(addresses[i]-addresses[target_index]);
  }
  return target_distance;
}
  
