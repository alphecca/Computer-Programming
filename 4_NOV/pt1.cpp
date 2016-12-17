#include <iostream>
#include <vector>
#include <string>
using namespace std;
//TODO const, reference
class Message{
  private:

  public:
    string from;
    string to;
    string text;
    bool fwd;//true if forwarding
    int fwd_num;

    //constructor
    Message(){//default
      from=to=text="";
      fwd=false;
      fwd_num=0;
    }
    Message(string a,string b, string c,string d){
      if(!a.compare("send")){
        from=b;
        to=c;
        text=d;
        fwd=false;
        fwd_num=0;
      }
      if(!a.compare("forward")){
        from=b;
        to=c;
        fwd=true;
        text="";
        fwd_num=stod(d);
      }
    }
};

vector<string> userList;
vector<Message> messageBox;

Message get_recieve(string user, int i){
  int cnt=0;
  Message message;
  for(auto it=messageBox.begin();it!=messageBox.end();++it){
    message=*it;
    if(!user.compare(message.to)){
      ++cnt;
      if(i==cnt){
        if(!message.fwd){
          cout<<"from <"<<message.from<<">: "<<message.text<<endl;
        return message;
        }
        else{
          cout<<"from <"<<message.from<<">: ";
          return get_recieve(message.from, message.fwd_num);
        }
      }
    }
  }
  return Message();
}
void print_message(string user){
  Message message;

  for(auto it=messageBox.begin(); it!=messageBox.end(); ++it){
    message=*it;
    if(!user.compare(message.to)&&!user.compare(message.from)){
      if(!message.fwd){
      cout<<"to <"<<user<<">: "<<message.text<<endl;
      cout<<"from <"<<user<<">: "<<message.text<<endl;
      }
      else{
        cout<<"to <"<<user<<">: ";
        get_recieve(message.from, message.fwd_num);
        cout<<"from <"<<user<<">: ";
        get_recieve(message.from, message.fwd_num);
      }
    }
    else if(!user.compare(message.to) ){
      cout<<"from <"<<message.from<<">: ";
      if(message.fwd){
        get_recieve(message.from, message.fwd_num);
      }
      else{
        cout<<message.text<<endl;
      }
    }
    else if(!user.compare(message.from)){
      cout<<"to <"<<message.to<<">: ";
      if(message.fwd){
        get_recieve(message.from, message.fwd_num);
      }
      else{
        cout<<message.text<<endl;
      }
    }
  }

}
int main(){
  int n, m;

  //1. get Userlist
  cin>>n;
  string a;
  for(int i=0;i<n;i++){
    cin>>a;
    userList.push_back(a);
  }

  //2. get messagebox
  string b[4];
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>b[0]>>b[1]>>b[2]>>b[3];
    Message message =Message(b[0],b[1],b[2],b[3]);
    messageBox.push_back(message);
  }

  //3.Print
  for(auto it=userList.begin(); it!=userList.end(); ++it){
    cout<<"@"<<*it<<endl;
    print_message(*it);
  }
  return 0;
}
