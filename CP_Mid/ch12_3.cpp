//Unique_ptr
unique_ptr<string> p1(new string("test"));
unique_ptr<string> p2(p1);//error: no copy for unique_ptr
unique_ptr<string> p3;
p3 = p2;//error: no assign for unique_ptr

unique_ptr<string> p2(p1.release());//release makes p1 null
unique_ptr<string> p3(new string("wow"));

p2.reset(p3.release());//transfers ownership from p3 to p2
//string "test"was deleted from the memory

//Weak_ptr
auto p = make_shared<int>(42);
weak_ptr<int> wp(p);//wp weakly shared with p
shared_ptr<int>np = wp.lock();//np shared its object with p
std::cout<<wp.use_count()<<std::endl;//2
