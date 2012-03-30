#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

string convert(const string& original);
map<char,char> get_conversion_table();

int main(){
  string line;
  vector<string> results;
  
  do {
    getline(cin, line);
    results.push_back(convert(line));
  } while (!line.empty());

  results.pop_back();

  for(int i=0; i<results.size(); i++){
    cout<<results[i]<<endl;
  }
}

string convert(const string& original){
  string result;
  map<char,char> conversion_table = get_conversion_table();

  for(int i=0; i<original.size(); i++){
    if (conversion_table.count(original[i])==1){
      result.push_back(conversion_table[original[i]]);
    } else {
      result.push_back(original[i]);
    }
  }
  return result;
}

map<char,char> get_conversion_table() {
  map<char,char> conversion_table;  

  conversion_table['W'] = 'Q';
  conversion_table['E'] = 'W';
  conversion_table['R'] = 'E';
  conversion_table['T'] = 'R';
  conversion_table['Y'] = 'T';
  conversion_table['U'] = 'Y';
  conversion_table['I'] = 'U';
  conversion_table['O'] = 'I';
  conversion_table['P'] = 'O';
  conversion_table['['] = 'P';
  conversion_table[']'] = '[';
  conversion_table['\\'] = ']';
  conversion_table['1'] = '`';
  conversion_table['2'] = '1';
  conversion_table['3'] = '2';
  conversion_table['4'] = '3';
  conversion_table['5'] = '4';
  conversion_table['6'] = '5';
  conversion_table['7'] = '6';
  conversion_table['8'] = '7';
  conversion_table['9'] = '8';
  conversion_table['0'] = '9';
  conversion_table['-'] = '0';
  conversion_table['='] = '-';
  conversion_table['S'] = 'A';
  conversion_table['D'] = 'S';
  conversion_table['F'] = 'D';
  conversion_table['G'] = 'F';
  conversion_table['H'] = 'G';
  conversion_table['J'] = 'H';
  conversion_table['K'] = 'J';
  conversion_table['L'] = 'K';
  conversion_table[';'] = 'L';
  conversion_table['\''] = ';';
  conversion_table['X'] = 'Z';
  conversion_table['C'] = 'X';
  conversion_table['V'] = 'C';
  conversion_table['B'] = 'V';
  conversion_table['N'] = 'B';
  conversion_table['M'] = 'N';
  conversion_table[','] = 'M';
  conversion_table['.'] = ',';
  conversion_table['/'] = '.';

  return conversion_table;
}
