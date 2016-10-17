//Declarataion & Initialization

//default constructor
vector<int> v1;// { }
//initializer list
vector<int> v2{1,2,3}; //{ 1,2,3 }
vector<int> v3 = {1,2,3};//{ 1,2,3 }
//copy: same type
vector<int> v4(v2);// { 1,2,3 }
vector<int> v5 = v2; //{ 1,2,3 }
list<int> li = v2;//error :different container type
vector<double> vd = v2; // error :different element type
//iterator initialize(not in array library)
auto b=v2.begin(), e=v2.end();
vector<int> v6(b,e);// { 1,2,3 }
vector<double> vd(b,e);//{1.00000, 2.00000, 3.00000}
list<double> ld(b,e);//{1.00000, 2.00000, 3.00000}
//initialize with # of element(not in array library)
vector<int> v7(3);// { 0, 0, 0}
vector<nonDefaultConstructor> v7(3);//error:
                                    //non built-in type element
                                    //without default constructor
//initialize with # of element & values(not in array library)
vector<int> v8(3,1);//{1,1,1}
vector<nonDefaultConstructor> v8(3, init);//ok:
                                          //non built-int type element
                                          //without default const.but
                                          //with initialize value
//library array initialization
array<int> arr;//error
array<int,10> arr;//ok
array<int,5> ia1;//{0,0,0,0,0}
array<int,5> ia2 = {0,1,2,3,4};//{0,1,2,3,4}
array<int,5> ia3 = {42};//{42,0,0,0,0}
array<int,5> ia4 = ia2;//ok: library array can copy for same type
int builtin1[5] = {0,1,2,3,4};
int buildtin2[5] = builtin1;// error: built-in array cannot copy

//Swap
deque<int> dq1 = {1,2,3,4,5};
dq3={-1,-2,-3};
swap(dq1, dq3);//dq1={-1,-2,-3}, dq3={1,2,3,4,5}

//Assignment
auto b = dq2.begin() +1, e=dq2.end()-1;
dq4.assign(b,e); //dq4 = {2,3,4}
dq5.assign({3,2,1});//dq5={3,2,1}
dq6.assign(3,1);//dq6={1,1,1}

