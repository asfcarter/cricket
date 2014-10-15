#include <cstring>

class Fielder
{
protected:
   int x,y;
public:
    Fielder(){
                set_position(0,0);
             }
    void set_position(int x1,int y1);
    void set_x(int);
    void set_y(int);
    int get_x() const;
    int get_y() const;
};
