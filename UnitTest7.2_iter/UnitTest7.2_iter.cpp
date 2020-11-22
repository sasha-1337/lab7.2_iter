#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2_iter/lab7_2_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72iter
{
	TEST_CLASS(UnitTest72iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			int O = 0;
			const int rowCount = 3;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < colCount; i++)
				a[i] = new int[colCount];

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					a[i][j] = 0;


			t = Min(a, rowCount, colCount);
			Assert::AreEqual(t, 0);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;

		}
	};
}
