//shared pointer
#include <iostream>
#include <memory>

using namespace std;

int main(){
    shared_ptr<int> a = make_shared<int>(5);
    auto b = make_shared<int>(5);
    auto c = b;//reference count of 42 increased by 1
    auto d(b);//reference count of 42 increased by 1

    b=a;//reference count of 42 decreased by 1
        //reference count of 5 increased by 1

    cout<<b.use_count()<<" "<<a.use_count();
    return 0;
}//a,b,c go out of scope: the memory is automatically freed.


