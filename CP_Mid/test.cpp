#include <iostream>
#include <vector>
#include <deque>
int main(){
    std::vector<int> v = {1,2,3};
    int size= 3;
    int tmp=4;
    auto begin = v.begin();
    while(begin != v.end()){
        ++begin;
        begin = v.insert(begin,tmp++ );
        ++size;
        ++begin;
    }
    std::cout<<size<<std::endl;
    for(auto it= v.begin();it!=v.end();++it)
            std::cout<<*it<<"\t";

    std::deque<int> dq {1,2,3};
    dq.pop_back();
    dq.pop_front();
    std::cout<<"\n"<<dq.at(0)<<std::endl;
    return 0;
}
