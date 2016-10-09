#include <iostream>
#include <string>
#include <string.h>

using namespace std;
#define MAX 502

class BigInteger{
  public:
    //constructor
    BigInteger();
    BigInteger(string str);

    //operator overloading
    BigInteger &operator=(const BigInteger &bi);
    BigInteger &operator+(const BigInteger &bi);
    BigInteger &operator*(const BigInteger &bi);
    void print_int(){
      string str;
      int i=MAX-1;
      bool zero=false;
      while(value[i]==0) i--;
      for(int tmp=i;tmp>=0;tmp--){
        zero=true;
        str+=to_string(value[tmp]);
      }
      if(zero) cout<<str<<endl;
      else cout<<"0"<<endl;
    }
 private:
    int value[MAX];
};
BigInteger::BigInteger(string str){
  int i=0;
  for(int tmp=str.length()-1;tmp>=0;tmp--){
    value[i++]=str.at(tmp)-'0';
  }
  for(i=str.length();i<MAX;i++)
    value[i]=0;
}
BigInteger &BigInteger::operator=(const BigInteger &bi){
  for(int i=0;i<MAX;i++)
    value[i] = bi.value[i];
  return *this;
}
BigInteger &BigInteger::operator+(const BigInteger &bi){
  for(int i=0;i<MAX-2;i++){
    int tmp=value[i]+bi.value[i];
    value[i] = tmp%10;
    value[i+1]=value[i+1]+tmp/10;
  }
  int tmp = value[MAX-2]+bi.value[MAX-2];
  value[MAX-2]=tmp%10;
  value[MAX-1]=value[MAX-1]+(tmp/10)%10;
  return *this;
}
BigInteger &BigInteger::operator*(const BigInteger &bi){
  int result[MAX];
  int partial[MAX];
  int pos=0;
  int carry;
  for(int tmp=0;tmp<MAX;tmp++)
    result[tmp]=partial[tmp]=0;

  for(int i=0;i<MAX/2;i++){
    pos = i;
    carry=0;
    for(int j=0;j<MAX/2;j++){
      carry = partial[pos]+bi.value[i]*value[j];
      partial[pos]= carry%10;
      partial[pos+1] =carry/10;
      pos++;
    }
    for(int k=0;k<MAX;k++){
      int tmp = result[k]+partial[k];
      result[k]=tmp%10;
      if(k!=MAX-1)  result[k+1]=result[k+1]+tmp/10;
      partial[k]=0;
    }
  }
  for(int k=0;k<MAX;k++)
    this->value[k]= result[k];
  return *this;
}

BigInteger multiply(string str);
BigInteger split_add(string str);
bool check_add(string str);
bool check_mul(string str);
int main(){
  string line, input;
  getline(cin, line);

  //trim all the whitespace
  for(int i=0;i<line.length();i++){
    if(line.at(i)==' '||line.at(i)=='\t');
    else input.push_back(line.at(i));
  }

  //calculate
  BigInteger result = split_add(input);
  result.print_int();

  return 0;
}
BigInteger split_add(string str){
  if(check_add(str)){
    int i=0;
    while(str[i]!='+') i++;
    string a = str.substr(0,i);
    BigInteger var1 = multiply(a);
    string b = str.substr(i+1);
    return var1+split_add(b);
  }
  else{
    return multiply(str);
  }
}
BigInteger multiply(string str){
  if(check_mul(str)){
    int i=0;
    while(str[i]!='*') i++;
    string a = str.substr(0,i);
    BigInteger var1 = BigInteger(a);
    string b = str.substr(i+1);
    return var1*multiply(b);
  }
  else{
    return BigInteger(str);
  }
}
bool check_add(string str){
  if(str.find("+")!=string::npos) return true;//+ operator exists
  else return false;
}
bool check_mul(string str){
  if(str.find("*")!=string::npos) return true;//* opearator exists
  else return false;
}

