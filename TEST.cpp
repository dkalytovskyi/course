#include "stdafx.h"
#include "iostream"
#include "CourseWork.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

TEST_CASE("Insert & inorder test") {
	Tree myTree;	
	myTree.insert(5);
	CHECK(myTree.inorder().compare("5 ") == 0);
	myTree.insert(123);
	myTree.insert(562);
	CHECK(myTree.inorder().compare("5 123 562 ") == 0);
}
TEST_CASE("Insert test") {
	Tree myTree;
	CHECK_NOTHROW(myTree.insert(674));
	CHECK_NOTHROW(myTree.insert(123674));
	CHECK_NOTHROW(myTree.insert(-13245));
	CHECK_NOTHROW(myTree.insert(-100000000));
	CHECK_NOTHROW(myTree.insert(50826758));
}
TEST_CASE("Unique test") {
	Tree myTree;
	myTree.insert(-8);
	myTree.insert(-8);
	myTree.insert(0);
	myTree.insert(39);
	myTree.insert(87);
	myTree.insert(87);
	myTree.insert(-8);
	CHECK(myTree.unique().compare("0 39 ") == 0);
}
TEST_CASE("Max Times Test") {
	Tree myTree;
	myTree.insert(12);
	myTree.insert(12);
	myTree.insert(12);
	myTree.insert(12);
	myTree.insert(-5);
	myTree.insert(23);
	myTree.insert(23);
	myTree.insert(23);
	myTree.insert(23);
	myTree.insert(90);
	myTree.insert(90);
	CHECK(myTree.maxTimes().compare("12 23 ") == 0);
}