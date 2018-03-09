#pragma once

#include <iostream>
#include <string>
#include <memory>


class Pizza {
private:
	std::string name_;
	std::string sauce_;
	std::string topping_;
	std::string dough_;

public:
	void setName(std::string name) { name_ = name; }
	void setSauce(std::string sauce) { sauce_ = sauce; }
	void setTopping(std::string topping) { topping_ = topping; }
	void setDough(std::string dough) { dough_ = dough; }

	std::string getName() const { return name_; }
	std::string getSauce() const { return sauce_; }
	std::string getTopping() const { return topping_; }
	std::string getDough() const { return dough_; }

	void composition() {
		std::cout << "Pizza with " << sauce_ << " sauce and " << topping_ << " on " << dough_ << " dough";
	}
};

class PizzaBuilder {
protected:
	std::string pizzaName_;
	std::string pizzaSauce_;
	std::string pizzaTopping_;
	std::string pizzaDough_;

public:
	PizzaBuilder() { }
	~PizzaBuilder() { }

	std::shared_ptr<Pizza> getPizza() {
		std::shared_ptr<Pizza> pizza(new Pizza);
		pizza->setName(pizzaName_);
		pizza->setSauce(pizzaSauce_);
		pizza->setTopping(pizzaTopping_);
		pizza->setDough(pizzaDough_);
		return pizza;
	}

	virtual void buildName() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
	virtual void buildDough() = 0;
};

class PepperoniPizzaBuilder : public PizzaBuilder {
public:
	PepperoniPizzaBuilder() : PizzaBuilder() { }
	~PepperoniPizzaBuilder() { }

	void buildName() { pizzaName_ = "Pepperoni"; }
	void buildSauce() { pizzaSauce_ = "Tomamto"; }
	void buildTopping() { pizzaTopping_ = "Pepperoni"; }
	void buildDough() { pizzaDough_ = "Yeast"; }
};

class ChorizoPizzaBuilder : public PizzaBuilder {
public:
	ChorizoPizzaBuilder() : PizzaBuilder() { }
	~ChorizoPizzaBuilder() { }

	void buildName() { pizzaName_ = "Chorizo"; }
	void buildSauce() { pizzaSauce_ = "Tomamto"; }
	void buildTopping() { pizzaTopping_ = "Sausages"; }
	void buildDough() { pizzaDough_ = "Batterless"; }
};

class ChickenCurryPizzaBuilder : public PizzaBuilder {
public:
	ChickenCurryPizzaBuilder() : PizzaBuilder() { }
	~ChickenCurryPizzaBuilder() { }

	void buildName() { pizzaName_ = "Chicken Curry"; }
	void buildSauce() { pizzaSauce_ = "Curry"; }
	void buildTopping() { pizzaTopping_ = "Pepperoni"; }
	void buildDough() { pizzaDough_ = "Yeast"; }
};

class Director {
private:
	PizzaBuilder* builder_;

public:
	void setBuilder(PizzaBuilder* builder) { builder_ = builder; }
	std::shared_ptr<Pizza> buildPizza() {
		builder_->buildName();
		builder_->buildSauce();
		builder_->buildTopping();
		builder_->buildDough();
		std::shared_ptr<Pizza> pizza = builder_->getPizza();
		return pizza;
	}
};
	
	
