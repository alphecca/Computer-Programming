//Type Conversion
bool b=42;//b is true;
int i = b;//i has value 1;
i = 3.14;//i has value 3;
double pi = i;// pi has value 3.0;

unsigned char c =-1;//assuming 8-bit chars, c has value 255
                    //in 2's compl., -1 is 11111111
signed cahr c2 = 256;//assuming 8-bit chars, c2 is undefined

//Implicit Class-type Conversion
class Integer{
    public:
        Integer(int i): myInt(i){}
        int getInt() const { return myInt; }
    private:
        int myInt;
};
int add(const Integer &i1, const Integer &i2){
    retturn i1.getInt() + i2.getInt();
}
int main(void){
    cout<<add(Integer(1),  Integer(2))<<endl;
    cout<<add(1,2) <<endl;//this is okay
}
//Explicit Class-type Conversion
class Integer{
    public:
        explicit Integer(int i): myInt(i){}
        int getInt() const {return myInt;}
    private:
        int myInt;
};
int add(const Integer &i1, const Integer &i2){
    retturn i1.getInt() + i2.getInt();
}
int main(void){
    cout<<add(Integer(1),  Integer(2))<<endl;
    cout<<add(1,2) <<endl;//error: cannot convert
}
