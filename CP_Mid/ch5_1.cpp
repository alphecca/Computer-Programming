//range for
for(auto &r : v)//auto &x || auto const &x
                //NOT auto x
    r *=2;
//same as following
for(auto beg = v.begin(); end !=v.end(); ++beg){
    auto &r = *beg;
    r *= 2;
}

///try catch
while(cin>>item1>>item2){
    try{
        //do something
    }catch (runtime_error err){
        cout<<err.what()<<endl;
    }
}
