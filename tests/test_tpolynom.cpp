#include "pch.h"
#include <string>
#include "..\polynom\TPolynom.h"

using namespace std;

TEST(TPolynom, CanCreatePolynom)
{
	ASSERT_NO_THROW(TPolynom t);
}

TEST(TPolynom, CanCreatePolynomStr)
{
	TPolynom t("xy+xz");

	TPolynom correct;
	correct.AddMonom(1, 1, 1, 0);
	correct.AddMonom(1, 1, 0, 1);

	EXPECT_EQ(t, correct);
}

TEST(TPolynom, NewCreatePolynomZero)
{
	TPolynom t;
	ASSERT_EQ(t.ToStr(), "0");
}

TEST(TPolynom, CanCreateCopy)
{
	TPolynom t;
	ASSERT_NO_THROW(TPolynom t2(t));
}

TEST(TPolynom, CanAssignPolynom)
{
	TPolynom t1;
	t1.AddMonom(2, 0, 0, 0);

	TPolynom t2;

	ASSERT_NO_THROW(t2 = t1);
	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';
	EXPECT_EQ(t1.ToStr(), t2.ToStr());
}

TEST(TPolynom, CanAddMonom)
{
	TPolynom t;

	cout << "t = " << t << '\n';

	ASSERT_NO_THROW(t.AddMonom(1, 1, 1, 1));

	cout << "t = " << t << '\n';
}

TEST(TPolynom, CanAddPolynom_1)
{
	TPolynom t1;
	t1.AddMonom(1, 1, 0, 0);
	t1.AddMonom(1, 0, 0, 0);

	TPolynom t2;
	t2.AddMonom(-1, 1, 0, 0);
	t2.AddMonom(-1, 0, 0, 0);

	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	cout << "t1 + t2 = " << sum << '\n';

	TPolynom correct;

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynomToPolynom_2)
{
	TPolynom t1;
	t1.AddMonom(1, 1, 0, 0);
	t1.AddMonom(1, 0, 0, 0);

	TPolynom t2;
	t2.AddMonom(-1, 1, 0, 0);

	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	cout << "t1 + t2 = " << sum << '\n';

	TPolynom correct;
	correct.AddMonom(1, 0, 0, 0);

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynom_3)
{
	TPolynom t1;
	t1.AddMonom(1, 0, 1, 1);
	t1.AddMonom(2, 1, 0, 1);
	t1.AddMonom(3, 1, 1, 1);

	TPolynom t2;
	t2.AddMonom(1, 0, 1, 1);
	t2.AddMonom(-2, 1, 0, 1);
	t2.AddMonom(3, 1, 1, 1);

	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	cout << "t1 + t2 = " << sum << '\n';

	TPolynom correct("6*x*y*z + 2*y*z");

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynom_4)
{
	TPolynom t1;
	t1.AddMonom(1, 2, 2, 2);
	t1.AddMonom(2, 1, 0, 2);

	TPolynom t2;
	t2.AddMonom(1, 2, 2, 1);
	t2.AddMonom(-2, 0, 0, 2);
	t2.AddMonom(2, 0, 1, 1);

	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	cout << "t1 + t2 = " << sum << '\n';

	TPolynom correct("x2y2z2 + x2y2z + 2xz2 + 2yz - 2z2");

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanSubstractPolynomAndPolynom)
{
	TPolynom t1;
	t1.AddMonom(1, 0, 1, 1);
	t1.AddMonom(2, 1, 0, 1);

	TPolynom t2;
	t2.AddMonom(1, 0, 1, 1);
	t2.AddMonom(3, 1, 1, 1);

	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';

	TPolynom sub;
	ASSERT_NO_THROW(sub = t1 - t2);

	cout << "t1 - t2 = " << sub << '\n';

	TPolynom correct;
	correct.AddMonom(-3, 1, 1, 1);
	correct.AddMonom(2, 1, 0, 1);

	EXPECT_EQ(sub, correct);
}

TEST(TPolynom, CanMultiplyPolynomByMonom)
{
	TPolynom t;
	t.AddMonom(1, 0, 1, 0);
	t.AddMonom(1, 1, 0, 0);

	TMonom m(2, 1, 0, 1);

	cout << "t = " << t << '\n';
	cout << "m = 2*" << m << '\n';

	TPolynom result;
	ASSERT_NO_THROW(result = t * m);

	cout << "t * m = " << result << '\n';

	TPolynom correct;
	correct.AddMonom(2, 2, 0, 1);
	correct.AddMonom(2, 1, 1, 1);

	EXPECT_EQ(result, correct);
}

TEST(TPolynom, CanMultiplyPolynomAndPolynom)
{
	TPolynom t1;
	t1.AddMonom(1, 1, 0, 0);

	TPolynom t2;
	t2.AddMonom(1, 0, 1, 1);
	t2.AddMonom(2, 0, 0, 1);

	cout << "t1 = " << t1 << '\n';
	cout << "t2 = " << t2 << '\n';

	TPolynom result;
	ASSERT_NO_THROW(result = t1 * t2);

	cout << "t1 * t2 = " << result << '\n';

	TPolynom correct("x*y*z+x*z");

	EXPECT_EQ(result, correct);
}