#include <stdio.h>
#define range 10000

using namespace std;

int main(void){
  int N, t, i;
  int arr[range];//initialize to zero
  for(i=0;i<range;i++) arr[i]=0;
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", &t);
    ++arr[t-1];
  }
  for(i=0;i<range;i++){
    while(arr[i]>0){
      printf("%d\n", i+1);
      --arr[i];
    }
  }
 return 0;
}
