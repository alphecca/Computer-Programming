//Read-only Algorithms
vector<int> vec, vec2;
int val = 8;
int sum;

for(int i=0;i<10;i++){
    vec.push_back(i);
    vec2.push_back(i);
}

auto result=  find(vec.cbegin(), vec.cend(), val);
sum = accumulate(vec.cbegin(), vec.cend(), 0);
equal(vec.cbegin(), vec.cend(), vec2.cbegin());
cout<<"sum "<<sum<<endl;
//Write Algorithms
vector<int> vec(10), vec2;
fill(vec.begin(), vec.end(), 10);
fill_n(vec.begin(), vec.size(), 10);
fill_n(vec2.bgin(), 10, 10);//error


vector<int> vec;
auto it = back_inserter(vec);
fill_n(it, 10,10);
for(int i=0;i<10;i++) cout<<vec[i];

//Reorder Algorithms
vector<int> vec;
vector<string< str;
//insert elements
for(int i=0;i<5;i++) vec.push_back(i);
vec.push_back(4);
str.push_back("apple"); str.push_back("banana"); str.push_back("pineapple");
str.push_back("apple"); str.push_back("carrot");
sort(vec.begin(), vec.end());
sort(str.begin(), str.end());
auto end_unique =unique(vec.begin(), vec.end());
auto end_unique2=unique(str.begin(), str.end());

//Generic algorithms
void generator(){
    cout<<"Generator";
}
bool predicate(int x){
    cout<<"Unary predicate";
}
bool binary_predicate(int x, int y){
    cout<<"Binary predicate";
}
