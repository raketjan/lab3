#include <cxxtest/TestSuite.h>

#include "gregorian.h"
#include "julian.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void test_year( void )
  {
    Julian j;
    TS_ASSERT_EQUALS(1, 1);
  }
};
