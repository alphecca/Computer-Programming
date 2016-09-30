#include <iostream>

using namespace std;

int max(int , int);//max of 2 integers
int max(int , int , int );//max of 3 integers
int max(int* arr, int size);//max element of array

int main(void){
  int a =0;
  int b =2;
  int c =3;

  int arr[8] = { 2, 0 , 1 , 6 , 0 , 9 , 2, 3};

  cout << max(a, b)<<endl;
  cout << max(a, b, c) <<endl;
  cout << max (arr, 8) <<endl;
  return 0;
}

int max(int a, int b){
  if(a>=b) return a;
  else return b;
}

int max(int a, int b, int c){
  int tmp;
  if(a>=b) tmp = a;
  else tmp = b;

  if(tmp<c) tmp = c;
  return tmp;
}

int max(int* arr, int size){
  int value=  arr[0];
  for(int tmp=0;tmp<size;tmp++){
    if(arr[tmp]>value) value = arr[tmp];
  }
  return value;
}
