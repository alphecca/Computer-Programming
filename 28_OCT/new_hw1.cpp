#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Movie{
  public:
    string name;
    string genre;
    string source;
    double production;
    double gross;
    double rating;
    //consturctor
    Movie():production(0),gross(0),rating(0){}
    Movie(string str){
      int i;
      for(i=0;str.at(i)!=' ';i++) ;
      name=str.substr(0,i);
//      cout<<"name"<<name<<endl;
      str=str.substr(i+1);
      for(i=0;str.at(i)!=' ';i++) ;
      genre=str.substr(0, i);
//      cout<<"genre"<<genre<<endl;
      str=str.substr(i+1);
      for(i=0;str.at(i)!=' ';i++) ;
      source=str.substr(0,i);
      str=str.substr(i+1);
//      cout<<"str: "<<str<<endl;
      for(i=0; str.at(i)!=' ';i++) ;
      production=stod(str.substr(0,i));
      str=str.substr(i+1);
      for(i=0; str.at(i)!=' ';i++) ;
      gross = stod(str.substr(0,i));
      str=str.substr(i+1);
//      cout<<"str : "<<str<<endl;
      rating=stod(str);
    }
};

vector<Movie> movieList;
string pivotTable1[9][2];
string pivotTable2[81][3];
string C,N,F,C1,C2;

void tot(bool flag){
if(flag){
      for(int i=0;i<9;i++)
        for(int k=0;k<2;k++)
         pivotTable1[i][k]="";
    }
    else{
      for(int i=0;i<81;i++)
        for(int k=0;k<3;k++)
          pivotTable2[i][k]="";
    }

  int i,j,k;
  double current;
  if(flag){//pivotTable1
    for(auto it=movieList.begin();it!=movieList.end();++it){
      Movie my_movie=*it;

      if(!N.compare("Production")) current=my_movie.production;
      else if(!N.compare("Gross")) current=my_movie.gross;
      else if(!N.compare("Rating")) current=my_movie.rating;
      else ;

      string c;
      if(!C.compare("Genre")) c=my_movie.genre;
      else c=my_movie.source;
      for(i=0;i<9;i++) if(pivotTable1[i][0]!="" &&!pivotTable1[i][0].compare(c)) break;

      if(i==9){//new
        for(i=0;i<9&&pivotTable1[i][0]!="";i++);
        pivotTable1[i][0]=c;
        pivotTable1[i][1]=to_string(current);
      }
      else{//already exists
        pivotTable1[i][1]=to_string(stod(pivotTable1[i][1])+current);
      }
    }//pivotTable1
  }

  else{//pivotTable2
    for(auto it=movieList.begin();it!=movieList.end();++it){
      Movie my_movie=*it;

      if(!N.compare("Production")) current=my_movie.production;
      else if(!N.compare("Gross")) current=my_movie.gross;
      else if(!N.compare("Rating")) current=my_movie.rating;
      else ;
      string c1,c2;
      if(!C1.compare("Genre")&&!C2.compare("Source")){
        c1=my_movie.genre;
        c2=my_movie.source;
      }
      else{
        c1=my_movie.source;
        c2=my_movie.genre;
      }

      for(i=0;i<81;i++) if(!pivotTable2[i][0].compare(c1)) break;
      if(i==81){//new c1
        for(i=0;i<81&&pivotTable2[i][0]!="";i+=9) ;
        for(k=i;k<i+9;k++) pivotTable2[k][0]=c1;

        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9) pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(current);
        }
        else{//c2 already exists
          pivotTable2[k][2]=to_string(current);
        }
      }//end of newc1
      else{//c1 already exists
        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2

          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9){
            pivotTable2[j][1]=c2;
          }
          pivotTable2[k][2]=to_string(current);
        }
        else{//c2 already exists
          if(pivotTable2[k][2]!=""){
            pivotTable2[k][2]=to_string(stod(pivotTable2[k][2])+current);
          }
          else pivotTable2[k][2]=to_string(current);
        }
      }//end of already c1
      //cout<<"+++++++++++++++"<<endl;
//      for(int a=0;a<81;a++)
//      cout<<pivotTable2[a][0]<<" "<<pivotTable2[a][1]<<endl;

    }//end of iterator
      }//end of else
}
void ave(bool flag){
  //initialize
  if(flag){
      for(int i=0;i<9;i++)
        for(int k=0;k<2;k++)
         pivotTable1[i][k]="";
    }
    else{
      for(int i=0;i<81;i++)
        for(int k=0;k<3;k++)
          pivotTable2[i][k]="";
    }
    //sum
    tot(flag);
    int i,j,k;

    //counting
    if(flag){//pivotTable1
      string c;
      int cnt[9]={0,0,0,0,0,0,0,0,0};

      for(auto it=movieList.begin();it!=movieList.end();++it){
        Movie my_movie=*it;

        if(!C.compare("Genre")) c=my_movie.genre;
        else c=my_movie.source;
        for(i=0;i<9;i++)
          if(pivotTable1[i][0]!=""&&!pivotTable1[i][0].compare(c)) cnt[i]++;
      }
      for(i=0;i<9;i++){
        if(pivotTable1[i][0]!=""){
          //    cout<<stod(pivotTable1[i][1])<<" / "<<cnt[i]<<"="<<stod(pivotTable1[i][1])/cnt[i]<<endl;
          pivotTable1[i][1]=to_string(stod(pivotTable1[i][1])/cnt[i]);
        }
      }

    }//end of pivotTable1
    else{//pivotTable2
      string c1,c2;
      int cnt[81];
      for(k=0;k<81;k++) cnt[k]=0;

      for(auto it=movieList.begin();it!=movieList.end();++it){
        Movie my_movie=*it;

        if(!C1.compare("Genre")&&!C2.compare("Source")){
          c1=my_movie.genre;
          c2=my_movie.source;
        }
        else{
          c1=my_movie.source;
          c2=my_movie.genre;
        }
        for(i=0;i<81;i+=9)
          if(pivotTable2[i][0]!=""&&!pivotTable2[i][0].compare(c1))
            for(k=i;k<i+9;k++)
              if(pivotTable2[k][1]!=""&&!pivotTable2[k][1].compare(c2)) cnt[k]++;
      }
//      cout<<"cnt is \t";
//      for(i=0;i<81;i++) cout<<cnt[i]<<"\t";
//      cout<<endl;
//      for(i=0;i<81;i++)
//        cout<<pivotTable2[i][0]<<" "<<pivotTable2[i][1]<<" "<<stod(pivotTable2[i][2])<<endl;


      for(i=0;i<81;i++)
        if(pivotTable2[i][0]!="")
          if(pivotTable2[i][1]!=""&&cnt[i]!=0){
            //cout<<pivotTable2[i][0]<<" "<<pivotTable2[i][1]<<" "<<stod(pivotTable2[i][2])<<endl;
            if(cnt[i]!=0)
            pivotTable2[i][2]=to_string(stod(pivotTable2[i][2])/cnt[i]);
          }


    }//end of pivotTable2

}
void max(bool flag){
if(flag){
      for(int i=0;i<9;i++)
        for(int k=0;k<2;k++)
         pivotTable1[i][k]="";
    }
    else{
      for(int i=0;i<81;i++)
        for(int k=0;k<3;k++)
          pivotTable2[i][k]="";
    }

  int i,j,k;
  double current;
  for(auto it=movieList.begin();it!=movieList.end();++it){
    Movie my_movie=*it;

    if(!N.compare("Production")) current=my_movie.production;
    else if(!N.compare("Gross")) current=my_movie.gross;
    else if(!N.compare("Rating")) current=my_movie.rating;
    else ;

    if(flag){//pivotTable1
      string c;
      if(!C.compare("Genre")) c=my_movie.genre;
      else c=my_movie.source;
      for(i=0;i<9;i++) if(!pivotTable1[i][0].compare(c)) break;
      if(i==9){//new
        for(i=0;i<9&&pivotTable1[i][0]!="";i++);
        pivotTable1[i][0]=c;
        pivotTable1[i][1]=to_string(current);
      }
      else{//already exists
        if(pivotTable1[i][1]!=""){
          if(stod(pivotTable1[i][1])<current) pivotTable1[i][1]=to_string(current);
        }
          else pivotTable1[i][1]=to_string(current);
      }
    }
    else{//pivotTable2
      string c1,c2;
      if(!C1.compare("Genre")&&!C2.compare("Source")){
        c1=my_movie.genre;
        c2=my_movie.source;
      }
      else{
        c1=my_movie.source;
        c2=my_movie.genre;
      }

      for(i=0;i<81;i+=9) if(!pivotTable2[i][0].compare(c1)) break;
      if(i==81){//new c1
        for(i=0;i<81&&pivotTable2[i][0]!="";i+=9) ;
        for(k=i;k<i+9;k++) pivotTable2[k][0]=c1;

        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9) pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(current);
        }
        else{//c2 already exists
          pivotTable2[k][2]=to_string(current);
        }

      }
      else{//c1 already exists
        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9) pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(current);
        }
        else{//c2 already exists
          if(pivotTable2[k][2]!=""){
            if(stod(pivotTable2[k][2])<current) pivotTable2[k][2]=to_string(current);
          }
          else pivotTable2[k][2]=to_string(current);

        }
//        cout<<"+++++++++++++++"<<endl;
//        for(int a=0;a<81;a++){
//          cout<<pivotTable2[a][0]<<" "<<pivotTable2[a][1];
//          if(pivotTable2[a][2]!="") cout<<pivotTable2[a][2];
//          cout<<endl;
//        }
      }//end of else
         }//end of pivotTable2
  }//and of iterate(movieList)
}
void min(bool flag){
if(flag){
      for(int i=0;i<9;i++)
        for(int k=0;k<2;k++)
         pivotTable1[i][k]="";
    }
    else{
      for(int i=0;i<81;i++)
        for(int k=0;k<3;k++)
          pivotTable2[i][k]="";
    }

  int i,j,k;
  double current;
  for(auto it=movieList.begin();it!=movieList.end();++it){
    Movie my_movie=*it;

    if(!N.compare("Production")) current=my_movie.production;
    else if(!N.compare("Gross")) current=my_movie.gross;
    else if(!N.compare("Rating")) current=my_movie.rating;
    else ;

    if(flag){//pivotTable1
      string c;
      if(!C.compare("Genre")) c=my_movie.genre;
      else c=my_movie.source;
      for(i=0;i<9;i++) if(!pivotTable1[i][0].compare(c)) break;
      if(i==9){//new
        for(i=0;i<9&&pivotTable1[i][0]!="";i++);
        pivotTable1[i][0]=c;
        pivotTable1[i][1]=to_string(current);
      }
      else{//already exists
        if(stod(pivotTable1[i][1])>(current)) pivotTable1[i][1]=to_string(current);
      }
    }
    else{//pivotTable2
      string c1,c2;
      if(!C1.compare("Genre")&&!C2.compare("Source")){
        c1=my_movie.genre;
        c2=my_movie.source;
      }
      else{
        c1=my_movie.source;
        c2=my_movie.genre;
      }
      for(i=0;i<81;i+=9) if(!pivotTable2[i][0].compare(c1)) break;
      if(i==81){//new c1
        for(i=0;i<81&&pivotTable2[i][0]!="";i+=9) ;
        for(k=i;k<i+9;k++) pivotTable2[k][0]=c1;

        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9) pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(current);
        }
        else{//c2 already exists
          pivotTable2[k][2]=to_string(current);
        }
      }
      else{//c1 already exists
        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9) pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(current);
        }
        else{//c2 already exists
          if(pivotTable2[k][2]!=""){
            if(stod(pivotTable2[k][2])>current) pivotTable2[k][2]=to_string(current);
          }
          else pivotTable2[k][2]=to_string(current);
        }

      }//end of else

    }//end of pivot2

  }//and of iterate(movieList)
}
void cnt(bool flag){
if(flag){
      for(int i=0;i<9;i++)
        for(int k=0;k<2;k++)
         pivotTable1[i][k]="";
    }
    else{
      for(int i=0;i<81;i++)
        for(int k=0;k<3;k++)
          pivotTable2[i][k]="";
    }

  int i,j,k;
  if(flag){//pivotTable1
    for(auto it=movieList.begin();it!=movieList.end();++it){
      Movie my_movie=*it;

      string c;
      if(!C.compare("Genre")) c=my_movie.genre;
      else c=my_movie.source;
      for(i=0;i<9;i++) if(!pivotTable1[i][0].compare(c)) break;
      if(i==9){//new
        for(i=0;i<9&&pivotTable1[i][0]!="";i++);
        pivotTable1[i][0]=c;
        pivotTable1[i][1]=to_string(1);
      }
      else{//already exists
        pivotTable1[i][1]=to_string(stod(pivotTable1[i][1])+1);
      }
    }}
  else{//pivotTable2
    for(auto it=movieList.begin();it!=movieList.end();++it){
      Movie my_movie=*it;
      string c1,c2;

      if(!C1.compare("Genre")&&!C2.compare("Source")){
        c1=my_movie.genre;
        c2=my_movie.source;
      }
      else{
        c1=my_movie.source;
        c2=my_movie.genre;
      }

      for(i=0;i<81;i++) if(!pivotTable2[i][0].compare(c1)) break;

      if(i==81){//new c1
        for(i=0;i<81&&pivotTable2[i][0]!="";i+=9) ;
        for(k=i;k<i+9;k++) pivotTable2[k][0]=c1;

        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9) pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(1);
        }
        else{//c2 already exists
          pivotTable2[k][2]=to_string(1);
        }

      }
      else{//c1 already exists
        for(k=i;k<i+9;k++) if(!pivotTable2[k][1].compare(c2)) break;
        if(k==i+9){//new c2
          for(k=i;k<i+9&&pivotTable2[k][1]!="";k++) ;
          for(j=k%9;j<81;j+=9)
            pivotTable2[j][1]=c2;
          pivotTable2[k][2]=to_string(1);
        }
        else{//c2 already exists
          if(pivotTable2[k][2]!="")
            pivotTable2[k][2]=to_string(stod(pivotTable2[k][2])+1);
          else pivotTable2[k][2]=to_string(1);
        }
      }//end of else
//      cout<<"+++++++++++++++"<<endl;
//      for(int a=0;a<81;a++)
//      cout<<pivotTable2[a][0]<<" "<<pivotTable2[a][1]<<endl;
    }//end of iterator
  }//end of pivot2
}
void OriginalTable(){
  cout<<"Name\tGenre\tSource\tProduction\tGross\tRating"<<endl;
  for(auto it=movieList.begin();it!=movieList.end();++it){
    Movie movie=*it;
    cout<<movie.name<<"\t"<<movie.genre<<"\t"<<movie.source<<"\t"
      <<movie.production<<"\t"<<movie.gross<<"\t"<<movie.rating<<endl;
  }

}
void PivotTable(bool flag){
  if(flag){//pivotTable1
    cout<<C<<"\t"<<N<<endl;
    for(int i=0;i<9&&pivotTable1[i][0]!="";i++){
      cout.precision(2);
      cout<<pivotTable1[i][0]<<"\t"<<fixed<<stod(pivotTable1[i][1])<<endl;
    }
  }
  else{//pivotTable2
    cout<<C1<<"\t"<<C2<<"\t"<<N<<endl;
    for(int i=0;i<81;i+=9){
      if(pivotTable2[i][0]!="")
        for(int k=i;k<i+9;k++)
          if(pivotTable2[k][2]!=""){
            cout.precision(2);
            cout<<pivotTable2[k][0]<<"\t"<<pivotTable2[k][1]<<"\t"<<fixed<<stod(pivotTable2[k][2])<<endl;
          }
    }
  }
}
void PivotChart(bool flag){
  vector<double> tmp;

  if(flag){//pivotTable1
    double result[9];
    for(int i=0;i<9;i++){
      if(pivotTable1[i][1]!=""){
        result[i]=stod(pivotTable1[i][1]);
        tmp.push_back(result[i]);
      }
      else result[i]=-1;
    }

    double max=*max_element(result, result+9);
    double min=*min_element(tmp.begin(), tmp.end());
    double interval=(max-min)/20;
    int cnt[9]={0,0,0,0,0,0,0,0,0};
    for(int i=0;i<9;i++){
      if(result[i]==-1) ;
      else{
        if(result[i]==min) cnt[i]=0;
        if(min<result[i]) cnt[i]++;
        if(min+interval<result[i]) cnt[i]++;
        if(min+2*interval<result[i]) cnt[i]++;
        if(min+3*interval<result[i]) cnt[i]++;
        if(min+4*interval<result[i]) cnt[i]++;
        if(min+5*interval<result[i]) cnt[i]++;
        if(min+6*interval<result[i]) cnt[i]++;
        if(min+7*interval<result[i]) cnt[i]++;
        if(min+8*interval<result[i]) cnt[i]++;
        if(min+9*interval<result[i]) cnt[i]++;
        if(min+10*interval<result[i]) cnt[i]++;
        if(min+11*interval<result[i]) cnt[i]++;
        if(min+12*interval<result[i]) cnt[i]++;
        if(min+13*interval<result[i]) cnt[i]++;
        if(min+14*interval<result[i]) cnt[i]++;
        if(min+15*interval<result[i]) cnt[i]++;
        if(min+16*interval<result[i]) cnt[i]++;
        if(min+17*interval<result[i]) cnt[i]++;
        if(min+18*interval<result[i]) cnt[i]++;
        if(min+19*interval<result[i]) cnt[i]++;
      }
    }

    //print Sticks
    //
    if(interval==0)
      for(int i=0;i<9;i++) cnt[i]=20;
    for(int i=0;i<9;i++){
      if(result[i]!=-1){
        if(!C.compare("Genre"))
          cout<<(char)(i+'A')<<"|";
        else
          cout<<i+1<<"|";
        for(int k=0;k<cnt[i];k++) cout<<"=";
        cout.precision(2);
        cout<<fixed<<result[i]<<endl;
      }
    }

    //print Labels
    for(int i=0;i<25;i++) cout<<"-";
    cout<<endl;
    for(int i=0;i<9;i++)
      if(pivotTable1[i][0]!=""){
        if(!C.compare("Genre"))
          cout<<(char)(i+'A')<<": ";
        else
          cout<<i+1<<": ";
        cout<<pivotTable1[i][0]<<endl;
      }

  }
  else{//pivotTable2
    double result[81];
    for(int i=0;i<81;i++) result[i]=-1;

    for(int i=0;i<81;i+=9){
      if(pivotTable2[i][0]!=""){
        for(int k=i;k<i+9;k++){
          if(pivotTable2[k][1]!="")
          if(pivotTable2[k][2]!=""){
            result[k]=stod(pivotTable2[k][2]);
            tmp.push_back(result[k]);
          }
        }
      }
    }

    double max=*max_element(result, result+81);
    double min=*min_element(tmp.begin(), tmp.end());
    double interval=(max-min)/20;
    int cnt[81];
    for(int i=0;i<81;i++) cnt[i]=0;

    for(int i=0;i<81;i++){
      if(result[i]==-1) ;
      else{
        if(result[i]==min) cnt[i]=0;
        if(min<result[i]) cnt[i]++;
        if(min+interval<result[i]) cnt[i]++;
        if(min+2*interval<result[i]) cnt[i]++;
        if(min+3*interval<result[i]) cnt[i]++;
        if(min+4*interval<result[i]) cnt[i]++;
        if(min+5*interval<result[i]) cnt[i]++;
        if(min+6*interval<result[i]) cnt[i]++;
        if(min+7*interval<result[i]) cnt[i]++;
        if(min+8*interval<result[i]) cnt[i]++;
        if(min+9*interval<result[i]) cnt[i]++;
        if(min+10*interval<result[i]) cnt[i]++;
        if(min+11*interval<result[i]) cnt[i]++;
        if(min+12*interval<result[i]) cnt[i]++;
        if(min+13*interval<result[i]) cnt[i]++;
        if(min+14*interval<result[i]) cnt[i]++;
        if(min+15*interval<result[i]) cnt[i]++;
        if(min+16*interval<result[i]) cnt[i]++;
        if(min+17*interval<result[i]) cnt[i]++;
        if(min+18*interval<result[i]) cnt[i]++;
        if(min+19*interval<result[i]) cnt[i]++;
      }
    }

    //print Sticks
    if(interval==0)
      for(int i=0;i<81;i++) cnt[i]=20;
    int tmp=0;
    for(int i=0;i<81;i++){
      if(result[i]!=-1){
        if(tmp!=i/9) cout<<"  |"<<endl;
        if(C1.compare("Genre"))
          cout<<(i/9)+1<<(char)((i%9)+'A')<<"|";
        else
          cout<<(char)(i/9+'A')<<i%9+1<<"|";
        for(int k=0;k<cnt[i];k++) cout<<"=";
        cout.precision(2);
        cout<<fixed<<result[i]<<endl;
        tmp=i/9;
      }
    }

    //print Labels
    for(int i=0;i<25;i++) cout<<"-";
    cout<<endl;
    for(int i=0;i<81;i+=9)
      if(pivotTable2[i][0]!=""){
        if(!C1.compare("Genre"))
          cout<<(char)((i/9)+'A')<<": ";
        else
          cout<<i/9+1<<": ";
        cout<<pivotTable2[i][0]<<endl;
      }
    for(int i=0;i<9;i++){
      if(pivotTable2[i][1]!=""){
        if(!C2.compare("Genre"))
        cout<<(char)(i%9+'A')<<": ";
        else
          cout<<i%9+1<<": ";
        cout<<pivotTable2[i][1]<<endl;
      }
    }
  }

}
int main(){
  int n;
  string tmp;
  bool flag;

  //1. Data input
  cin>>n;
  cin.ignore(256,'\n');

  for(int i=0;i<n;i++){
    getline(cin, tmp);
    movieList.push_back(Movie(tmp));
  }

  //2. Command input
  vector<string> cmd;
  getline(cin, tmp);
  while(tmp.compare("close")){
    cmd.push_back(tmp);
    getline(cin, tmp);
  }

  //3. Execute commands
  for(auto it=cmd.begin();it!=cmd.end();++it){
    string str=*it;
    int pos,i;
    if(str.find("pivot1")!=string::npos){

      flag=true;
      str=str.substr(7);
      for(i=0; str.at(i)!=' ';i++) ;
      C=str.substr(0,i);
      pos=i+1;
      for(i=pos; str.at(i)!=' ';i++) ;
      N=str.substr(pos, i-pos);
      pos=i+1;
      F=str.substr(pos);
      if(!F.compare("ave"))
        ave(true);
      else if(!F.compare("tot"))
        tot(true);
      else if(!F.compare("max"))
        max(true);
      else if(!F.compare("min"))
        min(true);
      else if(!F.compare("cnt"))
        cnt(true);
      else ;
    }
    else if(str.find("pivot2")!=string::npos){
      flag=false;
      str=str.substr(7);
      for(i=0; str.at(i)!=' ';i++) ;
      C1=str.substr(0,i);
      pos=i+1;
      for(i=pos; str.at(i)!=' ';i++) ;
      C2=str.substr(pos,i-pos);
      pos=i+1;
      for(i=pos; str.at(i)!=' ';i++) ;
      N=str.substr(pos,i-pos);
      pos=i+1;
      F=str.substr(pos);
      pos=i+1;
      if(!F.compare("ave"))
        ave(false);
      else if(!F.compare("tot"))
        tot(false);
      else if(!F.compare("max"))
        max(false);
      else if(!F.compare("min"))
        min(false);
      else if(!F.compare("cnt"))
        cnt(false);
      else ;

    }
    else if(str.find("originaltable")!=string::npos){
      OriginalTable();
    }
    else if(str.find("pivottable")!=string::npos){
      PivotTable(flag);
    }
    else if(str.find("pivotchart")!=string::npos){
      PivotChart(flag);
    }
    else ;
  }
return 0;
}
