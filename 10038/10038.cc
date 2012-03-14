#include<iostream>
#include<vector>

int main() {
  long number_of_jumpers;

  while (std::cin>>number_of_jumpers) {
    if (number_of_jumpers > 1){
      std::vector<long> jumpers;
      for (int i=0; i<number_of_jumpers; i++){
	long jumper;
	std::cin>>jumper;
	jumpers.push_back(jumper);
      }
    }
    std::cout << number_of_jumpers << std::endl;
  }
}

bool is_jolly(const &vector<long> jumpers){
  jumpers.
