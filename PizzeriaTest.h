#include <gtest/gtest.h>
#include <string>
#include "Pizzeria.h"


class PizzeriaTest : public ::testing::Test {
protected:
	Pizzeria pizzeria;

	void SetUp() {
		std::cout << "PIZZERIA TEST SET UP" << std::endl;
	}
	
	void TearDown() {
		std::cout << "PIZZERIA TEST TEARED DOWN" << std::endl;
	}
};

TEST_F(PizzeriaTest, GeneralTest) {
	std::string language[2] = { "EN", "RU" };
	std::string pizzaType[3] = { "Pepperoni", "Chorizo", "Chicken Curry" };
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 3; ++j) {
			pizzeria.newClient(language[i], pizzaType[j]);
			EXPECT_EQ(pizzeria.getWaiterLanguage(), language[i] + "Waiter");
			EXPECT_EQ(pizzeria.getCookLanguage(), language[i] + "Cook");
			EXPECT_EQ(pizzaType[j], pizzeria.getPizza());
		}
	}
}
