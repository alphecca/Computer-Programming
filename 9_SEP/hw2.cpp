#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <locale>
using namespace std;

int multiply(string str);
int split_add(string str );
bool check_add(string str);
bool check_mul(string str);

int main(){
    string line;
    string input;
    getline(std::cin, line);
    int i=0;

    //1.trim all the whitespace
    for(i=0;i<line.length();i++){
      if(isspace(line[i])) ;
      else input.push_back(line[i]);
    }

    //2.split by +,* and calculate
    int result =split_add(input);
    cout<<result<<endl;

    return 0;
}
int split_add(string str){

  if(check_add(str)){
    int i=0;
    while(str[i]!='+'&&i<str.length()) i++;
    string a = str.substr(0,i);
    int var1=multiply(a);
    string b = str.substr(i+1);
    return var1 + split_add(b);
  }
  else
    return multiply(str);

}
int multiply(string str){
  if(check_mul(str)){
      int i=0;
      while(str[i]!='*'&&i<str.length()) i++;
      string a = str.substr(0,i);
      int var1 = std::stoi(a,nullptr);
      string b = str.substr(i+1);
      return var1 * multiply(b);
  }
  else
    return std::stoi(str, nullptr);
}

bool check_add(string str){
  if(str.find("+")!=string::npos) return true;//+ operator exists
  else return false;
}
bool check_mul(string str){
  if(str.find("*")!=string::npos) return true;//* operator exists
  else return false;
}
