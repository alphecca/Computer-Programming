#include <iostream>

#include <memory>
using namespace std;

void f(shared_ptr<int> k){
  return;
}

int main(void){
  //shared count
  shared_ptr<int> p0(new int(1));
  cout<<p0.use_count()<<endl;

  shared_ptr<int> p1(p0);
  cout<<p0.use_count()<<endl;

  weak_ptr<int> p2(p0);
  cout<<p0.use_count()<<endl;

  p0.reset(new int(3));
  cout<<p0.use_count()<<endl;

  //be careful
  int* p3= p0.get();
  if((shared_ptr<int>)p3);//memory p0 points to is freed

  //unique_ptr
  unique_ptr<int> p4(new int(3));
  unique_ptr<int> p5(new int(4));
  cout<<*p4<<" "<<*p5<<endl;

  //unique_ptr<int> p6(p4);
  unique_ptr<int> p6(p4.release());
  cout<<*p6<<endl;

  return 0;
}
