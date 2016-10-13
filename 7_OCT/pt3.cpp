#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

  vector<int> arr;
  vector<int> brr;
  int tmp;
  int size=0;
  while((cin>>tmp)){
    if(tmp==-1) break;
    arr.push_back(tmp);
    size++;
  }

  if(size){

    //1.remove primenumbers
    bool flag=false;
    for(auto i=arr.begin();i!=arr.end();++i){
      int test=*i;
      for(tmp=2;tmp<=(test)/2;++tmp)
      if(test%tmp==0){
        flag = true;
        break;
      }
      if(flag||test==1) brr.push_back(test);
      flag=false;
    }

    if(!brr.empty()){
      //2.sort
      sort(brr.begin(), brr.end());

      //3.remove duplication
      arr.clear();
      auto i = brr.begin();
      tmp = *i;
      while(1){
        while(tmp ==*i && i!=brr.end()) ++i;
        arr.push_back(tmp);
        tmp = *i;
        if(i==brr.end()) break;
      }

      for(int tmp=0;tmp<arr.size();tmp++)
        cout<<arr.at(tmp)<<" ";
    }
  }

      cout<<endl;
  return 0;
}
