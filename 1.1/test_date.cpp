/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "test_date.h"

static date_test suite_date_test;

static CxxTest::List Tests_date_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_date_test( "test_date.h", 12, "date_test", suite_date_test, Tests_date_test );

static class TestDescription_date_test_test_gregorian_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_basic() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 35, "test_gregorian_basic" ) {}
 void runTest() { suite_date_test.test_gregorian_basic(); }
} testDescription_date_test_test_gregorian_basic;

static class TestDescription_date_test_test_gregorian_old : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_old() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 43, "test_gregorian_old" ) {}
 void runTest() { suite_date_test.test_gregorian_old(); }
} testDescription_date_test_test_gregorian_old;

static class TestDescription_date_test_test_gregorian_remote_future : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_remote_future() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 47, "test_gregorian_remote_future" ) {}
 void runTest() { suite_date_test.test_gregorian_remote_future(); }
} testDescription_date_test_test_gregorian_remote_future;

static class TestDescription_date_test_test_gregorian_leap_years : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_leap_years() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 51, "test_gregorian_leap_years" ) {}
 void runTest() { suite_date_test.test_gregorian_leap_years(); }
} testDescription_date_test_test_gregorian_leap_years;

static class TestDescription_date_test_test_gregorian_invalid_dates : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_invalid_dates() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 61, "test_gregorian_invalid_dates" ) {}
 void runTest() { suite_date_test.test_gregorian_invalid_dates(); }
} testDescription_date_test_test_gregorian_invalid_dates;

static class TestDescription_date_test_test_gregorian_copy_and_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_copy_and_assign() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 74, "test_gregorian_copy_and_assign" ) {}
 void runTest() { suite_date_test.test_gregorian_copy_and_assign(); }
} testDescription_date_test_test_gregorian_copy_and_assign;

static class TestDescription_date_test_test_gregorian_compare : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_compare() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 92, "test_gregorian_compare" ) {}
 void runTest() { suite_date_test.test_gregorian_compare(); }
} testDescription_date_test_test_gregorian_compare;

static class TestDescription_date_test_test_compare_gregorian_julian : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_compare_gregorian_julian() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 111, "test_compare_gregorian_julian" ) {}
 void runTest() { suite_date_test.test_compare_gregorian_julian(); }
} testDescription_date_test_test_compare_gregorian_julian;

static class TestDescription_date_test_test_gregorian_operator_plus_plus : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_operator_plus_plus() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 128, "test_gregorian_operator_plus_plus" ) {}
 void runTest() { suite_date_test.test_gregorian_operator_plus_plus(); }
} testDescription_date_test_test_gregorian_operator_plus_plus;

static class TestDescription_date_test_test_gregorian_operator_minus_minus : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_operator_minus_minus() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 143, "test_gregorian_operator_minus_minus" ) {}
 void runTest() { suite_date_test.test_gregorian_operator_minus_minus(); }
} testDescription_date_test_test_gregorian_operator_minus_minus;

static class TestDescription_date_test_test_gregorian_operator_add_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_operator_add_assign() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 158, "test_gregorian_operator_add_assign" ) {}
 void runTest() { suite_date_test.test_gregorian_operator_add_assign(); }
} testDescription_date_test_test_gregorian_operator_add_assign;

static class TestDescription_date_test_test_gregorian_operator_sub_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_operator_sub_assign() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 171, "test_gregorian_operator_sub_assign" ) {}
 void runTest() { suite_date_test.test_gregorian_operator_sub_assign(); }
} testDescription_date_test_test_gregorian_operator_sub_assign;

static class TestDescription_date_test_test_gregorian_add_month : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_add_month() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 185, "test_gregorian_add_month" ) {}
 void runTest() { suite_date_test.test_gregorian_add_month(); }
} testDescription_date_test_test_gregorian_add_month;

static class TestDescription_date_test_test_to_be_sure : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_to_be_sure() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 359, "test_to_be_sure" ) {}
 void runTest() { suite_date_test.test_to_be_sure(); }
} testDescription_date_test_test_to_be_sure;

static class TestDescription_date_test_test_gregorian_operator_plus_plus_postfix : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_operator_plus_plus_postfix() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 365, "test_gregorian_operator_plus_plus_postfix" ) {}
 void runTest() { suite_date_test.test_gregorian_operator_plus_plus_postfix(); }
} testDescription_date_test_test_gregorian_operator_plus_plus_postfix;

static class TestDescription_date_test_test_gregorian_operator_minus_minus_postfix : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_gregorian_operator_minus_minus_postfix() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 374, "test_gregorian_operator_minus_minus_postfix" ) {}
 void runTest() { suite_date_test.test_gregorian_operator_minus_minus_postfix(); }
} testDescription_date_test_test_gregorian_operator_minus_minus_postfix;

static class TestDescription_date_test_test_minus : public CxxTest::RealTestDescription {
public:
 TestDescription_date_test_test_minus() : CxxTest::RealTestDescription( Tests_date_test, suiteDescription_date_test, 384, "test_minus" ) {}
 void runTest() { suite_date_test.test_minus(); }
} testDescription_date_test_test_minus;

#include <cxxtest/Root.cpp>
