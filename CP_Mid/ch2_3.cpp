//variable initialization
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);

//variable scope
int reused = 42;//global scope
int main(){
    int reused = 0;
    std::cout<<reused<<" "<<::reused<<std::endl;
    //0 42 
    return 0;
}
