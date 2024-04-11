#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr11.2/Pr11.2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSearchStudensFunction)
        {
            const int n = 3;
            Student* students = new Student[n];
            students[0] = { "John", 3, FI, 4, 3, 0 };
            students[1] = { "Alice", 2, IT, 3, 5, 0 };
            students[2] = { "Bob", 4, KN, 5, 4, 0 };

            stringstream ss;
            streambuf* orig = cout.rdbuf();
            cout.rdbuf(ss.rdbuf());
            SearchStudens(students, n);
            cout.rdbuf(orig);

            string expectedOutput = "  2. Alice\n  3. Bob\n";
            Assert::AreEqual(expectedOutput, ss.str());

            delete[] students;
        }

    };
}