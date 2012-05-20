#include<cstdlib>
#include<cmath>
#include<set>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<complex>

using namespace std;

typedef complex<int> square;

struct classcomp {
  bool operator() (const square& lhs, const square& rhs) const{
  if (lhs.real() == rhs.real())
    return lhs.imag()<rhs.imag();
  else
    return lhs.real()<rhs.real();
  }
};

typedef set<square, classcomp> square_set;

bool is_under_attack(vector<int> board_setup, const int position){
  return true;
}

bool is_square_in_board(square point, int board_size){
  return
    point.real() > 0 &&
    point.imag() > 0 &&
    point.real() <= board_size &&
    point.imag() <= board_size;
}

int initial_d(square point, int a, int board_size){
  int b = point.imag()-a*point.real();
  int x0 = (a==1) ? 1-b : b-board_size;

  return point.real() - max(1,x0);
}

square_set attacked_diagonal(square point, int direction, int board_size){
  square_set result;

  int initial = initial_d(point, direction, board_size);
  square step(1, direction);
  square attacked_square = point - step*initial;
  for (int i=0; is_square_in_board(attacked_square + step*i, board_size); i++){
    result.insert(attacked_square + step*i);
  }
  return result;
}

square_set attacked_squares(square point, int board_size){
  square_set result;

  square_set asc_diag = attacked_diagonal(point, 1, board_size);
  result.insert(asc_diag.begin(), asc_diag.end());
  
  square_set desc_diag = attacked_diagonal(point, -1, board_size);
  result.insert(desc_diag.begin(), desc_diag.end());

  return result;
}

square_set clear_board(int shift, int board_size){
  square_set result;
  for (int i = 1; i<= board_size; i++){
    for (int j = 1 + (shift ^ (i+1)%2); j<= board_size; j+=2){
      result.insert(square(i, j));
    }
  }
  return result;
}

square_set unattacked_board(square_set bishops, int shift, int board_size){
  square_set result = clear_board(shift, board_size);
  square_set::iterator bishop;
  square_set::iterator attacked_square;
  for(bishop = bishops.begin(); bishop != bishops.end(); bishop++){
    square_set attacked_squaresb = attacked_squares(*bishop, board_size);
    for(attacked_square = attacked_squaresb.begin(); attacked_square != attacked_squaresb.end(); attacked_square++){
      result.erase(*attacked_square);
    }
  }
  return result;
}

square_set construct_candidates(square_set a, int input){
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
