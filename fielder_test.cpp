#include <iostream>
#include "fielder.h"

using namespace std;

bool test1();
bool test2();
bool test3();
bool test4();
bool test5();

bool (*test_func_ptr[])() = {
                             	test1, 
			     				test2, 
			     				test3,
			     				test4,
								test5
                            };


bool check_x_pos(Fielder *fielder, int x_pos)
{
int x = 0;
bool ret = true;

    x = fielder->get_x();
    
    if(x != x_pos)
    {
       ret = false;
    }
    
return ret;
}

bool check_y_pos(Fielder *fielder, int y_pos)
{
int y = 0;
bool ret = true;

    y = fielder->get_y();
    
    if(y != y_pos)
    {
       ret = false;
    }
    
return ret;
}


bool test1()
{
Fielder a;

return check_x_pos(&a, 0);
}

bool test2()
{
Fielder a;

return check_y_pos(&a, 0);
}

bool test3()
{
Fielder a;
a.set_x(10);
return check_x_pos(&a, 10);
}

bool test4()
{
Fielder a;
a.set_y(20);
return check_y_pos(&a, 20);
}

bool test5()
{
Fielder a;
a.set_position(-15,-25);
return (check_x_pos(&a, -15) && check_y_pos(&a, -25));
}





int fielder_test()
{
int i;
int ret_num=0;
bool ret;
   
	for(i=0;i<(int)(sizeof(test_func_ptr)/sizeof(*(test_func_ptr)));i++)
	{
		ret = test_func_ptr[i]();
		
		if(ret == false)
		{
			ret_num++;
		}
	}

return ret_num;
}

int main(int argc, char **argv)
{
int ret=true;

ret = fielder_test();

   if(ret == 0)
   {   
      cout << "\nPASS\n";
   }
   else
   {
      cout << "\nFAIL\n";
   }
}
