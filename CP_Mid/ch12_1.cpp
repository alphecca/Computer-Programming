//make_shared<>
#include <iostream>
#include <memory>
int main(){
    std::shared_ptr<int> foo = std::make_shared<int>(10);
    std::shared_ptr<int> foo2(new int(10));//same as
    std::shared_ptr<int> foo3(std::make_shared<int>(10));//same as

    auto bar = std::make_shared<int> (20);
    auto baz = std::make_shared<std::pair<int, int>>(30,40);

    std::cout<<*foo<<std::endl;
    std::cout<<*bar<<" "<<baz->first<<" "<<baz->second<<std::endl;
    return 0;
}

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
    return 0;
}//a,b,c go out of scope: the memory is automatically freed.

//Copmarison with new&delete
#include <iostream>
#include <memory>
using namespace std;

int *create1(){
    return new int(3);
}
shared_ptr<int> create2(){
    return make_shared<int> (3);
}
int main(){
    int *p1 = create1();
    shared_ptr<int> p2 = create2();

    delete p1;
    return 0;
    //p2 is automatically freed
}

//New & Shared_ptr
shared_ptr<int> clone(int p){
    return new int(p);//error
    return shared_ptr<int>(new int(p));
}
void process(shared_ptr<int> ptr){
    //do something
}//ptr goes out of scope and is destroyed

int main(){
    shared_ptr<int> p1 = new int(1024);//error: must use direct initialization
    shared_ptr<int> p2(new int(1024));//ok

    int *x= new int(5);
    process(shared_ptr<int>(x));
    //the memory will be deleted after function call

    int j = *x;//undefined: x is a dangling pointer
    return 0;
}

//Shared_ptr.get()
shared ptr<int> p(new int(42));//reference count is 1
int *q = p.get();//ok: but don't use q in any way that might delete its pointer
{
    shared_ptr<int>(q);//undefined: two independent shared_ptrs point to the same memory
}//block ends, q is destroyed, and the memory to which q points is freed
int foo = *p;//undefined: memory to which p point was freed

//shared_ptr.reset()
shared_ptr<int> p(new int(1));
p=new int(2);//error:cannot assign a pointer to a shared_ptr
p.reset(new int(3));//ok: p points to a new object 3
//and deletes the old object (1) from the memory since its ref.count becomes 0.
