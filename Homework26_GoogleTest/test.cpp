#include"pch.h"
#include"Factorial.h"
#include"Person.h"
#include"Tax.h"
using::testing::Return;
using::testing::AtLeast;
class Person_mock : public Person_interface
{
public:
	~Person_mock() override = default;
	MOCK_METHOD(void, Set_salary, (double salary), (override));
	MOCK_METHOD(double, Get_salary, (), (const,override));
	MOCK_METHOD(void, Set_surname, (std::string surname), (override));
	MOCK_METHOD(std::string, Get_surname, (), (const,override));
};
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
TEST(Person_Test, mock_Tax_1)
{
	Person_mock per_mock;
	EXPECT_CALL(per_mock, Get_salary()).Times(AtLeast(1));
	double tax = Tax(&per_mock, 13);
}
TEST(Person_Test, mock_Tax_2)
{
	Person_mock per_mock;
	EXPECT_CALL(per_mock, Get_salary()).Times(AtLeast(2));
	double tax = Tax(&per_mock, 13);
}
TEST(Person_Test, mock_Tax_3)
{
	Person_mock per_mock;
	EXPECT_CALL(per_mock, Get_salary()).Times(AtLeast(1));
	double tax = Tax(&per_mock, 13);
}
TEST(Person_Test,Tax_check)
{
	Person person;
	person.Set_surname("Gorbachik");
	person.Set_salary(500);
	const double tax = 13;
	ASSERT_TRUE(person.Get_salary() * 13 / 100 == Tax(&person, tax));
	std::cout << "\t" << person.Get_surname() << " salary is " << person.Get_salary()
			  <<"\n\tWithout tax " << person.Get_surname() << " salary is " << person.Get_salary() - Tax(&person,tax) << std::endl;
	
}
TEST(Person_Test, mock_Tax_check)
{
	Person_mock per_mock;
	EXPECT_CALL(per_mock,Get_salary()).Times(2).WillOnce(Return(500)).WillOnce(Return(500));
	EXPECT_TRUE(per_mock.Get_salary() * 13 / 100 == Tax(&per_mock, 13));
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}