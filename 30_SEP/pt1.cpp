#include <iostream>

class Market{
  public:
    Market() = default;
    Market(unsigned a) : apple(a){ }
    Market(unsigned a, unsigned b) : apple(a), applePrice(b) { }

    Market &appleSold(){
      apple--;
      return *this;
    }
    Market &sales() {
      std::cout<<apple<<std::endl;
      return *this;
    }
    unsigned getPrice() const;
    unsigned getPrice(unsigned a) const;
  private:
    unsigned apple = 0;
    unsigned applePrice = 39;
};
unsigned Market::getPrice() const{
  return applePrice * 1;
}
unsigned Market::getPrice(unsigned a) const{
  return applePrice * 12;
}

int main(void){
  Market eMart(99);
  Market gs25();
  Market homePlus(107,35);

  std::cout <<eMart.getPrice()<<std::endl;
  std::cout<< eMart.getPrice(12)<<std::endl;
  homePlus.sales().appleSold();
  homePlus.sales();

  return 0;
}
