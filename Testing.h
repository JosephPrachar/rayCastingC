using namespace std;
typedef int(*test)();

class Testing{
public:
	Testing(ofstream* error);


private:
	test* mTests;
	int mTestsLength;

	ofstream* err;

	void runTests();

	int test_color_constructor_1();
	int test_color_constructor_2();
	int test_color_scale_1();
	int test_color_scale_2();
	int test_color_scaleForPrinting();
	int test_color_multiply_1();
	int test_color_multiply_2();
	int test_color_add_1();
	int test_color_add_2();
	int test_color_copy_1();
	int test_color_equals_1();
	int test_color_equals_2();
	int test_color_capValue_1();
	int test_color_capValue_2();


};