#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(int, char**){
  //print floating point
  cout.precision(3);

  //declaration & initialization
  vector<int> int_vector={1,2,3,4};
  vector<int> vector1 = int_vector;
  deque<double> deque1(int_vector.begin(), int_vector.end());
  list<string> list1(3, "a");

  ///assignment & swap
  vector<int> vector2;
  vector2 = {1,2,3,4,5};
  swap(vector1, vector2);

  //adding elements
  vector1.push_back(7);
  deque1.push_front(10.0);
  list1.insert(list1.begin(), 2, "b");

  //accessing elements
  cout<<list1.front()<<" "<<deque1.back()<<" "<<vector1.at(2) <<endl;

  //erasing elements
  vector1.pop_back();
  deque1.pop_front();
  list1.erase(list1.begin());

  for(auto i = vector1.begin(); i!=vector1.end(); ++i){
    cout<<*i<<" ";
  }
  cout<<endl;
  for(auto i = deque1.begin(); i!=deque1.end(); ++i){
    cout<<fixed<<*i<<" ";
  }
  cout<<endl;
  for(auto i = list1.begin(); i!=list1.end(); ++i){
    cout<<*i<<" ";
  }
  cout<<endl;

  return 0;
}

