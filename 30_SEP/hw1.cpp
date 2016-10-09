#include <iostream>
using namespace std;
int M,N;

class Pixel{
  public:
    void hi(int a, int b);
    void clean();
    void mark(int , int , char );
    void vertical(int , int, int, char );
    void horizon(int , int , int , char );
    void fill(int, int , int , int , char);
    void rect(int, int, int, int, char);
    void change(int ,int, char);
    void bye();
  private:
    static char Board[30][30];
};
char Pixel::Board[30][30];//static data member

int main(void){
  Pixel pixel;
  string command;
  while(cin>>command){
    int x,y,x1,y1,x2,y2;
    char c;
    if(!command.compare("hi")){
      cin>>x>>y;
      pixel.hi(x,y);
    }
    else if(!command.compare("clean"))
      pixel.clean();
    else if(!command.compare("mark")){
      cin>>x>>y>>c;
      pixel.mark(x,y,c);
    }
    else if(!command.compare("vertical")){
      cin>>x>>y1>>y2>>c;
      pixel.vertical(x,y1,y2,c);
    }
    else if(!command.compare("horizon")){
      cin>>x1>>x2>>y>>c;
      pixel.horizon(x1,x2,y,c);
    }
    else if(!command.compare("fill")){
      cin>>x1>>y1>>x2>>y2>>c;
      pixel.fill(x1,y1,x2,y2,c);
    }
    else if(!command.compare("rect")){
      cin>>x1>>y1>>x2>>y2>>c;
      pixel.rect(x1,y1,x2,y2,c);
    }
    else if(!command.compare("change")){
      cin>>x>>y>>c;
      pixel.change(y-1,x-1,c);
    }
    else if(!command.compare("bye")){
      pixel.bye();
      break;
    }
    else cout<<"wrong command"<<endl;
  }
}
void Pixel::hi(int m,int n){
  M=m, N=n;
  clean();
}
void Pixel::clean(){
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      Board[i][j]='O';
}
void Pixel::mark(int x, int y, char c){
  Board[y-1][x-1]=c;
}
void Pixel::vertical(int x, int y1, int y2, char c){
  for(int j=(y1-1);j<y2;j++)
    Board[j][x-1]=c;
}
void Pixel::horizon(int x1,int x2, int y, char c){
  for(int i=(x1-1);i<x2;i++)
    Board[y-1][i]=c;
}
void Pixel::fill(int x1, int y1, int x2, int y2, char c){
  for(int i=(x1-1);i<x2;i++)
    for(int j=(y1-1);j<y2;j++)
      Board[j][i]=c;
}
void Pixel::rect(int x1,int y1, int x2, int y2, char c){
  for(int i=(x1-1);i<x2;i++){
    Board[y1-1][i]=c;
    Board[y2-1][i]=c;
  }
  for(int j=(y1-1);j<y2;j++){
    Board[j][x1-1]=c;
    Board[j][x2-1]=c;
  }
}
void Pixel::change(int x,int y, char c){

  char tmp = Board[x][y];
  Board[x][y]=c;

  if(0<=(x-1)) if(tmp==Board[x-1][y])
    change(x-1,y,c);
  if((y+1)<N) if(tmp==Board[x][y+1])
    change(x,y+1,c);
  if((x+1)<M) if(tmp==Board[x+1][y])
    change(x+1,y,c);
  if(0<=(y-1))if(tmp==Board[x][y-1])
    change(x,y-1,c);
}
void Pixel::bye(){
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cout<<Board[i][j];
    }
    if(i!=(M-1)) cout<<endl;
  }
}
