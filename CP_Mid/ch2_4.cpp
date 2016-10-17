//Reference
int i, &ri = i;
i = 5;
ri = 10;
std::cout<<i<<" "<<ri<<std::endl;//10 10

int ival=1024;
int &refVal = ival;
int &refVal2;// error: must be initialized

//Pointer
int ival = 42;
int *p = &ival;
if(pi1 == pi2) ;//equal if they have same address

//Pointer of Pointer
int ival = 1024;
int *pi = &ival;//pi points to an it
int **ppi = &pi;//ppi points to a pointer to an int

std::cout<<ival<<" "<<*pi<<" "<<**ppi<<std::endl;//1024 1024 1024

//Reference of Pointer
int i =42;
int *p;
int *&r = p;//r is a reference to the pointer p
r = &i;//r referes to a pointer assigning &i to r makes p point to i
*r = 0;//dereferencing r yields i, changes i to 0

//Const
const int i=get_size();
const int j=42;
const int k;//error: k is uninitialized const
j=31;//error: attempt to write to const object

int m =42;
const int cn =m;//ok: the value in m is copied into cn
int o = cn;//ok: the value in cn is copied into o

//Const and Reference
const int ci=1024;
const int &r1 = ci;//ok
r1 = 42;//error: r1 is a reference to const
int &r2 = ci;//error: non const reference to a const object

int i =42;
int &r1 = i;
const int &r2 = i;
r1 = 0;//i has value 0
r2 = 0;//error : r2 is a const int

//Const and Pointer
const double pi = 3.14;
double *ptr = &pi;//error : ptr is plain pointer
const double *cptr = &pi;//ok
*cptr = 42;//error : *cptr is const double

int i =0;
int *const p1 = &i;//we cannot change the value of p1
const int ci = 42;
const int *p2 = &ci;//we can change p2, but cannot change ci
const int *const p3 = p2;//we cannot change both p3 and p2
const int &r = ci;//we cannot change ci

//alias of variables
typedef double wages;//wages is a synonym for double
typedef wages base, *p;// base if a synonym for double, p for double*

auto i =0, *p = &i; // ok: is i
auto sz= 0, pi = 3.14;//error : inconsistent types for sz and pi

decltype(f()) sum = x;//sum has whatever types f returns
