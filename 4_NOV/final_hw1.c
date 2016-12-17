#include <iostream>
#include <vector>
using namespace std;
string result;
char arr[26];
vector<string> dic;

char check1(char ch1){//tmp, wd

  for(int i=0;i<26;i++){
    if(arr[i]==ch1){
//cout<<"[check1] return "<<(char)(i+'a')<<endl;
      return (char)(i+'a');
    }
  }
  return '0';
}
bool decode(string st){//it also prints
  int i,j;
  for(i=0;i<st.length()&&st.at(i)!=' ';++i) ;
  string tmp=st.substr(0,i);
//cout<<"tmp is : "<<tmp<<endl;
  if(i<st.length())  st=st.substr(i+1);
  else st="";

  for(auto it=dic.begin();it!=dic.end();++it){
    bool flag=false;
    string wd=*it;
//cout<<"wd is : "<<wd<<endl;
    vector<char> cc;
    //1
    if(tmp.length()==wd.length()){
      for(j=0;j<wd.length();j++){
        if(check1(tmp.at(j))==wd.at(j)){
// cout<<"case1 "<<endl;
          flag=true;
        }
        else if(check1(tmp.at(j))!='0'){
// cout<<"case2 "<<endl;
          flag=false;
          break;
        }
        else{
          if(arr[wd.at(j)-'a']!='0'){
// cout<<"case3 "<<endl;
            flag=false;
            break;
          }
          else{
// cout<<"case4 "<<endl;
            flag=true;
            cc.push_back(wd.at(j));
            arr[wd.at(j)-'a']=tmp.at(j);
          }
        }
      }

      //2
      if(flag){// If 1 is alright
        if(st.length()>0){
          if(decode(st)){
            result=wd+" "+result;
            return true;
          }
          else{
            for(auto itr=cc.begin();itr!=cc.end();++itr)
              arr[*itr-'a']='0';
          }
        }
        else{
          result=wd;
          return true;
        }
      }//if(flag)
      else{
        for(auto itr=cc.begin();itr!=cc.end();++itr)
          arr[*itr-'a']='0';
      }
    }
  }

  return false;
}
int main(){
  for(int i=0;i<26;i++)
    arr[i]='0';
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string wd;
    cin>>wd;
    dic.push_back(wd);
  }

  string tmp;
  cin.ignore(256,'\n');
  getline(cin, tmp);
  if(decode(tmp)) cout<<result<<endl;
  else cout<<"mission failure..."<<endl;

  return 0;
}
