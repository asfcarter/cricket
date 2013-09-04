#include <iostream>
#include "team.h"

using namespace std;

int main(int argc, char **argv)
{
team a;
a.setteamcomputer1();
a.setteamcomputer2();

cout << "hello\n"; 
cout << a.innings[0].player[3].getname();
}
