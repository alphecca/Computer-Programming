//Constructor
//Initializes data members vs assigns values to the data memb.
class ConstRef{
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci;
        int &ri;
};
//iniitializes data member with constructor initializer list
ConstRef::ConsfRef(int ii): i(ii), ci(ii), ri(i) {}
//assigns values to the data member
ConstRef::ConstRef(int ii){
    i=ii;
    ci ==ii;    //error
    ri == i;    //error
}
//initialization
const int a = 1;//ok
//assignment
const int a;
a =1;//error

//Order of member initialization
class X{
    int i;
    int j;
    public:
    X(int val): j(val), i(j) {} //i:undefined j:val
};

//Delegating constructors
class Value{
    public:
        Value(int i, double d):myInt(i), myDouble(d){} 
        Value(): Value(0, 0.0) {}//delegate constructor
        Value(int i): Value(i, 0.0) {}//delegate constructor
    private:
        int myInt;
        double myDouble;
};

int main(){
    Value v1; //0, 0.0
    Value v2(1); //1, 0.0
    Value v3(1, 1.1);// 1, 1.1
}


//Default Constructor
Sales_data obj(); //function
Sales_data obj;//default constructor

//Implicit Class-Type conversion
class Integer{
    public:
        Integer(int i): myInt(i) {}
        int getInt() const { return myInt;}
    private:
        int myInt;
};
int add(const Integer &i1, const Integer &i2){
    return i1.getInt() + i2.getInt();
}

int main(void){
    std::cout <<add(Integer(1), Integer(2)) <<std::endl;//3
    std::cout<<add(1,2)<<std::endl;//ok: print 3(implicit conversion)
}

//Explicit Class-type conversion
class Integer{
    public:
        explicit Integer(int i): myInt(i) {}
        int getInt() const { return myInt;}
    private:
        int myInt;
};
int add(const Integer &i1, const Integer &i2){
    return i1.getInt() + i2.getInt();
}

int main(void){
    std::cout <<add(Integer(1), Integer(2)) <<std::endl;//3
    std::cout<<add(1,2)<<std::endl;//error: cannot convert
}


