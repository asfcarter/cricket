#include <iostream>
#include "game.h"
#include "screen.h"

using namespace std;

int main(int argc, char **argv)
{
Screen *a = new Screen();
SDL_Keycode ret_val;
a->init_screen();
a->firstscreen();
ret_val=a->secondscreen();

if(ret_val == SDLK_y)
cout << "yyyy";
else if(ret_val == SDLK_n)
cout << "nnnnnn";
else
cout << ret_val << "what\n";

a->destroy_screen();

//cout << a->team[0].innings[1].player[4].getname();

cout << "\nhello\n";

}
