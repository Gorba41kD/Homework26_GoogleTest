#include"pch.h"
#include"Factorial.h"
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
TEST(TestFactorialTest, HandlesZeroInput) {
	EXPECT_EQ(Factorial(0), 1);
}
TEST(TestFactorialTest, HandlesPositiveInput) {
	EXPECT_EQ(Factorial(1), 1);
	EXPECT_EQ(Factorial(2), 2);
	EXPECT_EQ(Factorial(3), 6);
	EXPECT_EQ(Factorial(4), 24);
	EXPECT_EQ(Factorial(5), 120);
	EXPECT_EQ(Factorial(8), 40320);
}
class CRect
{
private:
	int m_x;
	int m_y;
public:
	void setX(int x)
	{
		m_x = x;
	}
	void setY(int y)
	{
		m_y = y;
	}
	int GetPerimeter()
	{
		return 2 * (m_x + m_y);
	}
};
class CRectTest : public ::testing::Test
{};
TEST_F(CRectTest, CheckPerimeter)
{
	CRect rect;
	rect.setX(5);
	rect.setY(6);
	ASSERT_TRUE(rect.GetPerimeter() == 22);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}