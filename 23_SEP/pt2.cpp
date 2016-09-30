#include <iostream>

using namespace std;

int main(void){
  int d;
  cin>>d;
  if(d<1) cout<<"wrong input"<<endl;
  else if(d==1) cout<<"*"<<endl;
  else{
    int base = 2*d -1;
    int count=1;
    int i,j,k, tmp;

    for(i=0;i<(base/2);i++)
      cout<<" ";
    cout<<"*"<<endl;
    count++;

    while(count<d){

      for( j=0;j<(base/2)-(count-1);j++)
        cout<<" ";
      cout<<"*";
      for( j=0; j<(count-1)*2-1;j++)
        cout<<" ";
      cout<<"*"<<endl;
      count++;
    }

    for( k=0;k<base;k++)
      cout<<"*";
    cout<<endl;
  }
  return 0;
}
