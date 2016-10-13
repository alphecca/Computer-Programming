#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Soccer{
  public:
    string name;
    int ground, point;
    int win, draw, lose;
    int Twin, Tlose, goal;

    //constructor
    Soccer(){//default constructor
      name=string();
      ground=point=win=draw=lose=Twin=Tlose=goal=0;
    }
    Soccer(string a, int b, char c, int d){
      name=a;
      ground=1;
      switch(c){
        case('W'):point=3;
                  win=1;
                  draw=lose=0;
                  break;
        case('L'):point=0;
                  lose=1;
                  win=draw=0;
                  break;
        case('D'):point=1;
                  draw=1;
                  win=lose=0;
                  break;
      }
      Twin=b;
      Tlose=d;
      goal=Twin-Tlose;
    }

    //member functions
    void add(int a, char b, int c){
      //update score in the existing team info
      ++ground;
      switch(b){
        case('W'):point+=3;
                  ++win;
                  break;
        case('L'):++lose;
                  break;
        case('D'):point+=1;
                  ++draw;
                  break;
      }
      Twin+=a;
      Tlose+=c;
      goal=Twin-Tlose;
    }
};

static list<Soccer> soccer;
void list_insert(string, int, char, int);
bool same(list<Soccer>::iterator, list<Soccer>::iterator);

int main(void){
  bool flag=false;
  string line;
  char result1, result2;

  while(getline(cin, line)){
    if(line.compare("end")==0) break;

    //1.parse by whitespace
    flag=true;//match exsits
    int curr=0;
    int pos =0;
    while(line.at(curr)!=' ') curr++;
    string name1=line.substr(0,curr++);
    pos=curr;
    while(line.at(curr)!=' ') curr++;
    int score1=stoi(line.substr(pos,curr++));
    pos=curr;
    while(line.at(curr)!=' ') curr++;
    int score2=stoi(line.substr(pos, curr++));
    pos=curr;
    string name2=line.substr(pos);

    if(score1>score2){
      result1='W';
      result2='L';
    }else if(score1<score2){
      result1='L';
      result2='W';
    }else{
      result1=result2='D';
    }
    list_insert(name1, score1, result1, score2);
    list_insert(name2, score2, result2, score1);
  }

  if(flag){
  //2.sort by winners
  soccer.sort( [](const Soccer& first, const Soccer& second){
      if(first.point>second.point) return true;
      else if(first.point<second.point) return false;
      else{//compare(2) win
      if(first.win>second.win) return true;
      else if(first.win<second.win) return false;
      else{//compare(3) goal
      if(first.goal>second.goal) return true;
      else if(first.goal<second.goal)return false;
      else{//compare(4) Twin
      if(first.Twin>second.Twin) return true;
      else if(first.Twin<second.Twin) return false;
      else{//compare(5) ground
      if(first.ground<second.ground) return true;
      else if(first.ground>second.ground) return false;
      else{//compare(6) string
      if(first.name.compare(second.name)<0) return true;
      else false;
      }
      }
      }
      }
      }
  ;});

  //3.print
  int test=1;
  auto t = soccer.begin();
  cout<<test<<") "<<t->name<<" "<<t->ground<<"G "<<t->point<<"P "
    <<t->win<<"-"<<t->draw<<"-"<<t->lose
    <<" "<<t->Twin<<"/"<<t->Tlose<<"/"<<t->goal<<endl;
  auto i = soccer.begin();
  i++;
  while(i!=soccer.end()){
    if(same(t, i)) ;
    else test++;
    cout<<test<<") "<<i->name<<" "<<i->ground<<"G "<<i->point<<"P "
     <<i->win<<"-"<<i->draw<<"-"<<i->lose
     <<" "<<i->Twin<<"/"<<i->Tlose<<"/"<<i->goal<<endl;
    t=i++;
  }
  }
  return 0;
}
bool same(list<Soccer>::iterator a, list<Soccer>::iterator b){
  if(a->point==b->point && a->win==b->win && a->goal==b->goal
      && a->Twin == b->Twin && a->ground==b->ground)
    return true;
  else return false;
}
void list_insert(string name, int score1, char  result, int score2){
  bool flag=false;
  for(auto i=soccer.begin();i!=soccer.end();++i){
    if((i->name).compare(name)==0){
      Soccer team = *i;
      team.add(score1, result, score2);
      i= soccer.erase(i);
      soccer.push_back(team);
      flag=true;
      break;
    }
  }
  if(!flag)
    soccer.push_back(Soccer(name, score1,result,score2));
}

