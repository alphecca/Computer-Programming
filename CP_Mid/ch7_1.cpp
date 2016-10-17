//Member Function
class Books_data{
    std::string title = "blahblah";
    double price = 0.0;
        public:
    std::string getTitle() const { return title; }
    double getPrice() const { return this->price; }
};

int main(){
        Books_data book1;
        std::cout<<book1.getTitle()<<" "<<book1.getPrice()<<std::endl;

        return 0;
}

//Return *this
inline Sreen &Screen::move(pos r, pos c ){
    pos row = r* width;
    cursor = row + c;
    return *this;
}
inline Screen &Screen::setValue(char c){
    contents[cursor] = c;
    return *this;
}
myScreen.move(4,0).setValue('#');

//if move returns 'Screen', not 'Screen &'
Screen temp = myScreen.move(4,0);
temp.setValue('#');

//Const member Function
class Screen{
    public:
        Screen &display(){
            return *this;
        }
        const Screen &display() const{
            return *this;
        }
};
Screen screen1;
const Screen screen2;
screen1.setValue('#').display();//ok
screen2.display();//ok

//Examples of Const
Market &print1 (){return *this;}//ok
const Market &print2() const{return *this;}//ok
Market &print3() const { return *this; }//error: cannot convert
const Market &print4() { return *this; }//ok but useless

Market m1;
const Market m2;

m1.print1();//works well
m1.print2();//works well
m1.print4();//works well

m2.print1();//error
m2.print2();//works well
m2.print4();//error
