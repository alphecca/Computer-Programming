#include <iostream>
#include <string>
#include <vector>
#include <set>
#define ull unsigned long long

using namespace std;
typedef vector<vector<ull>> matrix;

set<ull> N1set;
ull mod;
int N1size, N2size;

void fibo(ull *, ull n, int t);
void exist(ull *);

matrix operator*(const matrix& a, const matrix& b){
  int n = a.size();
  matrix c(n,vector<ull>(n));
  for(int i=0; i<n; i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }
      c[i][j] %=mod;
    }
  }
  return c;
}
int main(void){

  cin>>mod;

  //1.Get N1 elements
  cin>>N1size;
  ull N1[N1size];
  int cnt=0;
  while(cnt<N1size){
    ull n;
    cin>>n;
    fibo(&N1[cnt], n,1);
    cnt++;
  }

  //2.Get N2 elements
  cin>>N2size;
  ull N2[N2size];
  cnt=0;
  while(cnt<N2size){
    ull n;
    cin>>n;
    fibo(&N2[cnt], n,2);
    cnt++;
  }

  //3.Compare and print 0 or 1
  exist(N2);

  return 0;
}
void fibo(ull (*item), ull  n, int t){
  matrix A = {{1,0},{0,1}};
  matrix B = {{1,1},{1,0}};

  while(n>0){
    if(n%2==1){
      A=A*B;
    }
    B=B*B;
    n /= 2;
  }
  *item=A[0][1];
  if(t==1)  N1set.insert(A[0][1]);
}
void exist(ull (*arr2)){

  bool flag=true;
  for(int i=0;i<N2size;i++){
    if(N1set.find(arr2[i])==N1set.end()) flag=false;
    cout<<arr2[i]<<" : "<<flag<<endl;
    flag=true;
  }
}
