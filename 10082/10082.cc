#include<iostream>
#include<string>
#include<map>

int main(){
  std::string line;
  std::string result;
  std::map<char,char> conversion_table;

  conversion_table['W'] = 'Q';
  getline(std::cin, line);

  for(int i=0; i<line.size(); i++){
    if (conversion_table.count(line[i])==1){
      result.push_back(conversion_table[line[i]]);
    } else {
      result.push_back(line[i]);
    }
  }

  std::cout<<result<<std::endl;
}
