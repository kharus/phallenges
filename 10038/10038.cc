#include<iostream>
#include<vector>
#include<algorithm>
#include <stdlib.h>

bool is_jolly(const std::vector<long>& jumpers);

int main() {
  long number_of_jumpers;
  std::vector<bool> solutions;

  while (std::cin>>number_of_jumpers) {
    if (number_of_jumpers > 1){
      std::vector<long> jumpers;
      for (int i=0; i<number_of_jumpers; i++){
	long jumper;
	std::cin>>jumper;
	jumpers.push_back(jumper);
      }
      solutions.push_back(is_jolly(jumpers));
    } else {
      long dispose;
      std::cin>>dispose;
      solutions.push_back(true);
    }
  }

  for (int i=0; i<solutions.size(); i++){
    if (solutions[i]){
      std::cout<<"Jolly"<<std::endl;
    } else {
      std::cout<<"Not jolly"<<std::endl;
    }
  }
}

bool is_jolly(const std::vector<long>& jumpers){
  std::vector<long> jumper_diffs;
  for(int i=0; i<jumpers.size()-1; i++){
    jumper_diffs.push_back(
        abs(
	    jumpers[i]-jumpers[i+1]));
  }

  std::sort(jumper_diffs.begin(), jumper_diffs.end());

  for(int i=1; i <= jumper_diffs.size(); i++){
    if (jumper_diffs[i-1] != i){
      return false;
    }
  }
  return true;
}
