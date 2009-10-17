#include "calendar.h"
#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
#include <cxxtest/TestSuite.h>
using namespace lab2;

class date_test : public CxxTest::TestSuite
{
public:
    
    void setUp()
    { 
      //time_t ut = time(0);
      //set_k_time(1600442475);
      //set_k_time(4126094164);
      set_k_time(1255796638);
	//set_k_time(0);
    }
    void test_basic()
    {
      std::cout << " starting test " << std::endl;
      Calendar<Gregorian> cal;
      TS_ASSERT(cal.set_date(2009,10,2));
      TS_ASSERT(cal.add_event("2009,10,2"));
      TS_ASSERT(cal.add_event("2009,10,2 second"));
      TS_ASSERT(cal.add_event("2009,10,3", 3));
      TS_ASSERT(cal.add_event("2009,11,2", 2, 11));
      TS_ASSERT(cal.add_event("2012,10,2", 2, 10, 2012));
      TS_ASSERT_EQUALS(cal.add_event("ugly date", -1), false);
      std::cout << "test_basic" << std::endl;
      std::cout << cal;
	
    }

    void test_switch_date()
    {
      
        Calendar<Gregorian> cal;
        TS_ASSERT(cal.set_date(2009,2,3));
        TS_ASSERT(cal.add_event("2009,2,3"));
        TS_ASSERT(cal.set_date(2010,3,4));
        TS_ASSERT(cal.add_event("2010,3,4"));
        TS_ASSERT(cal.set_date(2008,1,1));
        TS_ASSERT(cal.add_event("2008,1,1"));
        TS_ASSERT_EQUALS(cal.set_date(2008,0,-1), false);
        TS_ASSERT_EQUALS(cal.set_date(2008,1,0), false);
        TS_ASSERT_EQUALS(cal.set_date(2008,0,3), false);
        std::cout << "test_switch_date" << std::endl;
        std::cout << cal;
    }

    void test_add_event()
    {
        Calendar<Gregorian> cal;
        TS_ASSERT(cal.set_date(2035,8,18));
        TS_ASSERT(cal.add_event("2100-09-14",14,9,2100));
    }


    void test_remove_event()
    {
        Calendar<Gregorian> cal;
        TS_ASSERT(cal.set_date(2035,8,18));
        TS_ASSERT(cal.add_event("2100-09-14",14,9,2100));
        TS_ASSERT_EQUALS(cal.remove_event("2100-09-14"), false);
        TS_ASSERT(cal.add_event("2100-10-2",3));
        TS_ASSERT(cal.remove_event("2100-10-2",3));
        TS_ASSERT(cal.add_event("gello",4,4));
        TS_ASSERT(cal.remove_event("gello",4,4));
        TS_ASSERT(cal.add_event("alo",4,3,2009));
        TS_ASSERT(cal.remove_event("alo",4,3,2009));
        TS_ASSERT(cal.remove_event("2100-09-14",14,9,2100));
        std::cout << "test_remove_event" << std::endl;
        std::cout << cal;
        Calendar<Gregorian> cal2;
        TS_ASSERT(cal2.set_date(2035,8,18));
        TS_ASSERT(cal2.add_event("2100-09-14",14,9,2100));
        TS_ASSERT_EQUALS(cal2.remove_event("2100-09-14"), false);
        TS_ASSERT(cal2.add_event("2100-10-2",3));
        TS_ASSERT(cal2.add_event("gello",4,4));
        TS_ASSERT(cal2.add_event("alo",4,3,2009));
        TS_ASSERT(cal2.remove_event("2100-10-2",3));
        std::cout << "cal 2: " << std::endl;
        std::cout << cal2;

    }

    void test_operator_assign()
    {
        Calendar<Gregorian> cal;
        cal.add_event("hello1");
        cal.add_event("hello2",10,10,2010);
        cal.add_event("hello3");
        Calendar<Gregorian> cal2;
        cal2 = cal;
        std::cout << "test_operator_assign" << std::endl;
        std::cout << "cal1: " << std::endl;
        std::cout << cal;
        std::cout << "cal2: " << std::endl;
        std::cout << cal2;
        cal2.set_date(2009,9,9);
        cal2 = cal2;
        cal2.add_event("hello1");
        cal2.remove_event("hello2",10,10,2010);
        std::cout << "cal2 again" << std::endl;
        std::cout << cal2;
    }

    void test_eat_this_mothafucka()
    {
        Calendar<Gregorian> gcal;
        Calendar<Julian> jcal;
        gcal.set_date(2010,12,12);
        jcal.set_date(2009,4,4);
        gcal.add_event("hello1");
        gcal.add_event("hello1");
        gcal.add_event("hello1",10);
        gcal.add_event("hello2");
        gcal.add_event("hello2",10,10);
        jcal.add_event("hello_j",5);
        jcal.add_event("hello_j");
	jcal.add_event("hello_j");
	jcal.add_event("hello_j");
        jcal.add_event("disco",5,5,2109);
        std::cout << "eat this" << std::endl;
        std::cout << "gcal" << std::endl;
        std::cout << gcal;
        std::cout << "jcal" << std::endl;
        std::cout << jcal;
        jcal.remove_event("disco",5,5,2109);
        jcal.remove_event("hello_j");
        gcal = jcal;
        std::cout << "gcal = jcal" << std::endl;
        std::cout << gcal;
        std::cout << "gjcal" << std::endl;
	Calendar<Gregorian> gjcal(jcal);
	gjcal = gcal;
	std::cout << gjcal;

	Calendar<Gregorian> x;
	x.set_date(2009,10,17);
	TS_ASSERT_EQUALS(x.add_event("XXXXX"),true);
	TS_ASSERT_EQUALS(x.add_event("XXXXX",25),true);
	TS_ASSERT_EQUALS(x.add_event("XXXXX",25,11),true);
	TS_ASSERT_EQUALS(x.add_event("XXXXX",25,11),false);
	std::cout << x;
	

	Calendar<Gregorian> ny;

	ny.set_date(2100, 5, 15);

	TS_ASSERT_EQUALS(ny.add_event("HOHOHOH",6,10,2100),true);
	TS_ASSERT_EQUALS(ny.add_event("HOHOHOH",20,10,2100),true);
	TS_ASSERT_EQUALS(ny.add_event("HOHOHOH",20,10,2100),false);
	TS_ASSERT_EQUALS(ny.remove_event("HOHOHOH",20,10,2100),true);
	TS_ASSERT_EQUALS(ny.remove_event("HOHOHOH",20,10,2100),false);
	TS_ASSERT_EQUALS(ny.add_event("HOHOHOH",20,10,2100),true);
	TS_ASSERT_EQUALS(ny.add_event("HOHOH",20,10,2110),true);
	TS_ASSERT_EQUALS(ny.get_events().size(),2);
	Gregorian * g = new Gregorian(2100,10,6);
	std::cout << "DAGENS " << *(ny.get_today()) << std::endl;	
	std::cout << ny;
	
	Calendar<Julian> nyj;
	nyj.set_date(2000, 5, 15);
	TS_ASSERT_EQUALS(nyj.add_event("nyj: HOHOHOH",6,10,2000),true);
	std::cout << nyj;

	
    }

    void x_test_copy_constructor()
    {
     
        // TODO
        // Test with both gregorian to gregorian,
        // julian to julian and gregorian to julian
    }

    void x_test_destructor()
    {
        // TODO
        // Test this by using anonymous scopes and try to trigger segfault
    }

};

