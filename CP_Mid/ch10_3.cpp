//Insert iterators
vector<int> vec;
auto it = front_inserter(vec);
auto it2= back_inserter(vec);
auto it3= inserter(vec, vec.begin());

fill_n(it3, 10,10);

//Iostream iterators
istream_iterator<int> in_it(cin), eof;
ostream_iterator<int> out_it(cout, " ");

vector<int> vec(in_it, eof);
for(auto e: vec) out_it = e;

//Reverse iterators
vector<int> vec = {1,2,3,4,5};

for(auto r_it = vec.crbegin(); r_it !=vec.crend(); ++r_it)
cout<< *r_it;
