#include <gtest/gtest.h>
#include <string>
#include "Pizza.h"


class PtrTest : public ::testing::Test {
protected:

	void SetUp() {
		std::cout << "PTR TEST SET UP" << std::endl;
	}
	
	void TearDown() {
		std::cout << "PTR TEST TEARED DOWN" << std::endl;
	}
};

TEST_F(PtrTest, ScopeTest) {
	std::shared_ptr<Pizza> pizzaPtr = nullptr;
	{
		Director director;
		PizzaBuilder* builder = new PepperoniPizzaBuilder();
		director.setBuilder(builder);
		pizzaPtr = director.buildPizza();
	}
	EXPECT_EQ(pizzaPtr->getName(), "Pepperoni");
}
