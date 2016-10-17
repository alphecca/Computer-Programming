//Forward Declaration
class Screen;
class Link_Screen{
    Screen window;// ok
    Link_Screen *next;//ok
    Link_Screen *prev;//ok
};

class Screen{
    public:
        typedef std::string::size_type pos;
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};//ok
class Screen{
   private:
       pos cursor = 0;//error : type should be declared before use.
       pos height = 0, width = 0;
       std::string contents;
   public:
       typedef std::string::size_type pos;

};
