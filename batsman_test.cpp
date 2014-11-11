#include <iostream>
#include "batsman.h"

using namespace std;

bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();

bool (*test_func_ptr[])() = {
                             	test1, 
			     	test2, 
			     	test3,
			     	test4,
				test5,
				test6
                            };




bool test1()
{
Batsman a;
return ( (a.get_balls_faced()==0) && (a.get_ones()==0) && (a.get_twos()==0) && (a.get_fours()==0) && (a.get_sixes()==0) && (a.get_threes()==0) && (a.get_runs_scored()==0) && (a.get_batsman_number()==0) && (a.get_how_out()==0) );
}

bool test2()
{
Batsman a;

    a.set_batsman_number(5);
    if(a.get_batsman_number() != 5)
    {
    	return false;
    }

    a.set_batsman_number(11);
    if(a.get_batsman_number() != 11)
    {
    	return false;
    }

return true;
}

bool test3()
{
Batsman a;

    a.change_balls_faced(11);
    if(a.get_how_out() != 11)
    {
    	return false;
    }

    a.change_balls_faced(15);
    if(a.get_how_out() != 15)
    {
    	return false;
    }

return true;
}

bool test4()
{
Batsman a;
int i;
	for(i=0;i<10;i++)
	{
		a.change_balls_faced(0);
	}

return ( (a.get_balls_faced() == 10) && (a.get_ones() == 0) && (a.get_twos() == 0) && (a.get_threes() == 0) && (a.get_fours() == 0) && (a.get_sixes() == 0) && (a.get_runs_scored() == 0) );
}

bool test5()
{
Batsman a;
int i;
	for(i=0;i<10;i++)
	{
		a.change_balls_faced(1);
	}

return ( (a.get_balls_faced() == 10) && (a.get_ones() == 10) && (a.get_twos() == 0) && (a.get_threes() == 0) && (a.get_fours() == 0) && (a.get_sixes() == 0) && (a.get_runs_scored() == 10) );
}

bool test6()
{
Batsman a;
int i;
	for(i=0;i<10;i++)
	{
		a.change_balls_faced(1);
	}

	for(i=0;i<9;i++)
	{
		a.change_balls_faced(2);
	}

	for(i=0;i<8;i++)
	{
		a.change_balls_faced(3);
	}
	
	for(i=0;i<7;i++)
	{
		a.change_balls_faced(4);
	}	

	for(i=0;i<6;i++)
	{
		a.change_balls_faced(6);
	}	
		
return ( (a.get_balls_faced() == 40) && (a.get_ones() == 10) && (a.get_twos() == 9) && (a.get_threes() == 8) && (a.get_fours() == 7) && (a.get_sixes() == 6) && (a.get_runs_scored() == 116) );
}



int batsman_test()
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

ret = batsman_test();

   if(ret == 0)
   {   
      cout << "\nPASS\n";
   }
   else
   {
      cout << "\nFAIL\n";
   }
}
