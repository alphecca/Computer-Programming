#include <iostream>
#include <vector>

using namespace std;

class Movie{
  public:
    //constructors
    Movie() : Year(1900), Name("Unknown"){ }
    Movie(int a, string b, vector<string> c):Year(a), Name(b), Actor(c) { }

    //member functions
    int getYear() const { return Year;}
    string getName() const { return Name;}
    string getMainActor() const{return Actor.at(0);}
    string getActor(int index) const{return Actor.at(index-1);}
  private:
    int Year;
    string Name;
    vector<string> Actor;
};

int main(void){
  Movie unknown;
  cout<< unknown.getYear()<<endl; //1900
  cout<<unknown.getName()<<endl;//Unknown

  vector<string> actors {"Uma Thurman", "Luch Liu", "David Carradine"};
  Movie killbill(2003, "Kill Bill", actors);
  cout<<killbill.getYear()<<endl; //2003
  cout<<killbill.getName()<<endl;//Kill Bill
  cout<<killbill.getMainActor()<<endl;//Uma Thurman
  cout<<killbill.getActor(3)<<endl;//David Carradine

  return 0;
}
