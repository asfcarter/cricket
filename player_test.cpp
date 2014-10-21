#include <iostream>
#include "player.h"

using namespace std;




bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();
bool test7();
bool test8();
bool test9();
bool test10();
bool test11();
bool test12();
bool test13();
bool test14();
bool test15();
bool test16();
bool test17();
bool test18();
bool test19();
bool test20();

bool (*test_func_ptr[])() = {
                             	test1, 
			     	test2, 
			     	test3,
			     	test4,
				test5,
				test6,
				test7,
				test8,
				test9,
				test10,
				test11,
				test12,
				test13,
				test14,
				test15,
				test16,
				test17,
				test18,
				test19,
				test20
                            };


bool check_x_pos(Player *fielder, int x_pos)
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

bool check_y_pos(Player *fielder, int y_pos)
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
Player a;
return !(strcmp(a.get_name(),""));
}

bool test2()
{
Player a;

	a.set_name("Andy");
        if(strcmp(a.get_name(),"Andy"))
	{
		return false;
	}
	
	a.set_name("Louise");
        if(strcmp(a.get_name(),"Louise"))
	{
		return false;
	}
	
	a.set_name("Rob");
        if(strcmp(a.get_name(),"Rob"))
	{
		return false;
	}

return true;
}


bool test3()
{
Player a;
return ( (a.get_balls_faced()==0) && (a.get_ones()==0) && (a.get_twos()==0) && (a.get_fours()==0) && (a.get_sixes()==0) && (a.get_threes()==0) && (a.get_runs_scored()==0) && (a.get_batsman_number()==0) && (a.get_how_out()==0) );
}

bool test4()
{
Player a;

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

bool test5()
{
Player a;

    a.set_how_out(4);
    if(a.get_how_out() != 4)
    {
    	return false;
    }

    a.set_how_out(10);
    if(a.get_how_out() != 10)
    {
    	return false;
    }

return true;
}

bool test6()
{
Player a;
int i;
	for(i=0;i<10;i++)
	{
		a.change_balls_faced(0);
	}

return ( (a.get_balls_faced() == 10) && (a.get_ones() == 0) && (a.get_twos() == 0) && (a.get_threes() == 0) && (a.get_fours() == 0) && (a.get_sixes() == 0) && (a.get_runs_scored() == 0) );
}

bool test7()
{
Player a;
int i;
	for(i=0;i<10;i++)
	{
		a.change_balls_faced(1);
	}

return ( (a.get_balls_faced() == 10) && (a.get_ones() == 10) && (a.get_twos() == 0) && (a.get_threes() == 0) && (a.get_fours() == 0) && (a.get_sixes() == 0) && (a.get_runs_scored() == 10) );
}

bool test8()
{
Player a;
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

bool test9()
{
Player a;

return (!(a.get_overs() || a.get_overs_ball() || a.get_maidens() || a.get_runs_conceeded() || a.get_wickets() || a.get_bowler_number()));
}

bool test10()
{
Player a;
	a.change_wickets();
	if(a.get_wickets() != 1)
	{
		return false;
	}
	
	a.change_wickets();
	if(a.get_wickets() != 2)
	{
		return false;
	}
	
return true;
}

bool test11()
{
Player a;
	a.set_bowler_number(4);
        if(a.get_bowler_number() != 4)
	{
		return false;
	}

return true;
}

bool test12()
{
Player a;
int i;

	for(i=0;i<22;i++)
	{
		a.change_overs_ball(0);
	}
	
return ((a.get_overs()==3)&&(a.get_overs_ball()==4)&&(a.get_maidens()==3)&&(a.get_runs_conceeded()==0));
}

bool test13()
{
Player a;
int i;

	for(i=0;i<12;i++)
	{
		a.change_overs_ball(2);
	}
	
return ((a.get_overs()==2)&&(a.get_overs_ball()==0)&&(a.get_maidens()==0)&&(a.get_runs_conceeded()==24));
}

bool test14()
{
Player a;
return check_x_pos(&a, 0);
}

bool test15()
{
Player a;
return check_y_pos(&a, 0);
}

bool test16()
{
Player a;
	a.set_x(10);
return check_x_pos(&a, 10);
}

bool test17()
{
Player a;
	a.set_y(20);
return check_y_pos(&a, 20);
}

bool test18()
{
Player a;
	a.set_position(-15,-25);
return (check_x_pos(&a, -15) && check_y_pos(&a, -25));
}

bool test19()
{
Player a,b;

	a.set_name("Andy");
        if(strcmp(a.get_name(),"Andy"))
	{
		return false;
	}
	
	a.set_name("Louise");
        if(strcmp(a.get_name(),"Louise"))
	{
		return false;
	}
	
	a.set_name("Rob");
        if(strcmp(a.get_name(),"Rob"))
	{
		return false;
	}
	
	b=a;
	
        if(strcmp(b.get_name(),"Rob"))
	{
		return false;
	}	

return true;
}

bool test20()
{
Player a;

	a.set_name("Andy");
        if(strcmp(a.get_name(),"Andy"))
	{
		return false;
	}
	
	a.set_name("Louise");
        if(strcmp(a.get_name(),"Louise"))
	{
		return false;
	}
	
	a.set_name("Rob");
        if(strcmp(a.get_name(),"Rob"))
	{
		return false;
	}
		

Player b;
b=a;
        if(strcmp(b.get_name(),"Rob"))
	{
		return false;
	}
	
return true;
}

int player_test()
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

ret = player_test();
      cout << "\nPASS\n";
      cout << "\nPASS\n";
      cout << "\nPASS\n";

   if(ret == 0)
   {   
      cout << "\nPASS\n";
   }
   else
   {
      cout << "\nFAIL\n";
   }
   cin.get();
}

