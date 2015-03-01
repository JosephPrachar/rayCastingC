#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTest {
	TEST_CLASS(Test_Color) {
	public:
		TEST_METHOD(get) {
			Color color = Color(.1, .3, .7);

			Assert::AreEqual(color.getRed(), .1f);
			Assert::AreEqual(color.getGreen(), .3f);
			Assert::AreEqual(color.getBlue(), .7f);
		}
		TEST_METHOD(equals){
			Color one = Color(.1, .3, .7);
			Color two = Color(.1, .3, .7);
			Color three = Color(.1,.3, .8);

			Assert::AreEqual(one == two, true);
			Assert::AreEqual(two == one, true);
			Assert::AreEqual(one != two, false);

			Assert::AreEqual(one == three, false);
			Assert::AreEqual(one != three, true);
		}
		TEST_METHOD(scale){
			Color one = Color(1,2,3);
			Color one2 = Color(1,2, 3);
			Color twice = Color(2, 4, 6);
			Color half = Color(.5, 1, 1.5);

			one.scale(2);
			Assert::AreEqual(one == twice, true);
			one2.scale(.5);
			Assert::AreEqual(one2 == half, true);

			twice.scaleForPrinting();
			Assert::AreEqual(twice == Color(255, 255, 255), true);

			half.scaleForPrinting();
			Assert::AreEqual(half == Color(127, 255, 255), true);
		}
		TEST_METHOD(mult_Add){
			Color color = Color(.1, .5, .3);

			color.add(Color(.1, .2, .6));
			Assert::AreEqual(color == Color(.2, .7, .9), true);

			color.multiply(Color(.5, .1, 1));
			Assert::AreEqual(color == Color(.1, .07, .9), true);
		}
		TEST_METHOD(copy){
			Color one = Color(1,3,5);

			Assert::AreEqual(one == one.copy(), true);
		}
	};
	TEST_CLASS(Test_Finish) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Intersection) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Light) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Point) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Ray) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_RayCaster) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Sphere) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Vector) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
	TEST_CLASS(Test_Window) {
	public:
		TEST_METHOD(get) {
			Assert::AreEqual(1, 1);
		}
	};
}