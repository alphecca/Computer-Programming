#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int n;
string dic[100];

bool check(string wd){
  for(int i=0; i<100;++i){
    if(!(dic[i]).compare(wd)) return true;
  }
  return false;
}
int main(void){

  map<char, string> table;
  table['m']="a";
  table['f']="b";
  table['z']="c";
  table['y']="d";
  table['t']="e";
  table['x']="f";
  table['w']="g";
  table['v']="h";
  table['c']="i";
  table['d']="j";
  table['g']="k";
  table['o']="l";
  table['u']="m";
  table['e']="n";
  table['l']="o";
  table['a']="p";
  table['h']="q";
  table['b']="r";
  table['i']="s";
  table['j']="t";
  table['g']="u";
  table['k']="v";
  table['n']="w";
  table['p']="x";
  table['r']="y";
  table['s']="z";

  string word;
  string sentence;

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>word;
    dic[i]=word;
  }

  cin.ignore(256,'\n');
  getline(cin, sentence);

  //1. Convert
  for(int i=0;i<sentence.length();i++){
    if(sentence.at(i)!=' '){
      sentence.replace(i,1,table.find(sentence.at(i))->second);
    }
  }

  //2. Check the word is in my table
  //split it!
  int j=0;
  int pos=0;
  string result=sentence;

  while(j<sentence.length()){
    while(j<sentence.length()&&sentence.at(j)!=' ') j++;
    word=sentence.substr(pos,j-pos);
    j+=1;
    pos=j;
    if(!check(word)){
      cout<<"mission failure..."<<endl;
      return 0;
    }
  }

  if(result.length()>0)
    cout<<result;
  cout<<endl;
  return 0;
}
