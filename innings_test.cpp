#include <iostream>
#include "innings.h"

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
				test18
                            };



bool test1()
{
return true;
}

bool test2()
{
return true;
}


bool test3()
{
return true;
}

bool test4()
{
return true;
}

bool test5()
{
return true;
}

bool test6()
{
return true;
}

bool test7()
{
return true;
}

bool test8()
{
return true;
}

bool test9()
{
return true;
}

bool test10()
{
return true;
}

bool test11()
{
return true;
}

bool test12()
{
return true;
}

bool test13()
{
return true;
}

bool test14()
{
return true;
}

bool test15()
{
return true;
}

bool test16()
{
return true;
}

bool test17()
{
return true;
}

bool test18()
{
return true;
}



int innings_test()
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

ret = innings_test();

   if(ret == 0)
   {   
      cout << "\nPASS\n";
   }
   else
   {
      cout << "\nFAIL\n";
   }
}
