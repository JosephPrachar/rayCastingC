#include "stdafx.h"
//#include "CppUnitTest.h"
//#include "cppunittestassert.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace Microsoft
//{
//	namespace VisualStudio
//	{
//		namespace CppUnitTestFramework
//		{
//			template<> static std::wstring ToString<Point> (const Point& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Point> (const Point* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Point> (Point* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Color> (const Color& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Color> (const Color* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Color> (Color* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Finish> (const Finish& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Finish> (const Finish* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Finish> (Finish* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Intersection> (const Intersection& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Intersection> (const Intersection* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Intersection> (Intersection* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Light> (const Light& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Light> (const Light* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Light> (Light* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Ray> (const Ray& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Ray> (const Ray* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Ray> (Ray* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Sphere> (const Sphere& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Sphere> (const Sphere* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Sphere> (Sphere* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Vector> (const Vector& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Vector> (const Vector* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Vector> (Vector* t)		{ RETURN_WIDE_STRING(t); }
//
//			template<> static std::wstring ToString<Window> (const Window& t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Window> (const Window* t) { RETURN_WIDE_STRING(t); }
//			template<> static std::wstring ToString<Window> (Window* t)		{ RETURN_WIDE_STRING(t); }
//		}
//	}
//}
//
//namespace MyTest {
//	TEST_CLASS(Test_Color) {
//	public:
//		TEST_METHOD(get) {
//			Color color = Color(.1, .3, .7);
//
//			Assert::AreEqual(color.getRed(), .1f);
//			Assert::AreEqual(color.getGreen(), .3f);
//			Assert::AreEqual(color.getBlue(), .7f);
//		}
//		TEST_METHOD(equals){
//			Color one = Color(.1, .3, .7);
//			Color two = Color(.1, .3, .7);
//			Color three = Color(.1,.3, .8);
//
//			Assert::AreEqual(one == two, true);
//			Assert::AreEqual(two == one, true);
//			Assert::AreEqual(one != two, false);
//
//			Assert::AreEqual(one == three, false);
//			Assert::AreEqual(one != three, true);
//		}
//		TEST_METHOD(scale){
//			Color one = Color(1,2,3);
//			Color one2 = Color(1,2, 3);
//			Color twice = Color(2, 4, 6);
//			Color half = Color(.5, 1, 1.5);
//
//			one.scale(2);
//			Assert::AreEqual(one, twice);
//			one2.scale(.5);
//			Assert::AreEqual(one2, half);
//
//			twice.scaleForPrinting();
//			Assert::AreEqual(twice, Color(255, 255, 255));
//
//			half.scaleForPrinting();
//			Assert::AreEqual(half, Color(127, 255, 255));
//		}
//		TEST_METHOD(mult_Add){
//			Color color = Color(.1, .5, .3);
//
//			color.add(Color(.1, .2, .6));
//			Assert::AreEqual(color, Color(.2, .7, .9));
//
//			color.multiply(Color(.5, .1, 1));
//			Assert::AreEqual(color, Color(.1, .07, .9));
//		}
//		TEST_METHOD(copy){
//			Color one = Color(1,3,5);
//			Color copy = one.copy();
//
//			Assert::AreEqual(one, copy);
//			Assert::AreNotEqual(&one, &copy);
//		}
//	};
//	TEST_CLASS(Test_Finish) {
//	public:
//		TEST_METHOD(get) {
//			Finish fin = Finish(.2, .4, .5, .05);
//
//			Assert::AreEqual(fin.getAmbient(), .2f);
//			Assert::AreEqual(fin.getDiffuse(), .4f);
//			Assert::AreEqual(fin.getSpecular(), .5f);
//			Assert::AreEqual(fin.getRoughness(), .05f);
//		}
//		TEST_METHOD(equal){
//			Finish one = Finish(.1, .3, .7, .9);
//			Finish two = Finish(.1, .3, .7, .9);
//			Finish three = Finish(.1,.3, .8, .9);
//
//			Assert::AreEqual(one == two, true);
//			Assert::AreEqual(two == one, true);
//			Assert::AreEqual(one != two, false);
//
//			Assert::AreEqual(one == three, false);
//			Assert::AreEqual(one != three, true);
//		}
//		TEST_METHOD(copy){
//			Finish one = Finish(1,3,5, 7);
//			Finish copy = one.copy();
//
//			Assert::AreEqual(one, copy);
//			Assert::AreNotEqual(&one, &copy);
//		}
//	};
//	TEST_CLASS(Test_Intersection) {
//	public:
//		TEST_METHOD(copy) {
//			Intersection one = Intersection();
//			Intersection copy = one.copy();
//
//			Assert::AreEqual(one.mPoint, copy.mPoint);
//			Assert::AreEqual(one.mSphere, copy.mSphere);
//			Assert::AreNotEqual(&one, &copy);
//		}
//	};
//	TEST_CLASS(Test_Light) {
//	public:
//		TEST_METHOD(get) {
//			Light one = Light(Point(1,2,3), Color(4, 5, 6));
//
//			Assert::AreEqual(one.getColor(), Color(4, 5, 6));
//			Assert::AreEqual(one.getPoint(), Point(1, 2, 3));
//		}
//		TEST_METHOD(equals) {
//			Light one = Light(Point(1,2,3), Color(.1, .3, .7));
//			Light two = Light(Point(1,2,3), Color(.1, .3, .7));
//			Light three = Light(Point(3,2,1), Color(.1,.3, .8));
//
//			Assert::AreEqual(one == two, true);
//			Assert::AreEqual(two == one, true);
//			Assert::AreEqual(one != two, false);
//
//			Assert::AreEqual(one == three, false);
//			Assert::AreEqual(one != three, true);
//		}
//	};
//	TEST_CLASS(Test_Point) {
//	public:
//		TEST_METHOD(get) {
//			Point one = Point(1,2,3);
//
//			Assert::AreEqual(one.getX(), 1.0f);
//			Assert::AreEqual(one.getY(), 2.0f);
//			Assert::AreEqual(one.getZ(), 3.0f);
//		}
//		TEST_METHOD(equals){
//			Point one = Point(.1, .3, .7);
//			Point two = Point(.1, .3, .7);
//			Point three = Point(.1,.3, .8);
//
//			Assert::AreEqual(one == two, true);
//			Assert::AreEqual(two == one, true);
//			Assert::AreEqual(one != two, false);
//
//			Assert::AreEqual(one == three, false);
//			Assert::AreEqual(one != three, true);
//		}
//		TEST_METHOD(translate){
//			Point p = Point(1,2,3);
//			Point p1 = p.copy();
//			Vector v = Vector(0,0,0);
//			p.translate(v);
//
//			Assert::AreEqual(p, p1);
//
//			Vector v1 = Vector(4,5,6);
//			p.translate(v1);
//			Assert::AreEqual(p, Point(5, 7, 9));
//
//		}
//		TEST_METHOD(copy){
//			Point one = Point(1,2,3);
//			Point copy = one.copy();
//
//			Assert::AreEqual(one, copy);
//			Assert::AreNotEqual(&one, &copy);
//		}
//		TEST_METHOD(distance){
//			Point origin = Point(0,0,0);
//			Point one = Point(1,1,0);
//
//			Assert::AreEqual(one.distance(origin), (float)sqrt(2), .0001f);
//			Assert::AreEqual(one.distance(origin), origin.distance(one));
//
//		}
//		TEST_METHOD(vectorFromTo){
//			Point p1 = Point(1,2,3);
//			Point p2 = Point(0,0,0);
//			Vector v1 = Point::vectorFromTo(p1, p2);
//			Vector v2 = Point::vectorFromTo(p2, p1);
//			Vector equals = Vector(-1, -2, -3);
//
//			Assert::AreEqual(v1 == equals, true);
//			equals.scale(-1);
//			Assert::AreEqual(v2 == equals, true);
//		}
//		TEST_METHOD(differenceVector){
//			Point p1 = Point(1,2,3);
//			Point p2 = Point(0,0,0);
//			Vector v1 = Point::differenceVector(p1, p2);
//			Vector v2 = Point::differenceVector(p2, p1);
//			Vector equals = Vector(1, 2, 3);
//
//			Assert::AreEqual(v1 == equals, true);
//			equals.scale(-1);
//			Assert::AreEqual(v2 == equals, true);
//		}
//	};
//	TEST_CLASS(Test_Ray) {
//	public:
//		TEST_METHOD(get) {
//			Ray one = Ray(Point(1,2,3), Vector(4,5,6));
//
//			Assert::AreEqual(one.getPoint(), Point(1,2,3));
//			Assert::AreEqual(one.getDirection(), Vector(4,5,6));
//		}
//		TEST_METHOD(equals){
//			Ray one = Ray(Point(.1, .3, .7), Vector(1,2,3));
//			Ray two = Ray(Point(.1, .3, .7), Vector(1,2,3));
//			Ray three = Ray(Point(.1,.3, .8), Vector(1,2,3));
//
//			Assert::AreEqual(one == two, true);
//			Assert::AreEqual(two == one, true);
//			Assert::AreEqual(one != two, false);
//
//			Assert::AreEqual(one == three, false);
//			Assert::AreEqual(one != three, true);
//		}
//	};
//	TEST_CLASS(Test_RayCaster) {
//	public:
//		TEST_METHOD(castRay) {
//
//		}
//	};
//	TEST_CLASS(Test_Sphere) {
//	public:
//		TEST_METHOD(get) {
//			Sphere one = Sphere(Point(1,2,3), 4, Color(5, 6, 7), Finish(8, 9, 10, 11));
//
//			Assert::AreEqual(one.getCenter(), Point(1,2,3));
//			Assert::AreEqual(one.getRadius(), 4.0f);
//			Assert::AreEqual(one.getColor(), Color(5, 6, 7));
//			Assert::AreEqual(one.getFinish(), Finish(8,9,10,11));
//		}
//		TEST_METHOD(equals){
//			Sphere one = Sphere(Point(.1, .3, .7), 4, Color(5, 6, 7), Finish(8, 9, 10, 11));
//			Sphere two = Sphere(Point(.1, .3, .7), 4, Color(5, 6, 7), Finish(8, 9, 10, 11));
//			Sphere three = Sphere(Point(.1, .3, .7), 4, Color(4, 6, 7), Finish(8, 9, 10, 11));
//
//			Assert::AreEqual(one == two, true);
//			Assert::AreEqual(two == one, true);
//			Assert::AreEqual(one != two, false);
//
//			Assert::AreEqual(one == three, false);
//			Assert::AreEqual(one != three, true);
//		}
//		TEST_METHOD(rayIntersection1){
//			Sphere sphere = Sphere(Point(5, 1, 0), 1, Color(1,1,1), Finish(1,1,1,1));
//			Ray ray = Ray(Point(0,0,0), Vector(1,0,0));
//			bool hits = false;
//			Point result = sphere.rayIntersection(ray, &hits);
//
//			Assert::AreEqual(result, Point(5, 0, 0));
//			Assert::AreEqual(hits, true);
//		}
//		TEST_METHOD(rayIntersection2){
//			Sphere sphere = Sphere(Point(1, 1, 0), 1, Color(1,1,1), Finish(1,1,1,1));
//			Ray ray = Ray(Point(0,0,0), Vector(1,1,0));
//			float val = sqrt(3.0 / 2.0 - sqrt(2));
//
//			bool hits = false;
//			Point result = sphere.rayIntersection(ray, &hits);
//
//			Assert::AreEqual(result, Point(val, val, 0));
//			Assert::AreEqual(hits, true);
//		}
//		TEST_METHOD(rayIntersection3){
//			Sphere sphere = Sphere(Point(1, 1, 1), 1, Color(1,1,1), Finish(1,1,1,1));
//			Ray ray = Ray(Point(0,0,0), Vector(-1,-1,-1));
//
//			bool hits = false;
//			Point result = sphere.rayIntersection(ray, &hits);
//
//			Assert::AreEqual(hits, false);
//		}
//		TEST_METHOD(normal1){
//			Sphere sphere = Sphere(Point(1, 1, 0), 1, Color(1,1,1), Finish(1,1,1,1));
//			Point p = Point(1,0,0);
//			Vector n = sphere.normalAtPoint(p);
//			Assert::AreEqual(n, Vector(0,-1,0));
//		}
//		TEST_METHOD(normal2){
//			Sphere sphere = Sphere(Point(1, 0, 0), 1, Color(1,1,1), Finish(1,1,1,1));
//			Point p = Point(0,0,0);
//			Vector n = sphere.normalAtPoint(p);
//			Assert::AreEqual(n, Vector(-1,0,0));
//		}
//		TEST_METHOD(copy){
//			Sphere one = Sphere(Point(1,2,3), 4, Color(5, 6, 7), Finish(8, 9, 10, 11));
//			Sphere copy = one.copy();
//
//			Assert::AreEqual(one, copy);
//			Assert::AreNotEqual(&one, &copy);
//		}
//	};
//	TEST_CLASS(Test_Vector) {
//	public:
//		TEST_METHOD(get) {
//			Vector one = Vector(1,2,3);
//
//			Assert::AreEqual(one.getX(), 1.0f);
//			Assert::AreEqual(one.getY(), 2.0f);
//			Assert::AreEqual(one.getZ(), 3.0f);
//		}
//		TEST_METHOD(normalize){
//
//		}
//		TEST_METHOD(scale){
//
//		}
//		TEST_METHOD(dotWith){
//
//		}
//		TEST_METHOD(subtract){
//
//		}
//		TEST_METHOD(copy){
//			Sphere one = Sphere(Point(1,2,3), 4, Color(5, 6, 7), Finish(8, 9, 10, 11));
//			Sphere copy = one.copy();
//
//			Assert::AreEqual(one, copy);
//			Assert::AreNotEqual(&one, &copy);
//		}
//	};
//}
