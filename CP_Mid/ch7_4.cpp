//Friend
class Screen{
    friend bool Equal(Screen, Screen);
    friend void Window::setSize(double);
    public:
    Screen() = default;
    Screen(double ht, double wd): height(ht), width(wd) {}
    //ok. it's okay to use variables before declaration
    private:
    double height = 980.0, width = 100.0;
};
bool Equal(Screen a, Screen b){
    if(a.height == b.height && a.width == b.width) { return true;}
    else return false;
}
class Window{
    //do something
};
void Window::setSize(double scale){
    Screen s;
    hieght = s.height;//ok
    width = s.width;//ok
}
