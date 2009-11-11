#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
#include <ctime>
#include <cxxtest/TestSuite.h>
#include <iostream>
#include <string>


using namespace lab2;

class date_test : public CxxTest::TestSuite
{
public:

    void assert_date( Date& d, 
                      int year, 
                      int month, 
                      int day,
                      int week_day,
                      int days_this_month,
                      std::string week_day_name,
                      std::string month_name,
                      int id)
    {
        TSM_ASSERT_EQUALS(id, d.day(), day);
        TSM_ASSERT_EQUALS(id, d.month(), month);
        TSM_ASSERT_EQUALS(id, d.year(), year);
        TSM_ASSERT_EQUALS(id, d.week_day(), week_day);
        TSM_ASSERT_EQUALS(id, d.days_this_month(), days_this_month);
        TSM_ASSERT_EQUALS(id, d.week_day_name(), week_day_name);
        TSM_ASSERT_EQUALS(id, d.month_name(), month_name);
    }

    void test_gregorian_basic()
    {
	std::cout << "TEST 1" << std::endl;

      Gregorian g(2008, 9, 12);
        assert_date(g, 2008, 9, 12, 5, 30, "friday", "september",0);
    }
    
    void test_gregorian_old()
    {
    }
    
    void test_gregorian_remote_future()
    {
    }

    void test_gregorian_leap_years()
    {
        
	std::cout << "TEST 2" << std::endl;
        Gregorian g2(1944, 2, 29);
        assert_date(g2, 1944, 2, 29, 2, 29, "tuesday", "february",1);
        
        
    }

    void test_gregorian_invalid_dates()
    {

	std::cout << "TEST 3" << std::endl;
        TS_ASSERT_THROWS(Gregorian(2004, 4, 31), std::out_of_range);
        TS_ASSERT_THROWS(Gregorian(2004, -1, 23), std::out_of_range);
        TS_ASSERT_THROWS(Gregorian(2004, 7, 32), std::out_of_range);
        TS_ASSERT_THROWS(Gregorian(2004, 7, -1), std::out_of_range);
        TS_ASSERT_THROWS(Gregorian(-4713, 4, 31), std::out_of_range);
        TS_ASSERT_THROWS(Gregorian(2004, 13, 14), std::out_of_range);
        TS_ASSERT_THROWS(Gregorian(2007, 2, 29), std::out_of_range);
    }

    void test_gregorian_copy_and_assign()
    {
	std::cout << "TEST 4" << std::endl;
        Gregorian genesis(1984, 6, 20);
        Gregorian g2(2004, 6, 20);

        assert_date(genesis, 1984, 6, 20, 3, 30, "wednesday", "june",0);
        assert_date(g2, 2004, 6, 20, 7, 30, "sunday", "june",1);

        g2 = genesis;

        assert_date(g2, 1984, 6, 20, 3, 30, "wednesday", "june",2);

        Gregorian g3 = g2;

        assert_date(g3, 1984, 6, 20, 3, 30, "wednesday", "june",3);
    }

    void test_gregorian_compare() 
    {
	std::cout << "TEST 5" << std::endl;
        Gregorian g1(1984, 6, 20);
        Gregorian g2(1984, 6, 20);
        TS_ASSERT(g1 == g2);
        TS_ASSERT(g1 <= g2);
        TS_ASSERT(g1 >= g2);

        Gregorian g3(1984, 6, 20);
        Gregorian g4(1984, 8, 20);
       
        TS_ASSERT(g3 != g4);
        TS_ASSERT(g3 < g4);
        TS_ASSERT(g3 <= g4);
        TS_ASSERT(g4 > g3);
        TS_ASSERT(g4 >= g3);
    }

    void test_compare_gregorian_julian()
    {
	std::cout << "TEST 6" << std::endl;
        Gregorian g(1984, 6, 20);
        Julian j(1984, 6, 7);
        TS_ASSERT(g == j);
        TS_ASSERT(g <= j);
        TS_ASSERT(j >= g);
        Julian j2(1984, 6, 2);
        TS_ASSERT(j2 < g);
        Gregorian g2(1984,6, 10);
        TS_ASSERT(g2 < j2);
        TS_ASSERT(g2 != j);
        TS_ASSERT(j2 != g);
    }


    void test_gregorian_operator_plus_plus()
    {
	std::cout << "TEST 7" << std::endl;
        Gregorian g1(1993, 4, 15);
        ++g1;
        assert_date(g1, 1993, 4, 16, 5, 30, "friday", "april",0);
        ++(++g1);
        assert_date(g1, 1993, 4, 18, 7, 30,"sunday", "april",1);
        Gregorian g2(1996, 2, 28);
        ++(++g2);
        assert_date(g2, 1996, 3, 1, 5, 31, "friday", "march",2);
        Gregorian g3(1995, 12, 31);
        ++g3;
        assert_date(g3, 1996,1,1,1,31,"monday","january",3);
    }
    void test_gregorian_operator_minus_minus()
    {
	std::cout << "TEST 8" << std::endl;
        Gregorian g1(1993, 4, 1);
        --g1;
        assert_date(g1, 1993, 3, 31, 3, 31, "wednesday", "march",0);
        --(--g1);
        assert_date(g1, 1993, 3, 29, 1, 31,"monday", "march",1);
        Gregorian g2(1996,3,1);
        --g2;
        assert_date(g2, 1996, 2, 29, 4, 29, "thursday", "february",2);
        Gregorian g3(1996,1,1);
        --g3;
        assert_date(g3, 1995, 12, 31, 7, 31, "sunday", "december",3);
    }
    void test_gregorian_operator_add_assign()
    {
	std::cout << "TEST 9" << std::endl;
        Gregorian g1(1996, 1, 17);
        g1 += 21;
        assert_date(g1, 1996, 2, 7, 3, 29, "wednesday", "february",0);
        g1 += 30;
        assert_date(g1, 1996, 3, 8, 5, 31, "friday", "march",1);

        Gregorian g2(1995, 12, 29);
        g2 += 4;
        assert_date(g2, 1996, 1, 2, 2, 31, "tuesday", "january",2);
    }
    void test_gregorian_operator_sub_assign()
    {
	std::cout << "TEST 10" << std::endl;
        Gregorian g1(1996, 3, 8);
        g1 -= 30;
        assert_date(g1, 1996, 2, 7, 3, 29, "wednesday", "february",0);
        g1 -= 21;
        assert_date(g1, 1996, 1, 17, 3, 31, "wednesday", "january",1);
        
        Gregorian g2(1996, 1, 2);
        g2 -= 4;
        assert_date(g2, 1995, 12, 29, 5, 31, "friday", "december",2);
    }

    void test_gregorian_add_month()
    {
	std::cout << "TEST 11" << std::endl;
        Gregorian g1(1996, 1, 31);
        g1.add_month();
        assert_date(g1, 1996, 3, 1, 5,  31, "friday", "march",0);
    
        Gregorian g3(1995, 12, 1);
        g3.add_month();
        assert_date(g3, 1996, 1, 1, 1, 31, "monday", "january",1);

        Gregorian g2(1995, 12, 1);
        g2.add_month(2);
        assert_date(g2, 1996, 2, 1, 4, 29, "thursday", "february",2);
        
        Gregorian g4(1995, 12, 1);
        g4.add_month(3);
        assert_date(g4, 1996, 3, 1, 5, 31, "friday", "march",3);

        Gregorian g5(1995, 12, 1);
        g5.add_month();
        g5.add_month();
        g5.add_month();
        assert_date(g5, 1996, 3, 1, 5, 31, "friday", "march",4);
	
	Gregorian g6(1992, 2, 29);
        g6.add_month(29);
        assert_date(g6, 1994, 7, 28, 4, 31, "thursday", "july",3);

	Gregorian g7(1993, 1, 29);
        g7.add_month(1);
        assert_date(g7, 1993, 2, 28, 7, 28, "sunday", "february",3);

    }

    void test_gregorian_add_year()
    {
      std::cout << "TEST 12" << std::endl;
        Gregorian g1(1995, 1, 5);
        g1.add_year();
        assert_date(g1, 1996, 1, 5, 5,  31, "friday", "january",0);
        
        Gregorian g2(1996, 1, 31);
        g2.add_year();
        assert_date(g2, 1997, 1, 31, 5,  31, "friday", "january",1);
        
        Gregorian g3(1996, 2, 29);
        g3.add_year(4);
        assert_date(g3, 2000, 2, 29, 2,  29, "tuesday", "february",2);

        Gregorian g4(1988, 2, 29);
        g4.add_year(3);
        assert_date(g4, 1991, 2, 28, 4,  28, "thursday", "february",3);
        
    }

    void test_julian_basic()
    {
      std::cout << "TEST 13" << std::endl;
      Julian j(2008, 9, 12);
      assert_date(j, 2008, 9, 12, 4, 30, "thursday", "september",0);
    }
    
    void test_julian_old()
    {
      std::cout << "TEST 14" << std::endl;
      Julian j(1900, 2, 28);
      assert_date(j, 1900, 2, 28, 1, 29, "monday", "february",0);
    }
    
    void test_julian_leap_years()
    {
      std::cout << "TEST 15" << std::endl;
           
      Julian j2(1944, 2, 29);
      assert_date(j2, 1944, 2, 29, 1, 29, "monday", "february",1);
      
     
    }
    
    void test_julian_invalid_dates()
    {
        TS_ASSERT_THROWS(Julian(2004, 4, 31), std::out_of_range);
        TS_ASSERT_THROWS(Julian(2004, -1, 23), std::out_of_range);
        TS_ASSERT_THROWS(Julian(2004, 7, 32), std::out_of_range);
        TS_ASSERT_THROWS(Julian(2004, 7, -1), std::out_of_range);
        TS_ASSERT_THROWS(Julian(-4713, 4, 31), std::out_of_range);
        TS_ASSERT_THROWS(Julian(2004, 13, 14), std::out_of_range);
        TS_ASSERT_THROWS(Julian(2007, 2, 29), std::out_of_range);
    }

    void test_julian_copy_and_assign()
    {
        Julian genesis(1984, 6, 20);
        Julian g2(2004, 6, 20);

        assert_date(genesis, 1984, 6, 20, 2, 30, "tuesday", "june",0);
        assert_date(g2, 2004, 6, 20, 6, 30, "saturday", "june",1);

        g2 = genesis;

        assert_date(g2, 1984, 6, 20, 2, 30, "tuesday", "june",2);

        Julian g3 = g2;

        assert_date(g3, 1984, 6, 20, 2, 30, "tuesday", "june",3);
    }

    void test_julian_compare() 
    {
        Julian g1(1984, 6, 20);
        Julian g2(1984, 6, 20);
        TS_ASSERT(g1 == g2);
        TS_ASSERT(g1 <= g2);
        TS_ASSERT(g1 >= g2);

        Julian g3(1984, 6, 20);
        Julian g4(1984, 8, 20);
       
        TS_ASSERT(g3 != g4);
        TS_ASSERT(g3 < g4);
        TS_ASSERT(g3 <= g4);
        TS_ASSERT(g4 > g3);
        TS_ASSERT(g4 >= g3);
    }
    
    void test_julian_operator_plus_plus()
    {
        Julian g1(1993, 4, 15);
        ++g1;
        assert_date(g1, 1993, 4, 16, 4, 30, "thursday", "april",0);
        ++(++g1);
        assert_date(g1, 1993, 4, 18, 6, 30,"saturday", "april",1);
        Julian g2(1996, 2, 28);
        ++(++g2);
        assert_date(g2, 1996, 3, 1, 4, 31, "thursday", "march",2);
        Julian g3(1995, 12, 31);
        ++g3;
        assert_date(g3, 1996,1,1,7,31,"sunday","january",3);
    }
    void test_julian_operator_minus_minus()
    {
        Julian g1(1993, 4, 1);
        --g1;
        assert_date(g1, 1993, 3, 31, 2, 31, "tuesday", "march",0);
        --(--g1);
        assert_date(g1, 1993, 3, 29, 7, 31,"sunday", "march",1);
        Julian g2(1996,3,1);
        --g2;
        assert_date(g2, 1996, 2, 29, 3, 29, "wednesday", "february",2);
        Julian g3(1996,1,1);
        --g3;
        assert_date(g3, 1995, 12, 31, 6, 31, "saturday", "december",3);
        Julian g4(2137,5,1);
        --g4;
        assert_date(g4,2137,4,30, 2, 30, "tuesday", "april", 4); 
    }
    void test_julian_operator_plus_plus_postfix()
    {
        Julian g1(1993, 4, 15);
        g1++;
        assert_date(g1, 1993, 4, 16, 4, 30, "thursday", "april",0);
        Julian g1old = g1++;
        assert_date(g1old, 1993, 4, 16, 4, 30, "thursday", "april",1);
        assert_date(g1, 1993, 4, 17, 5, 30,"friday", "april",2);
    }
    void test_julian_operator_minus_minus_postfix()
    {
        Julian g1(1993, 4, 1);
        g1--;
        assert_date(g1, 1993, 3, 31, 2, 31, "tuesday", "march",0);
        Julian g1old = g1--;
        assert_date(g1old, 1993, 3, 31, 2, 31, "tuesday", "march",1);
        assert_date(g1, 1993, 3, 30, 1, 31,"monday", "march",2);
        Julian g4(2137,5,1);
        g4--;
        assert_date(g4,2137,4,30, 2, 30, "tuesday", "april", 4); 
    }
    void test_to_be_sure()
    {
        Julian g4(2137,5,1);
        g4--;
        assert_date(g4,2137,4,30, 2, 30, "tuesday", "april", 4); 
    }
    void test_gregorian_operator_plus_plus_postfix()
    {
        Gregorian g1(1993, 4, 15);
        g1++;
        assert_date(g1, 1993, 4, 16, 5, 30, "friday", "april",0);
        Gregorian g1old = g1++;
        assert_date(g1old, 1993, 4, 16, 5, 30, "friday", "april",1);
        assert_date(g1, 1993, 4, 17, 6, 30,"saturday", "april",2);
    }
    void test_gregorian_operator_minus_minus_postfix()
    {
        Gregorian g1(1993, 4, 1);
        g1--;
        assert_date(g1, 1993, 3, 31, 3, 31, "wednesday", "march",0);
        Gregorian g1old = g1--;
        assert_date(g1old, 1993, 3, 31, 3, 31, "wednesday", "march",1);
        assert_date(g1, 1993, 3, 30, 2, 31,"tuesday", "march",2);
    }

    void test_minus()
    {
        time_t ut = time(0);
        set_k_time(ut);
        Gregorian g;
        Julian j;
        TS_ASSERT_EQUALS(g - j, 0);
        TS_ASSERT_EQUALS(j - g, 0);

        Gregorian g2(1984, 6, 21);
        Julian j2(1984, 6, 7);
        TS_ASSERT_EQUALS(g2 - j2, 1);
        TS_ASSERT_EQUALS(j2 - g2, -1);
    }

    void x_test_julian_add_month()
    {
	std::cout << "TEST last" << std::endl;
        Julian g1(2008, 3, 31);
        g1.add_month(-8);
        assert_date(g1, 2007, 8, 1, 3,  31, "wednesday", "august",0);
        Julian g2(2008, 3, 31);
        g2.add_month(-1);
        assert_date(g2, 2008, 3, 1, 1,  31, "wednesday", "march",0);

    }
private:
};
