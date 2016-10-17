//Class scope
int height;
class Screen{
    public:
        typedef std::string::size_type pos;
        void dummy_function(pos height){
            cursor = width * height;//parameter height
        }
    private:
        pos cursor = 0, height = 0, width = 0;
        void Screen::dummy_function(pos height){
        };
        void Screen::dummy_function(pos height){
            cursor = width * this ->hieght;// member height
            cursor = width * Screen::height;//member height
        }
};
