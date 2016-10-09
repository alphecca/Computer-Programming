#include <iostream>
#include <string>

using namespace std;
int T,M,N;
class Bingo{
  public :
    void setTable(char a, int i, int j) ;
    char getTable(int i, int j);
    bool match(string str, int a, int i, int j );
  private:
    static char Table[30][30];
};

char Bingo::Table[30][30];//static data member

void Bingo::setTable(char a, int i, int j){
  Table[i][j] = toupper(a);
}
char Bingo::getTable(int i, int j){
  if(i<30&&j<30) return Table[i][j];
}
bool Bingo::match(string str, int a, int i, int j){
  if(str.length()==1){//base case
    if(str.at(0)==Table[i][j]) return true;
    else false;
 }
  else{
    if(str.at(0)==Table[i][j]){
      switch(a){
        case(0)://North
          if(0<=(i-1))
             return match(str.substr(1),a,i-1,j);
          else break;
       case(1)://South
          if((i+1)<M)
            return match(str.substr(1),a,i+1,j);
          else break;
      case(2)://West
          if(0<=(j-1))
            return match(str.substr(1),a,i,j-1);
          else break;
      case(3)://East
          if((j+1)<N)
            return match(str.substr(1),a,i,j+1);
          else break;
      case(4)://NorthEast
          if(0<=(i-1)&&(j+1)<N)
            return match(str.substr(1),a,i-1,j+1);
          else break;
      case(5)://SouthEast
          if((i+1)<M&&(j+1)<N)
            return match(str.substr(1), a, i+1, j+1);
          else break;
      case(6)://SouthWest
          if((i+1)<M&&0<=(j-1))
            return match(str.substr(1),a,i+1,j-1);
          else break;
      case(7)://NorthWest
          if(0<=(i-1)&&0<=(j-1))
            return match(str.substr(1), a, i-1,j-1);
          else break;
     }//end of switch
      return false;
    }
    else return false;
  }//end of else
}
int main(void){
  cin>>T>>M>>N;
  char tmp;

  Bingo bingo;

  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cin>>tmp;
      bingo.setTable(tmp, i, j);
    }
  }
  bool flag=false;
  string str;
  string result[T];

  for(int k=0;k<T;k++){
    flag=false;
    cin>>str;
    if(str.length()==0) cout<<"false"<<endl;
    else{
      for(int aaa=0;aaa<str.length();aaa++){
        str.at(aaa)=toupper(str.at(aaa));
      }
      for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){

          if(bingo.getTable(i,j)==str.at(0)){
            for(int tmp=0;tmp<8;tmp++)
              if(bingo.match(str,tmp,i,j)) flag=true;
            if(flag){
              result[k]=to_string(i+1)+" "+to_string(j+1);
              i=M,j=N;//break
            }
          }

        }
      }//end of for loop
      if(!flag) result[k]="false";
    }//end of else
  }
  for(int k=0;k<T;k++) cout<<result[k]<<endl;
  return 0;
}
