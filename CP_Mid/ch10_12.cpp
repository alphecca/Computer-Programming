//Lambda Expression
void print_odd(int *a){
    for(int i=0;i<5;i++)
        if(a[i]%2!=0) cout<<a[i]<<" ";
}
auto func = [](int*a){for(int i=0;i<5;i++) if(a[i]%2!=0) cout<<a[i]<<" ";};

vector<int> vec = {4,3,2,1,0};
sort(vec.begin(), vec.end());//{0,1,2,3,4}
sort(vec.begin(), vec.end(), [](int i1, int i2)->bool{return i1>i2;});
//{4,3,2,1}

//Pass argument to Lambda
int a =5;
auto func = [](int a){cout<<a;};//parameters
auto func2=[a](){cout<<a;};//Introducer captures
auto func3=[&](){a++;};//capture by reference
auto func4=[=](){a++;};//error: capture by value
auto func5=[a](){a++;};//error: capture by value
auto func6=[=]() mutable {a++;};//ok: capture by value
auto func7=[a]() mutable {a++;};//ok

//Lambda returns
int a =7, b=6;
auto func = [=]() mutable {a++; return a;};//ok
auto func2= [&]() -> int {a++; return a;};//ok
auto func3= [=]() mutable {a++;b++;return{a,b};};//error
