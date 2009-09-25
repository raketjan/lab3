#include <cxxtest/TestSuite.h>

#include "julian.h"
#include "gregorian.h"
using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void test_year( void )
  {
    Julian j;
    TS_ASSERT_EQUALS(j.year(), 1858);
    TS_ASSERT_EQUALS(j.month(), 11);
    // lägg till eller skapa ny med offset 10000
    // ska bli 23e march 1886
    Julian k(10000);
    TS_ASSERT_EQUALS(k.year(), 1886);
    TS_ASSERT_EQUALS(k.month(), 3);
    // 100000 = 20e augusti 2132
    Julian l(100000);
    TS_ASSERT_EQUALS(l.year(), 2132);
    TS_ASSERT_EQUALS(l.month(), 8);
  }
};
