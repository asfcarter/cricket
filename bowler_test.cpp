#include <iostream>
#include "bowler.h"

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




bool test1()
{
Bowler a;

return (!(a.get_overs() || a.get_overs_ball() || a.get_maidens() || a.get_runs_conceeded() || a.get_wickets() || a.get_bowler_number()));
}

bool test2()
{
Bowler a;
	a.change_overs_ball(11);
	if(a.get_wickets() != 1)
	{
		return false;
	}
	
	a.change_overs_ball(11);
	if(a.get_wickets() != 2)
	{
		return false;
	}
	
return true;
}

bool test3()
{
Bowler a;
	a.set_bowler_number(4);
        if(a.get_bowler_number() != 4)
	{
		return false;
	}

return true;
}

bool test4()
{
Bowler a;
int i;

	for(i=0;i<22;i++)
	{
		a.change_overs_ball(0);
	}
	
return ((a.get_overs()==3)&&(a.get_overs_ball()==4)&&(a.get_maidens()==3)&&(a.get_runs_conceeded()==0));
}

bool test5()
{
Bowler a;
int i;

	for(i=0;i<12;i++)
	{
		a.change_overs_ball(2);
	}
	
return ((a.get_overs()==2)&&(a.get_overs_ball()==0)&&(a.get_maidens()==0)&&(a.get_runs_conceeded()==24));
}



int bowler_test()
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

ret = bowler_test();

   if(ret == 0)
   {   
      cout << "\nPASS\n";
   }
   else
   {
      cout << "\nFAIL\n";
   }
}
