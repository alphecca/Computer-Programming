//Relational operator
vector<int> v1 = {1,3,5,9,12};
vector<int> v2 = {1,3,9};
vector<int> v3 = {1,3,5,7};
vector<int> v4 = {1,3,5,7,9,12};
v1<v2;//true
v1<v3;//false
v1==v4;//true
v1==v2;//false

//Adding elements
deque<int> dq{1,2,3};
dq.push_back(4); //{1,2,3,4}
dq.push_front(5);//{5,1,2,3,4}

class Person{
    public:
        Person(string _name, int _age): name(_name), age(_age) {}
        string name;
        int age;
};
vector<Person> persons;
persons.emplace_back("Adam", 23);
//same as
persons.push_back(Person("Adam", 23));

list<int> slist={1,2};
auto it = slist.begin();
it = slist.insert(it, 5);//slist=={5,1,2}
it = slist.insert(it, 2,6);//slist=={6,6,5,1,2}
it = slist.insert(it, {7,8});//slist=={7,8,6,6,5,1,2}

//Accessing elements
vector<int> v= {1,2,3};
auto val1 = *v.begin();//val1 = ==1
auto val2 = v.front();//val2 ==1
auto last = v.end();
val3 = *(--last);//val3 ==3
val4 = v.back();// val4 ==3

std::cout<<v[4];//run-time error
std::cout<<v.at(4);//out_of_range exception

//Erasing elements
deque<int> dq{1,2,3};
dq.pop_back();//{1,2}
dq.pop_front();//{2}

list<int> lst = {0,1,2,3,4,5,6,7,8,9};
auto it = lst.begin();
while(it!= lst.end()){
    if(*it %2 !=0)
        it= lst.erase(it);
    else ++it;
}//lst={0,2,4,6,8}

//Resize
list<int> lst(5,42);//{42,42,42,42,42}
lst.resize(8);//{42,42,42,42,42,42,0,0,0}
lst.resize(10,-1);//{42,42,42,42,42,0,0,0,-1,-1}
lst.resize(3);//{42,42,42}

//Reseve
vector<int> v;

for(auto i=0;i<=24;++i) 
        v.push_back(i);
cout<<v.size()<<" "<<v. capacity() <<endl;
//24 32(or else)

v.resize(30);
v.reserve(100);
cout<<v.size()<<" "<<v.capacity()<<endl;
//30 100



