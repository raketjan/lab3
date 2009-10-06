#include <cxxtest/TestSuite.h>

#include "julian.h"
#include "gregorian.h"
using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void test_year( void )
  {
    Gregorian g;
    TS_ASSERT_EQUALS(g.mod_julian_day(), 55110);
    TS_ASSERT_EQUALS(g.year(), 2009);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 6);
    TS_ASSERT_EQUALS(g.mod_julian_day(), 55110);
    // lägg till eller skapa ny med offset 10000
    // ska bli 23e march 1886
    Gregorian p(10000);
    TS_ASSERT_EQUALS(p.year(), 1886);
    TS_ASSERT_EQUALS(p.month(), 4);
    TS_ASSERT_EQUALS(p.day(), 4);
    TS_ASSERT_EQUALS(p.mod_julian_day(), 10000);
    // 100000 = 31a augusti 2132

Gregorian l(100000);
    TS_ASSERT_EQUALS(l.year(), 2132);
    TS_ASSERT_EQUALS(l.month(), 9);
    TS_ASSERT_EQUALS(l.day(), 1);
    TS_ASSERT_EQUALS(l.mod_julian_day(), 100000);
 
Gregorian q(0);
    TS_ASSERT_EQUALS(q.year(), 1858);
    TS_ASSERT_EQUALS(q.month(), 11);
    TS_ASSERT_EQUALS(q.day(), 17);
    TS_ASSERT_EQUALS(q.mod_julian_day(), 0);
  }

  void test_constructors( void ) {
    Gregorian j(1858, 11, 17);
    TS_ASSERT_EQUALS(j.year(), 1858);
    TS_ASSERT_EQUALS(j.month(), 11);
    TS_ASSERT_EQUALS(j.day(), 17);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 0);
  }
  void test_constructors2( void ) {
    Gregorian j(2009, 10, 5);
    TS_ASSERT_EQUALS(j.year(), 2009);
    TS_ASSERT_EQUALS(j.month(), 10);
    TS_ASSERT_EQUALS(j.day(), 5);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 55109);
  }
  void test_constructors3( void ) {
    Gregorian j(1890, 2, 13);
    TS_ASSERT_EQUALS(j.year(), 1890);
    TS_ASSERT_EQUALS(j.month(), 2);
    TS_ASSERT_EQUALS(j.day(), 13);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 11411);
  }



  void test_mod_julian_day( void ) {
    Gregorian g;
    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(1858,11,17), 0);
    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(1900, 1, 1), 15020);


    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(2009, 10, 5), 55109);
    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(1973, 3, 11), 41752);
}

  void test_day( void ) {
    Gregorian g;
    g.offset = 0;
    TS_ASSERT_EQUALS(g.day(), 17);
    TS_ASSERT_EQUALS(g.month(), 11);
    g.offset = 20;
    TS_ASSERT_EQUALS(g.day(), 7);
    TS_ASSERT_EQUALS(g.month(), 12);
    g.offset = 10;
    TS_ASSERT_EQUALS(g.day(), 27);
    TS_ASSERT_EQUALS(g.month(), 11);
    g.offset = 55109;
    TS_ASSERT_EQUALS(g.day(), 5);
}

  void test_inc(){
    Gregorian g;
    ++g;
    TS_ASSERT_EQUALS(g.day(), 7);
  }
};
