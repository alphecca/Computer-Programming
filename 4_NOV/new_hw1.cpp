#include <iostream>
#include <vector>
using namespace std;
string result;
char arr[26];
vector<string> dic;

bool check(string st){//it also prints
  int i,j;
  for(i=0;i<st.length()&&st.at(i)!=' ';++i) ;
  string tmp=st.substr(0,i);
  if(i<st.length())  st=st.substr(i+1);
  else st="";

//cout<<"[with "<<tmp<<"]"<<endl;
  for(auto it=dic.begin();it!=dic.end();++it){
    bool flag=false;
    string wd=*it;
    vector<char> cc;
    //1
//for(int i=0;i<26;i++) cout<<arr[i]<<"*";
//cout<<endl;
//cout<<"\tcompare "<<wd<<endl;
    if(tmp.length()==wd.length()){
//cout<<"same length"<<endl;
      for(j=0;j<tmp.length();j++){
        if(arr[tmp.at(j)-'a']=='0'){
//cout<<"new alphabet : "<<tmp.at(j)<<endl;
          arr[tmp.at(j)-'a']=wd.at(j);
          cc.push_back(tmp.at(j));
          flag=true;
        }
        else{
//cout<<"already existing alphabet :["<<tmp.at(j)-'a'<<"] "<<arr[tmp.at(j)-'a']<<"*"<<endl;
          if(arr[tmp.at(j)-'a']!=wd.at(j)){
//cout<<"\t\tbut not correct"<<endl;
            flag=false;
            break;
          }
          else flag=true;
        }
      }
      //2
      if(flag){//2 If 1 is alright
        if(st!=""){
          if(check(st)){
            result = wd+" "+result;
            return true;
          }
          else{
            //restore
            for(auto itr=cc.begin();itr!=cc.end();++itr){
              arr[*itr-'a']='0';
            }
            continue;
          }
        }
        else{
          result=wd;
          return true;
        }
      }//if(flag)
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
  if(check(tmp)) cout<<result<<endl;
  else cout<<"mission failure..."<<endl;

  return 0;
}
