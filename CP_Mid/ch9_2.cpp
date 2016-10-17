//Iterator
vector<int> v = {1,2,3,4,5};
vector<int>::iterator begin;
begin = v.begin();
while(begin!=v.end()){
    *begin = *begin+i;
    ++begin;
}
//const_iterator
list<string> a = {"A", "B", "C"};
list<string>::iterator it = a.begin();
list<string>::const_iterator cit= a.cbegin();

*it = "ABC";//ok
*cit= "ABC";//error
list<string>::const_iterator cit = a.begin();//implicit conversion

//Invalidate Iterators

//good example
list<int> lst = {0,1,2,3,4,5,6,7,8,9};
auto it = lst.begin();
while(it!=lst.end()){
    if(*it % 2 !=0){
        it = lst.erase(it);//point to the next element
    }
    else ++it;
}//lst  = {0,2,4,6,8}
//bad example(compile but run time error)
list<int> lst = {0,1,2,3,4,5,6,7,8,9};
auto it = lst.begin();
while(it!=lst.end()){
    if(*it%2!=0){
        lst.erase(it);//now it point to nowhere
        ++it;
    }
}

//good example
vector<int> v= {42};
auto begin = v.begin();
while(begin != v.end()){
    ++begin;
    begin = v.insert(begin,42);
    ++begin;
}
//bad exmpale(error)
vector<int> v ={42};
auto begin= v.begin();
auto end =v.end();
while(begin !=end){
    ++begin;
    begin = v.insert(begin, 42);
    ++begin;
}
