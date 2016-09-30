#include <iostream>
using namespace std;

void hanoi(int height, int start, int dest, int middle);
int main(void){
  int height, start, dest, middle;
  cin >> height >> start >> dest;

  if(start+dest == 3) middle =3;
  else if(start+dest ==4) middle =2;
  else if(start+dest ==5) middle =1;
  else middle =0;

  hanoi(height, start, dest, middle);

  return 0;
}


void hanoi(int height, int start, int dest, int middle){
  if(height==1){
    cout<<height<<" : "<<start<<" -> "<<dest<<endl;
  }
  else{
    hanoi(height-1, start, middle, dest);
    cout<<height<<" : "<<start<<" -> "<<dest<<endl;
    hanoi(height-1, middle, dest, start);
  }
}
