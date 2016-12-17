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
  FrameworkElement(){
    Width=100;
    Height=100;
    OffsetLeft=0;
    OffsetTop=0;
  }
};
class Panel: public FrameworkElement {
  private:
  protected:
  vector<FrameworkElement*> Children;
  public:
  void Add(FrameworkElement* child);
  FrameworkElement* Find(string name);
  friend void printing(FrameworkElement*);
};
class Grid: public Panel{
  private:
  public:
  vector<int> Cols{1};//Ratio of Cols in Grid
  vector<int> Rows{1};//Ratio of Rows in Grid
  void UpdateLayout();//updates:width,height,offsetleft,offsettop
};
class Shapes: public FrameworkElement{
};
class Rectangle: public Shapes{
  private:
  public:
  string Fill;//RGB code values
  //constuctor
};

void printing(FrameworkElement* root_grid);//for debugging
int main(){
  vector<string> rectangle_order;

  int n;
  cin>>n;
  string tmp,cmd,name;
  //enter root_grid
  cin>>tmp>>tmp>>name>>tmp;
  FrameworkElement* root_grid=new Grid();//default
  root_grid->Name=name;
  while(tmp.compare("end")){
    if(!tmp.compare("Cols")){
      dynamic_cast<Grid*>(root_grid)->Cols.pop_back();
      int m, colnum;
      cin>>m;
      while(m--){
        cin>>colnum;
        dynamic_cast<Grid*>(root_grid)->Cols.push_back(colnum);
      }
    }//end of Cols
    if(!tmp.compare("Rows")){
      dynamic_cast<Grid*>(root_grid)->Rows.pop_back();
      int m, rownum;
      cin>>m;
      while(m--){
        cin>>rownum;
        dynamic_cast<Grid*>(root_grid)->Rows.push_back(rownum);
      }
    }
    cin>>tmp;
  }

  //enter inputs
  for(int i=1;i<n;i++){
    cin>>cmd>>tmp>>name>>tmp;
    if(!cmd.compare("Grid")){
      FrameworkElement* grid = new Grid();
      dynamic_cast<Grid*>(grid)->Name=name;
      while(tmp.compare("Parent")){
        if(!tmp.compare("Cols")){
          dynamic_cast<Grid*>(grid)->Cols.pop_back();
          int m, colnum;
          cin>>m;
          while(m--){
            cin>>colnum;
            dynamic_cast<Grid*>(grid)->Cols.push_back(colnum);
          }
        }
        if(!tmp.compare("Rows")){
          dynamic_cast<Grid*>(grid)->Rows.pop_back();
          int m,rownum;
          cin>>m;
          while(m--){
            cin>>rownum;
            dynamic_cast<Grid*>(grid)->Rows.push_back(rownum);
          }
        }
        cin>>tmp;
      }
      string parent_name;
      cin>>parent_name>>tmp;
      while(tmp.compare("end")){
        if(!tmp.compare("Col")){
          cin>>grid->GridCol;
        }
        if(!tmp.compare("Row")){
          cin>>grid->GridRow;
        }
        cin>>tmp;
      }
      if(!parent_name.compare((root_grid)->Name)){
        dynamic_cast<Grid*>(root_grid)->Add(grid);
      }
      else{
        dynamic_cast<Grid*>(dynamic_cast<Grid*>(root_grid)->Find(parent_name))->Add(grid);
      }
    }
    else if(!cmd.compare("Rectangle")){
      Rectangle* rec = new Rectangle();
      rec->Name=name;
      rectangle_order.push_back(name);
      string fill;
      cin>>fill;
      rec->Fill=fill;
      string parent_name;
      cin>>tmp>>parent_name>>tmp;
      while(tmp.compare("end")){
        if(!tmp.compare("Col")){
          cin>>rec->GridCol;
        }
        if(!tmp.compare("Row")){
          cin>>rec->GridRow;
        }
        cin>>tmp;
      }
      if(!parent_name.compare((root_grid)->Name)){
          dynamic_cast<Grid*>(root_grid)->Add(rec);
      }
      else{
        if(dynamic_cast<Grid*>(root_grid)->Find(parent_name)==nullptr);
        else{
          dynamic_cast<Grid*>(dynamic_cast<Grid*>(root_grid)->Find(parent_name))->Add(dynamic_cast<FrameworkElement*>(rec));
        }
      }
    }else ;//wrong command
  }
  dynamic_cast<Grid*>(root_grid)->UpdateLayout();
  //for debugging
/*  cout<<"*"<<root_grid->Name<<"*\n"<<root_grid->Width<<" "
    <<root_grid->Height<<"\t"<<root_grid->OffsetLeft<<" "
    <<root_grid->OffsetTop<<"\t"<<root_grid->GridCol<<" "
    <<root_grid->GridRow<<endl;
  printing(root_grid);
*/
  //print outputs
//cout<<"[Result]"<<endl;
cout.precision(2);
  for(auto itr=rectangle_order.begin();itr!=rectangle_order.end();++itr){
    FrameworkElement* result=dynamic_cast<Grid*>(root_grid)->Find(*itr);
    cout<<result->Name<<" "<<dynamic_cast<Rectangle*>(result)->Fill<<" ";
    cout<<fixed<<result->OffsetLeft<<" "<<result->OffsetTop<<" "
      <<result->Width<<" "<<result->Height<<endl;
  }

  return 0;
}
void printing(FrameworkElement* root_grid){
  if(dynamic_cast<Grid*>(root_grid)!=nullptr){
//  cout<<"+"<<dynamic_cast<Grid*>(root_grid)->Children.size()<<endl;
  Grid* tmp=dynamic_cast<Grid*>(root_grid);
  if(tmp!=nullptr){
    for(auto wow=(tmp->Children).begin();wow!=(tmp->Children).end();++wow){
      FrameworkElement* child=(*wow);
      cout<<"*"<<child->Name
        <<"*\n"<<child->Width<<" "<<child->Height
        <<"\t"<<child->OffsetLeft<<" "<<child->OffsetTop
        <<"\t"<<child->GridCol<<" "<<child->GridRow<<endl;
      printing(child);
    }
  }
  }
}
void Grid::UpdateLayout(){
  if(dynamic_cast<Grid*>(this)==nullptr) ;
  else{
    for(auto itr=Children.begin();itr!=Children.end();++itr){
      FrameworkElement* child_grid=(*itr);
      int cnt=1;
      int col_sum = 0;
      int col_subsum=0;
      for(auto it_c=Cols.begin();it_c!=Cols.end();++it_c){
        col_sum+=*it_c;
        if(cnt<(child_grid->GridCol)) col_subsum+=*it_c;
        cnt++;
      }
      cnt=1;
      int row_sum=0;
      int row_subsum=0;
      for(auto it_r=Rows.begin();it_r!=Rows.end();++it_r){
        row_sum+=*it_r;
        if(cnt<(child_grid->GridRow)) row_subsum+=*it_r;
        cnt++;
      }
      child_grid->Width=Width*(Cols.at((child_grid->GridCol)-1)/(double)col_sum);
      child_grid->Height=Height*(Rows.at((child_grid->GridRow)-1)/(double)row_sum);
      child_grid->OffsetLeft=OffsetLeft+Width*((double)col_subsum/col_sum);
      child_grid->OffsetTop=OffsetTop+Height*((double)row_subsum/row_sum);
//      cout<<"Width= "<<Width<<"*("<<Cols.at(GridCol-1)<<"/"<<col_sum<<")="<<child_grid->Width<<endl;
//      cout<<"OffsetLeft= "<<OffsetLeft<<"+"<<Width<<"*("<<col_subsum<<"/"<<col_sum<<")="<<child_grid->OffsetLeft<<endl;
      if(dynamic_cast<Grid*>(child_grid)!=nullptr)
        if(dynamic_cast<Grid*>(child_grid)->Children.size()>0)
          child_grid->UpdateLayout();

    }//end of for loop
  }//end of else
}
void Panel::Add(FrameworkElement* child){
  Children.push_back(child);
}
FrameworkElement* Panel::Find(string name){
//  cout<<"[Find]"<<endl;
//  cout<<"Parent: "<<this->Name<<endl;
  if(dynamic_cast<Grid*>(this)==nullptr){
//    cout<<"parent doesn't have any child"<<endl;
    if(!(Name.compare(name))) return this;
    else return nullptr;
  }else{
//    cout<<"parent have children"<<endl;
    for(auto itr=(Children).begin();itr!=(Children).end();++itr){
//      cout<<"Child: "<<(*itr)->Name<<endl;
      if(dynamic_cast<Grid*>(*itr)==nullptr){
//        cout<<"This is REC CHILD"<<endl;
        if(!(*itr)->Name.compare(name)){
//          cout<<"HIT!!"<<endl;
          return *itr;
        }
        else{
//          cout<<"MISS!!"<<endl;
          continue;
        }
      }

      else{
//        cout<<"This is GRID CHILD"<<endl;
        if(!(*itr)->Name.compare(name)){
//          cout<<"HIT!!"<<endl;
          return *itr;
        }
        else{
          FrameworkElement* result=dynamic_cast<Grid*>(*itr)->Find(name);
          if(result!=nullptr) return result;
          continue;
        }
      }
    }
  }
  return nullptr;
}
