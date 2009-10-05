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
    TS_ASSERT_EQUALS(g.year(), 2009);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 5);
    // lägg till eller skapa ny med offset 10000
    // ska bli 23e march 1886
    Gregorian p(10000);
    TS_ASSERT_EQUALS(p.year(), 1886);
    TS_ASSERT_EQUALS(p.month(), 3);
    TS_ASSERT_EQUALS(p.day(), 4);
    // 100000 = 31a augusti 2132

Gregorian l(100000);
    TS_ASSERT_EQUALS(l.year(), 2132);
    TS_ASSERT_EQUALS(l.month(), 8);
    TS_ASSERT_EQUALS(l.day(), 31);
  }

  void test_constructors( void ) {
    Gregorian j(1858,11,17);
    TS_ASSERT_EQUALS(j.year(), 1858);
    TS_ASSERT_EQUALS(j.month(), 11);
    TS_ASSERT_EQUALS(j.day(), 17);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 0);
  }
  void test_inc(){
    Gregorian g;
    ++g;
    TS_ASSERT_EQUALS(g.day(), 0);
  }
};
