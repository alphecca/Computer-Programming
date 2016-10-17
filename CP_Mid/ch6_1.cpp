int func(int a){
    a -=10;
    return a;
}
void func2(int* a){
    *a = -10;
    a = 0;
}
int main(){
    int k =10;
    int l = func(k);
    std::cout<<k<<std::endl;//10
    int *p = &k;
    func2(p);
    std::cout<< k<<std::endl;//-10
    return 0;
}
