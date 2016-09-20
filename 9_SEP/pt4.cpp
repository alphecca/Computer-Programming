#include <iostream>
#include <vector>

using namespace std;

int main(){
  int input;
  int size=0;
  int i=0;

  vector<int> V;
  vector<int> answ;

  //1.Put input
  while(cin >> input){
    if(input!=-1){
      V.push_back(input);
      size++;
    }
    else break;
  }
  if(size>0){
    //2.Sum
    for(i=0;i<=(size-1)/2-1;i++){
      answ.push_back(V[i]+V[size-1-i]);
    }

    if(size%2==0){
      answ.push_back(V[(size-1)/2]+V[(size+1)/2]);
    }
    else{
      answ.push_back(V[(size-1)/2]);
    }

    //3.Print using iterator
    for(vector<int>::const_iterator iter = answ.begin();iter != answ.end(); ++iter){
      cout<< (*iter)<< " ";
    }
    cout << endl;
  }
  else ;

  return 0;
}
