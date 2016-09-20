#include <iostream>
#include <iomanip>
#include <string>

int arr[20][20];
void snail(int start, std::string dir, int wid);

int main(){
  int wid, start;
  std::string dir;
  std::cin >> wid>>start>>dir;
  for(int k=0;k<20;k++)
    for(int l=0;l<20;l++)
      arr[k][l] = 0;

  if(wid>20||wid<=0)
    std::cout<<"wrong wid"<<std::endl;
  else if(start<0 && 3<start)
    std::cout<<"wrong start number"<<std::endl;
  else if(dir.compare("C")!=0&&dir.compare("CC")!=0)
    std::cout <<"wrong direction"<<std::endl;
  else{
    snail(start, dir, wid);

    for(int i=0;i<wid;i++){
      for(int j=0;j<wid;j++)
        std::cout<<std::setfill(' ')<<std::setw(4)<<arr[i][j];
      std::cout<<std::endl;
    }
  }//else
  return 0;
}

void snail(int flag, std::string dir, int wid){
  int tmp=1;
  int count = wid*wid;
  int i,j;

  if(flag==0)  i=j=0;
  if(flag==1){
    i=0;
    j=wid-1;
  }
  if(flag==2) i=j=wid-1;
  if(flag==3){
    i=wid-1;
    j=0;
  }
  if(dir.compare("C")==0){
    while(tmp<=count){
      if(flag==0 || flag==9){
        while(j<wid&&arr[i][j]==0) arr[i][j++]=tmp++;
        j--;
        i++;
        flag=9;
      }
      if(flag==1 || flag==9){
        while(i<wid&&arr[i][j]==0) arr[i++][j] = tmp++;
        i--;
        j--;
        flag=9;
      }
      if(flag==2 || flag==9){
        while(j>=0&&arr[i][j]==0) arr[i][j--]=tmp++;
        j++;
        i--;
        flag=9;
      }
      if(flag==3 || flag==9){
        while(i>=00&&arr[i][j]==0) arr[i--][j]=tmp++;
        i++;
        j++;
        flag=9;
      }
    }
  }//if direction is Clockwise
  else {//if(dir.compare("CC")==0){
    while(tmp<=count){

      if(flag==3 || flag==9){
        while(j<wid&&arr[i][j]==0) arr[i][j++]=tmp++;
        j--;
        i--;
        flag=9;
      }
      if(flag==2 || flag==9){
        while(i>=00&&arr[i][j]==0) arr[i--][j]=tmp++;
        i++;
        j--;
        flag=9;
      }
      if(flag==1 || flag==9){
        while(j>=0&&arr[i][j]==0) arr[i][j--]=tmp++;
        j++;
        i++;
        flag=9;
      }
     if(flag==0 || flag==9){
         while(i<wid&&arr[i][j]==0) arr[i++][j] = tmp++;
        i--;
        j++;
        flag=9;
     }}
  }//if direction is Counter Clockwise
}
