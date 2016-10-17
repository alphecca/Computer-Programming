//overloading
int max(int, int);
int max(int, int, int);
int max(int* arr, int size);

int main(){
    int a = 0;
    int b = 2;
    int c = 3;
    int arr[8] = {2,8,1,6,0,9,7,3};

    cout<<max(a,b)<<endl;//2
    cout<<max(a,b,c)<<endl;//3
    cout<<max(arr,8)<<endl;//9
    return 0;
}
