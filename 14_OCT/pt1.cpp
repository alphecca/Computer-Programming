#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;
map<string, string> maplist;//map<name, as>
map<string, set<string>> aslist;//map<as, set<name>>

void add(string, string);
bool exist(string);
void print(string);
int main(void){
  string input;
  int i=0;

  cin>>input;
  while(input.compare("end")!=0){
    if(input.compare("add")==0){
      string name, as;
      cin>>name>>as;
      add(name, as);
    }
    else if(input.find("exist")!=string::npos){
      bool flag;
      string name;
      cin>>name;
      flag= exist(name);
      if(flag) cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
    else if(input.find("print")!=string::npos){
      string as;
      cin>>as;
      print(as);
    }
    else{
      cout<<"wrong command"<<endl;
    }
    i=0;
    cin>>input;
  }
  return 0;
}
//map<string, string> maplist;//map<name, as>
//map<string, set<string>> aslist;//map<as, set<name>>

void add(string name, string as){
  maplist.insert(pair<string, string>(name, as));

  map<string, set<string>>::iterator it;
  it=aslist.find(as);

  if(it!=aslist.end()){//append
    set<string> temp = it->second;
   temp.insert(name);
    aslist.erase(it);
    aslist.insert(pair<string, set<string>>(as, temp));
  }
  else{//new
    set<string> temp;
    temp.insert(name);
    aslist.insert(pair<string,set<string>>(as,temp));
  }

}
bool exist(string name){

for(auto kk=maplist.begin();kk!=maplist.end();++kk){
}

  if(maplist.find(name)!=maplist.end())
    return true;
  else return false;
}
void print(string as){
  map<string,set<string>>::iterator it=aslist.find(as);
  if(it!=aslist.end()){
    set<string> temp = it->second;
    for(auto k = temp.begin(); k!=temp.end(); ++k)
      cout<<*k<<endl;
  }
  else{
    cout<<"no such as"<<endl;
  }
}
