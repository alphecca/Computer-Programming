//Inline and constexpr
inline const string& shorterString(const string &s1, const string &s2){
    return s1.size()<=s2.size() ? s1: s2;
}

constexpr size_t scale(size_t k){ return 20*k;}


//Function Pointer
bool lengthCompare(const string &a, const string &b);

int main(){
    bool (*pf)(const string&, const string &) = lengthComapre;
    //pointer of bool(const string &, const string &) type function
}
void useBigger(const string&, const string&,
                bool (*pf)(const string & , const string&));
//equivalent expression
void useBigger(const string&, const string&,
                bool pf(const string& const string&)); 

//Member Function Pointer
int Rectangle::area(int width, int height);
void main(){
    int (Rectangle::*pf)(int, int) = &Rectangle::area;
}

