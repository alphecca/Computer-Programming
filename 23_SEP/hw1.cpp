#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>

using namespace std;
unordered_map <char, string> wildcard;

string wild(char c , double a, double b );
double postfix(string);
int main(void){

  int WCnum;
  string expression;

  cin>>WCnum;

  for(int i=0;i<WCnum;i++){
    char opr;
    string s;
    cin>>opr>>s;
    wildcard[opr]=s;//make map
  }
  cin>>expression;
  double result = postfix(expression);

  if(-0.0009<result&&result<0.0009) cout<<"0.000"<<endl;
  else{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);
    cout<<result<<endl;
  }

  return 0;
}
string wild(char opr, double a, double b){
  unordered_map<char, string>::const_iterator got = wildcard.find(opr);
  if(got==wildcard.end()) return nullptr;
  else{
    string expression = got->second;
    string tmp1, tmp2;
    for(int i=0;i<expression.length();i++){
      if(expression[i]=='A'){
        tmp1 = expression.substr(0,i);
        tmp2 = expression.substr(i+1);
        expression=tmp1+to_string(a)+tmp2;
      }
      if(expression[i]=='B'){
        tmp1 = expression.substr(0,i);
        tmp2 = expression.substr(i+1);
        expression=tmp1+to_string(b)+tmp2;
      }
    }
    //cout<<"**"<<expression<<endl;
    return expression;
  }
}
double postfix(string str){
  //NOTE :parameter string can have double numbers.
  string expression;
  vector<string> stk1;//ultimately store result value
  vector<string> stk2;//temporary stack for postfix
  bool flag=false;//unary - OR operator -

  /*1.numbers : put pf stack  operators: put stk stack*/
  for(int itr=0; itr<str.length(); ){
    if('0'<=(str.at(itr))&&(str.at(itr))<='9'){
      int pos = itr;
      while('0'<=str[itr]&&str[itr]<='9'||str[itr]=='.'||str[itr]==string::npos){
        itr++;
      }
      string tmp = str.substr(pos, itr-pos);
      expression+=tmp+" ";
      flag =true;
      continue;
    }
    else if(str[itr]==')'){
      //put into stack stk popping all things inside until it meets '('
      if(!stk2.empty()){
        string tmp = stk2.back();
        stk2.pop_back();
        while(!stk2.empty()&&tmp.compare("(")!=0){
          expression+=tmp+" ";
          tmp=stk2.back();
          stk2.pop_back();
        }
      }
      flag = true;
    }
    else if(str[itr]=='('){
      stk2.push_back("(");
      flag = false;
    }
    else if(str[itr]=='+'){
      if(!stk2.empty()){
        while(!stk2.empty()&&stk2.back().compare("(")!=0){
          expression+=stk2.back()+" ";
          stk2.pop_back();
        }
      }
      stk2.push_back("+");
      flag = false;
    }
    else if(str[itr]=='-'){
      if(flag){//operator minus
        if(!stk2.empty()){
          while(!stk2.empty()&&stk2.back().compare("(")!=0){
            expression+=stk2.back()+" ";
            stk2.pop_back();
          }
        }
        stk2.push_back("-");
        flag = false;
      }
      else{//unary minus
        stk2.push_back(".");
        flag =false;

      }
    }
    else if(str[itr]=='*'||str[itr]=='/'){
      if(!stk2.empty()){
        while(!stk2.empty()&&stk2.back().compare("(")!=0&&stk2.back().compare("+")!=0&&stk2.back().compare("-")!=0){
          expression+=stk2.back()+" ";
          stk2.pop_back();
        }
      }
      if(str[itr]=='*') stk2.push_back("*");
      else stk2.push_back("/");
      flag = false;
    }

    else{//wildcard
      if(!stk2.empty()){
        while(!stk2.empty()&&stk2.back().compare("(")!=0&&stk2.back().compare("+")!=0&&stk2.back().compare("-")!=0){
          expression += stk2.back()+" ";
          stk2.pop_back();
        }
      }
      string test;
      test+= str[itr];
      stk2.push_back(test);
      flag=false;
    }
    itr++;

  }

  while(!stk2.empty()){
    expression+=stk2.back()+" ";//pop all remaining opeartors
    stk2.pop_back();
  }
  //cout<<"string is "<<expression<<endl;

  /*2.Calculate values in string expression
   **/
  std::size_t sz;
  std::size_t pos;
  pos = 0;

  while(!expression.empty()){
    sz=expression.find(" ");
    if(sz!=string::npos){
      string tmp = expression.substr(pos,sz-pos);
      char test=tmp.at(0);
      if(test=='0'||test=='1'||test=='2'||test=='3'||test=='4'||test=='5'||test=='6'||test=='7'||test=='8'||test=='9'){
        stk1.push_back(tmp);
      }
      else if(tmp.compare("+")==0){
        double B = atof(stk1.back().c_str());
        stk1.pop_back();
        double A = atof(stk1.back().c_str());
        stk1.pop_back();
        stk1.push_back(to_string(A+B));
      }
      else if(tmp.compare("-")==0){
        double B =atof(stk1.back().c_str());
        stk1.pop_back();
        double A =atof(stk1.back().c_str());
        stk1.pop_back();
        stk1.push_back(to_string(A-B));
      }
      else if(tmp.compare("/")==0){
        double B =atof(stk1.back().c_str());
        stk1.pop_back();
        double A =atof(stk1.back().c_str());
        stk1.pop_back();
        stk1.push_back(to_string(A/B));
      }
      else if(tmp.compare("*")==0){
        double B = atof(stk1.back().c_str());
        stk1.pop_back();
        double A = atof(stk1.back().c_str());
        stk1.pop_back();
        stk1.push_back(to_string(A*B));
      }
      else if(tmp.compare(".")==0){//unary minus
        double A = atof(stk1.back().c_str());
        A*=-1;
        stk1.pop_back();
        stk1.push_back(to_string(A));
      }
      else{//wild card
        char opr = tmp.at(0);
        double B = atof(stk1.back().c_str());
        stk1.pop_back();
        double A = atof(stk1.back().c_str());
        stk1.pop_back();
        stk1.push_back(to_string(postfix(wild(opr, A, B))));
      }
    }//end of if
    if(sz==expression.length()-1) break;
    else expression = expression.substr(sz+1);
  }//end of while
  double result = atof( stk1.back().c_str());
//      cout<<"*"<<result<<endl;
  return atof(stk1.back().c_str());
}




