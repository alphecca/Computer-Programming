#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <array>
using namespace std;

//This is function
void simple_function(){
  cout <<"Simple Functor"<<endl;
}
int main (void){
  int a =10, b=1000;
  //I'm function pointer!
  void(*pf) () = simple_function;
  //Simple Lambda function
  [] () {cout<<"Simple Lambda function!"<<endl;} ();
  //Pass by parameter
  auto lambda_p = [](int a, int b){cout <<"A is "<<a << endl;
                                cout<<"B is "<< b <<endl;};
  //Capture by value
  [=] () {cout<<"Capture by value!"<<" "<<a <<" "<<b <<endl;}();
  //Capture by reference
  [&] () {a +=1; b+=1; cout<<"Capture by reference!"<<" "<<a <<" "<<b<< endl;}();
  //Mutable can modify value
  [=] () mutable {a+=1; b+=1; cout<<"Mutable!"<<" "<<a <<" "<<b <<endl;}();
  //Return type
  auto sum_lambda = [=] () ->int {return a+b;}();
  cout<<sum_lambda<<endl;
  //If you omit return type Compiler automatically guess return type
  auto sum_lambda2  = [=] (){return a+b;}();
  cout<<sum_lambda2 <<endl;

  return 0;
}
