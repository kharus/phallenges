#include<vector>
#include<string>

std::vector<int> convert(std::string number);
std::vector<int> add(std::vector<int> number1, std::vector<int> number2);
int comp(const std::vector<int>& number1, const std::vector<int>& number2);
std::vector< std::vector<int> > fib_table(int max);
int find_below_index(std::vector< std::vector<int> >& sequence, std::vector<int> target);
int find_above_index(std::vector< std::vector<int> >& sequence, std::vector<int> target);
int numbers_in_interval(std::vector< std::vector<int> >& sequence, std::vector<int> low, std::vector<int> high);
