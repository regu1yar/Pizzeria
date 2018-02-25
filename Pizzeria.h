#include <iostream>
#include <string>
#include <cassert>
#include "Pizza.h"
#include "Staff.h"


class Pizzeria {
private:
	Waiter* waiter_;
	Cook* cook_;
	Director director_;
	
	void serveTheClient() {
		std::cout << waiter_->takeAnOrder() << std::endl;
		std::cout << waiter_->passToTheKitchen() << std::endl;
		std::cout << cook_->startCooking() << std::endl;
		Pizza pizza = director_.buildPizza();
		pizza.composition();
		std::cout << " was cooked" << std::endl;
		std::cout << cook_->finishCooking() << std::endl;
		std::cout << waiter_->completeTheOrder() << std::endl;
	}
	
public:
	Pizzeria() : waiter_(nullptr), cook_(nullptr) { }
	~Pizzeria() {
		delete waiter_;
		delete cook_;
	}

	void newClient(std::string language, std::string pizza) {
		StaffFactory* staffFactory = nullptr;
		if(language.compare("EN") == 0) staffFactory = new EnStaffFactory();
		else if(language.compare("RU") == 0) staffFactory = new RuStaffFactory();
		else {
			std::cout << "Unsupported language" << std::endl;
			return;
		}
		
		PizzaBuilder* builder = nullptr;
		if(pizza.compare("Pepperoni") == 0) builder = new PepperoniPizzaBuilder();
		else if(pizza.compare("Chorizo") == 0) builder = new ChorizoPizzaBuilder();
		else if(pizza.compare("Chicken Curry") == 0) builder = new ChickenCurryPizzaBuilder();
		else {
			delete staffFactory;
			std::cout << "Not in stock" << std::endl;
			return;
		}
		delete waiter_;
		waiter_ = staffFactory->getWaiter();
		delete cook_;
		cook_ = staffFactory->getCook();
		director_.setBuilder(builder);
		serveTheClient();
		std::cout << std::endl;
	}
	
	std::string getWaiterLanguage() {
		assert(waiter_ != nullptr);
		return waiter_->getLanguage();
	}
	std::string getCookLanguage() {
		assert(cook_ != nullptr);
		return cook_->getLanguage();
	}
	std::string getPizza() {
		Pizza pizza = director_.buildPizza();
		return pizza.getName();
	}
		
};
