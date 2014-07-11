#include <iostream>
#include "game.h"
#include "screen.h"

using namespace std;

int main(int argc, char **argv)
{
Game *a = new Screen();
a->firstscreen();

cout << a->team[0].innings[1].player[4].getname();

cout << "\nhello\n";

}
