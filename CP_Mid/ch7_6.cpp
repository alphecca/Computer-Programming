//Static
static Account{
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);
    private:
        std::string owner;
        double amount;
        static dobule interesetRate;
        static double initRate();
}
double r;
r = Account::rate();//ok: access by ::
Account ac1;
Account *ac2 = &ac1;
r= ac1.rate();//ok: access by instance
r= ac2->rate();//ok: access by instance

//Static declaration
class Account{
    public:
        //static member function definition
        static double rate(){ return interestRate; }
        static void rate(double);
        static double interestRate;
};
//static data member definition
double Account::interestRate =1.2;
//static member function definition
void Account::rate(double newRate){
    interestRate = newRate;
}

//Incomplete Data type of static
class Screen;
class Bar{
    private:
        static Bar mem1;//ok
        Bar *mem2;//ok
        Bar mem3;// error
        Screen mem4;//ok
};
class Screen{
    public:
        Screen& clear(char = bkground);//default argument
        Screen& clear(char = bkground2);//error
    private:
        static const char bkground;
        char bkground2;
};
