//Direct Memory Manipulation
#include <iostream>
#include <memory>
#include <string>

int main(){
    int *pi = new int;//uninitialized int
    std::string *ps = new std::string;//uninitialized string

    delete pi;
    delete ps;
    delete pi;//error: segfault(alread deleted)
    pi = new int(1024); //object to which pi points has value 1024
    ps = new std::string(10, '9');//9999999999

    std::cout<<*ps<<std::endl;

    auto pi2 = new auto(pi);//pi2 points to the same object to which pi points
    int **pi4 = new auto(pi);//ok
    int* pi3 = new auto(pi);//error

    //Delete
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;

    delete i;//error (i is not a pointer)
    delete pi1;//error(undefined): pi1 refers to a local(not heap)
    delete pd;// ok
    delete pd2;//error(undefined): the momory pointed to by pd2 was freed
    delete pi2;//ok: it is always ok to delete a null pointer
    return 0;
}
