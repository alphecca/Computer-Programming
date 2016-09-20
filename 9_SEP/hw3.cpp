#include <iostream>
#include <string>
#include <vector>
using namespace std;

//return int: check whether errors occur.
void add_genre(string genrename);
void add_movie(string genrename, string moviename);
void remove_genre(string genrename);
void remove_movie(string genrename, string moviename);
void print_genre(string genrename);
void print_all();

vector< vector<string> > list;

int main(){
    string command;
    string genrename;
    string moviename;

    cin>>command;

    while(command.compare("exit")!=0){
      genrename.empty();
      moviename.empty();
      if(command.find("_genre")!=string::npos){
        cin>>genrename;
      //  cout<<"command: "<<command<<"\tgenrename: "<<genrename;
        if(command.compare("add_genre")==0) add_genre(genrename);
        else if(command.compare("remove_genre")==0)  remove_genre(genrename);
        else if(command.compare("print_genre")==0)  print_genre(genrename);
        else{
          cout<<"wrong command"<<endl;
          cin>>command;
          continue;
        }
      }
      else if(command.find("_movie")!=string::npos) {
        cin>>genrename>>moviename;
      //  cout<<"command: "<<command<<"\tgenrename: "<<genrename<<"\tmoviename: "<<moviename;
        if(command.compare("add_movie")==0)  add_movie(genrename, moviename);
        else if(command.compare("remove_movie")==0)  remove_movie(genrename,moviename);
        else{
          cout<<"wrong command"<<endl;
          cin>>command;
          continue;
        }
      }
      else if(command.compare("print_all")==0)  print_all();
      else{
        cout<<"wrong command"<<endl;
        cin>>command;
        continue;
      }
      command.empty();
      cin>>command;
    }//end of while

    return 0;
}
void add_genre(string genrename){
  vector<string> movielist;
  movielist.push_back(genrename);
  list.push_back(movielist);
}
void add_movie(string genrename, string moviename){

  vector< vector<string> >::iterator row;
  bool flag=false;

  for(row=list.begin(); row != list.end(); row++){
    string name = *(row->begin());
    if(name.compare(genrename)==0){
      row->push_back(moviename);
      flag=true;
      break;
    }
  }
  if(!flag){//new genre
    vector<string> movielist;
    movielist.push_back(genrename);
    movielist.push_back(moviename);
    list.push_back(movielist);
  }
}
void remove_genre(string genrename){
  vector< vector<string> >::iterator itr;
  for(itr=list.begin(); itr!=list.end(); ){
    vector<string> movielist = *itr;
    if(movielist[0].compare(genrename)==0){
      itr=list.erase(itr);
      break;
    }
    else ++itr;
  }
}
void remove_movie(string genrename, string moviename){
  vector< vector<string> >::iterator row;
  vector<string>::iterator col;

  for(row=list.begin();row!=list.end(); row++){
    string name = *(row->begin());

    if(name.compare(genrename)==0){
      for(col=row->begin()+1; col!=row->end(); ){
        string movie = *col;
        if(movie.compare(moviename)==0){
          col=row->erase(col);
        }
        else ++col;
      }
      break;
    }

  }
}
void print_genre(string genrename){
  vector< vector<string> >::iterator row;
  vector<string>::iterator col;

  cout<<"--"<<genrename<<"--"<<endl;
  for(row=list.begin();row !=list.end(); row++){
    string name =*(row->begin());
    if(name.compare(genrename)==0){
      for(col=row->begin()+1;col!=row->end();col++){
        string movie = *col;
        cout<<movie<<endl;
      }
    }
  }
}
void print_all(){

  vector< vector<string> >::iterator row;
  vector<string>::iterator col;

  for(row=list.begin();row !=list.end(); row++){
    string genrename = *(row->begin());
    cout<<"--"<<genrename<<"--"<<endl;
    for(col=row->begin()+1;col!=row->end();col++){
        string movie = *col;
        cout<<movie<<endl;
    }
  }

}

