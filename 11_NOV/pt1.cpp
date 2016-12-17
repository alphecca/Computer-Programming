#include <iostream>
#include <string>
#include <vector>
using namespace std;
class UIElement {
  private:
  public:
  string Name;//set element's name or get
};
class FrameworkElement: public UIElement {
  private:
  public:
  double Width;
  double Height;
  double OffsetLeft;
  double OffsetTop;
  int GridCol=1;
  int GridRow=1;
  virtual void UpdateLayout() {};
  //constructor
  FrameworkElement():Width(100),Height(100),OffsetLeft(0),OffsetTop(0){}
};
class Panel: public FrameworkElement {
  protected:
  vector<FrameworkElement*> Children;
  public:
  void Add(FrameworkElement* child){
    Children.push_back(child);
  }
  FrameworkElement* Find(string name);
};
class Grid: public Panel{
  public:
  vector<int> Cols{1};//Ratio of Cols in Grid
  vector<int> Rows{1};//Ratio of Rows in Grid
  void UpdateLayout();//updates:width,height,offsetleft,offsettop
};
class Shapes: public FrameworkElement{
};
class Rectangle: public Shapes{
  public:
  string Fill;//RGB code values
};
int main(){
  return 0;
}
