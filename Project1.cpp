#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string keywd;//select/selectAll
class CSV{
  private:
  public:
    //member fucntion
    int idx;
    vector<pair<string, string>> d_field;//Category-Type(order should be preserved)
    map<string, string> csvlist;
    //constructor
    CSV():idx(1){}//default
    CSV(string filename, int i){
      idx=i;
      bool flag=true;
      ifstream FILE;
      FILE.open(filename);
      string tmp;
      while(getline(FILE,tmp)){
        if(flag){
          flag=false;
          string tmp2;
          int i,k,pos1=0,pos2=0;
          getline(FILE,tmp2);
          while(true){
            for(i=pos1;i<tmp.length()&&tmp.at(i)!=',';i++);
            for(k=pos2;k<tmp2.length()&&tmp2.at(k)!=',';k++);
            d_field.push_back(pair<string,string>(tmp.substr(pos1,i-pos1),tmp2.substr(pos2,k-pos2)));
            pos1=i+1;
            pos2=k+1;
            if(pos1>=tmp.length()||pos2>=tmp2.length()) break;
          }
        }else{
          string key, value;
          int i;
          for(i=0;i<tmp.length()&&tmp.at(i)!=',';i++);
          key=tmp.substr(0,i);
          if(i+1<tmp.length()) value=tmp.substr(i+1);
          csvlist.insert(pair<string,string>(key,value));
        }
      }
      FILE.close();
    }
};

class SVG{
  public:
    string tag;
    map<string,string> attribute;
    bool selected;
    vector<SVG*> children;
    SVG* parent;
    bool binding;
    int bind_idx;
    pair<string,string> bind_info;

    //member function
    void append(SVG*);
    void select(string);//selectAll(string) also included.
    void cattr(string, string);
    void enter(CSV&, int);
    void update(CSV&, int);
    void exiting(CSV&, int);
    //constructor
    SVG(){
      selected=false;parent=nullptr;binding=false;
    }//default forDUMM
    SVG(string input,bool flag){
      tag=input; selected=flag; parent=nullptr ;binding=false;
    }
    SVG(string input,bool flag,pair<string,string> info,int idx){
      tag=input; selected=flag; bind_idx=idx; bind_info=info; binding=true;
    }
};
vector<SVG*> result;
void printing(SVG, string, bool);
int main(int argc, char *args[]){
  //CSV
  vector<CSV> csv_list;
  for(int i=1;i<argc;i++)
    csv_list.push_back(CSV(args[i],i));
  //SVG
  SVG dummy;
  SVG* cursor=&dummy;//refers to selection scope-points at parent
  SVG root;
  root.selected=true;
  dummy.children.push_back(&root);
  root.parent=&dummy;
  bool root_flag=true;

  while(true){
    string cmd;
    cin>>cmd;
    if(!cmd.compare("append")){
      string tmp;
      cin>>tmp;
      if(root_flag){
        root.tag=tmp;
        root.selected=true;
        root.children.clear();
        root_flag=false;
      }else{
        SVG* svg=new SVG(tmp,true);
        for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr){
          if((*itr)->selected){
            (*itr)->append(svg);
            cursor=(*itr);
            break;
          }
        }
      }
    }else if(!cmd.compare("select")||!cmd.compare("selectAll")){
      cin>>keywd;
      for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr){
          if((*itr)->selected){
            (*itr)->select(keywd);
            cursor=(*itr);
            break;
          }
      }
    }else if(!cmd.compare("remove")){
      for(auto itr=cursor->children.begin();itr!=cursor->children.end(); ){
        if((*itr)->selected){
          itr=cursor->children.erase(itr);
        }
        else ++itr;
      }
      cursor->selected=true;
      cursor=(cursor->parent);
    }else if(!cmd.compare("end")){
      if(cursor==nullptr){
        break;
      }
      else{
        for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr)
          if((*itr)->selected)
            (*itr)->selected=false;
        cursor->selected=true;
        cursor=(cursor->parent);
      }
    }else if(!cmd.compare("cattr")){
      string tmp1, tmp2;
      cin>>tmp1>>tmp2;
      for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr){
        if((*itr)->selected){
          (*itr)->cattr(tmp1,tmp2);
        }
      }
    }else if(!cmd.compare("tattr")){
      float tmp1, tmp2;
      cin>>tmp1>>tmp2;
      int cnt=0;
      for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr){
        if((*itr)->selected){
          string result="translate(";
          result+=to_string(tmp1*cnt);
          result+=",";
          result+=to_string(tmp2*cnt);
          result+=")";
          (*itr)->cattr("transform",result);
          cnt++;
        }
      }
    }else if(!cmd.compare("dattr")){
      string tmp;
      getline(cin, tmp);
      tmp=tmp.substr(1);
      size_t found= tmp.find(' ');
      string att_name=tmp.substr(0,found);
      tmp=tmp.substr(found+1);
      int k,cnt;
      for(k=0;k<tmp.length()&&tmp.at(k)!=' ';k++) ;

      if(k==tmp.length()){//string
        string dat_value=tmp.substr(0,k);
        string att_value;
        for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr){
          if((*itr)->selected){
            vector<pair<string,string>> tmp =csv_list.at(((*itr)->bind_idx)-1).d_field;
            cnt=1;
            for(auto aa=tmp.begin();aa!=tmp.end();++aa){
              if(!aa->first.compare(dat_value)) break;
              else cnt++;
            }
            if(cnt==1){
              att_value=(*itr)->bind_info.first;
            }else{
              string ss=(*itr)->bind_info.second;
              int pos=0;
              int cnt2=2;
              int ww=1;
              int tt;
              while(true){
                for(tt=ww;tt<ss.length()&&ss.at(tt)!=',';++tt);
                ww=tt+1;
                  if(cnt2==cnt){
                    att_value=(ss.substr(pos,tt-pos));
                    break;
                  }else{
                    pos=tt+1;
                    cnt2++;
                  }
              }
            }
            (*itr)->cattr(att_name, att_value);
          }
        }
      }else{//double
        double mul,add,att_value;
        mul=add=att_value=0;
        string df_name=tmp.substr(0,k);
        tmp=tmp.substr(k+1);

        for(k=0;k<tmp.length()&&tmp.at(k)!=' ';k++) ;
        mul=stod(tmp.substr(0,k));
        if(k<tmp.length()){
          tmp=tmp.substr(k+1);
          for(k=0;k<tmp.length()&&tmp.at(k)!=' ';k++) ;
          add=stod(tmp.substr(0,k));
        }

        for(auto itr=cursor->children.begin();itr!=cursor->children.end();++itr){
          if((*itr)->selected){
            vector<pair<string,string>> tmp =csv_list.at(((*itr)->bind_idx)-1).d_field;
            int cnt=1;
            for(auto aa=tmp.begin();aa!=tmp.end();++aa){
              if(!aa->first.compare(df_name)) break;
              else cnt++;
            }
            if(cnt==1){
              att_value=stod((*itr)->bind_info.first)*mul+add;
            }else{
              string ss=(*itr)->bind_info.second;
              int cnt2=2;
              int pos=0;
              int tt,ww;
              ww=1;
              while(true){
                for(tt=ww;tt<ss.length()&&ss.at(tt)!=',';++tt) ;
                ww=tt+1;
                if(cnt2==cnt){
                  att_value=stod(ss.substr(pos,tt-pos));
                  break;
                }else{
                  pos=tt+1;
                  cnt2++;
                }
              }
              att_value=att_value*mul+add;
            }
            (*itr)->cattr(att_name, to_string(att_value));
          }
        }
      }
    }else if(!cmd.compare("enter")){
      int idx;
      cin>>idx;
      CSV csv=csv_list.at(idx-1);
      cursor->enter(csv, idx);
    }else if(!cmd.compare("update")){
      int tmp;
      cin>>tmp;
      CSV csv=csv_list.at(tmp-1);
      cursor->update(csv, tmp);
    }else if(!cmd.compare("exit")){
      int tmp;
      cin>>tmp;
      CSV csv=csv_list.at(tmp-1);
      cursor->exiting(csv, tmp);
    }else if(!cmd.compare("print")){
      string tmp;
      cin>>tmp;
      ofstream outfile(tmp);
      outfile.close();
      printing(root, tmp, true);
    }else cout<<"Wrong command"<<endl;
  }
  return 0;
}
////////////////SVG class member functions/////////////////////////
void SVG::append(SVG* svg){
  this->children.push_back(svg);
  svg->parent=this;
  this->selected=false;
}
void SVG::select(string tag){
  for(auto itr=this->children.begin();itr!=this->children.end();++itr){
    string tag_origin=(*itr)->tag;
    if(!tag.compare(tag_origin)){
      (*itr)->selected=true;
    }}
  this->selected=false;
}
void SVG::enter(CSV& csv, int idx){
  string type=csv.d_field.at(0).second;
  if(type==("string")){
    map<string,SVG*> m1;
    map<string,SVG*> m2;
    for(auto itr=this->children.begin();itr!=children.end();++itr){
      if((*itr)->selected){
        m1.insert(pair<string, SVG*>((*itr)->bind_info.first,(*itr)));
        (*itr)->selected=false;
      }
    }

    for(auto it=csv.csvlist.begin();it!=csv.csvlist.end();++it){
      if(!m1[(*it).first]){//not exist
        SVG* svg=new SVG(keywd, true, (*it), idx);
        m2[(*it).first]=svg;
      }
    }
    for(auto itr=m2.begin();itr!=m2.end();++itr){
      this->children.push_back((*itr).second);
      (*itr).second->parent=this;
    }
  }else{//type=="float"||type=="int"
    map<double, SVG*> m1;
    map<double, SVG*> m2;
    for(auto itr=this->children.begin();itr!=children.end();++itr){
      if((*itr)->selected){
        m1.insert(pair<double, SVG*>(stod((*itr)->bind_info.first),(*itr)));
        (*itr)->selected=false;
      }
    }
    for(auto it=csv.csvlist.begin();it!=csv.csvlist.end();++it){
      if(!m1[stod((*it).first)]){//not exist
        SVG* svg=new SVG(keywd, true, (*it),idx);
        m2[stod((*it).first)]=svg;
      }
    }
    for(auto itr=m2.begin();itr!=m2.end();++itr){
      this->children.push_back((*itr).second);
      (*itr).second->parent=this;
    }
  }
  result.clear();

}
void SVG::cattr(string att_name, string att_value){
  bool flag=true;
  for(auto itr=this->attribute.begin();itr!=this->attribute.end();++itr){
    pair<string,string> curr=*itr;
    if(!curr.first.compare(att_name)){
      flag=false;
      itr->second=att_value;
    }
  }
  if(flag){//new attribute
    this->attribute.insert(this->attribute.end(),pair<string,string>(att_name, att_value));
  }

}
void printing(SVG svg,string output,bool flag){
  ofstream outFILE(output,ios_base::app);
  if(flag) outFILE<<"<html>"<<endl;
  outFILE<<"<"<<svg.tag;
  for(auto itr_a=svg.attribute.begin();itr_a!=svg.attribute.end();++itr_a){
    outFILE<<" "<<itr_a->first<<"=\""<<itr_a->second<<"\"";
  }
  outFILE<<">"<<endl;
  for(auto itr=svg.children.begin();itr!=svg.children.end();++itr){
    printing(*(*itr), output,false);
  }
  outFILE<<"</"<<svg.tag<<">"<<endl;
  if(flag) outFILE<<"</html>"<<endl;
  outFILE.close();
}
void SVG::update(CSV& csv, int idx){
 for(auto itr=this->children.begin();itr!=this->children.end();++itr){
   if((*itr)->selected){
     (*itr)->selected=false;
     for(auto itr_csv=csv.csvlist.begin();itr_csv!=csv.csvlist.end();++itr_csv){
       string ID_csv=itr_csv->first;
       if(!(*itr)->bind_info.first.compare(ID_csv)){//update
         (*itr)->bind_info.second=itr_csv->second;
         (*itr)->selected=true;
         break;
       }
     }
   }
 }
}
void SVG::exiting(CSV& csv, int idx){
 for(auto itr=this->children.begin();itr!=this->children.end();++itr){
   if((*itr)->selected){
     bool flag=true;
     (*itr)->selected=false;
     for(auto itr_csv=csv.csvlist.begin();itr_csv!=csv.csvlist.end();++itr_csv){
       string ID_csv=itr_csv->first;
       if(!(*itr)->bind_info.first.compare(ID_csv)){
         flag=false;
         break;
       }
     }
     if(flag) (*itr)->selected=true;
   }
 }
}
