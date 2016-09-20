#include <iostream>
#include <vector>
using namespace std;

int main(){
  string line;
  getline(cin, line);

  for(int i=0;i<line.size();i++){
    if(ispunct(line[i])) ;
    else cout << line[i];
  }

  cout << endl;
  return 0;
}
