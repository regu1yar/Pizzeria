#include <iostream>
#include <string>


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

	std::string getName() { return name_; }
	std::string getSauce() { return sauce_; }
	std::string getTopping() { return topping_; }
	std::string getDough() { return dough_; }

	void composition() {
		std::cout << "Pizza with " << sauce_ << " sauce and " << topping_ << " on " << dough_ << " dough";
	}
};

class PizzaBuilder {
protected:
	Pizza* pizza_;

public:
	PizzaBuilder() : pizza_(nullptr) { }
	~PizzaBuilder() { delete pizza_; }

	Pizza getPizza() { return *pizza_; }
	void createPizza() {
		delete pizza_;		
		pizza_ = new Pizza;
	}

	virtual void buildName() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
	virtual void buildDough() = 0;
};

class PepperoniPizzaBuilder : public PizzaBuilder {
public:
	PepperoniPizzaBuilder() : PizzaBuilder() { }
	~PepperoniPizzaBuilder() { delete pizza_; }

	void buildName() { pizza_->setName("Pepperoni"); }
	void buildSauce() { pizza_->setSauce("Tomamto"); }
	void buildTopping() { pizza_->setTopping("Pepperoni"); }
	void buildDough() { pizza_->setDough("Yeast"); }
};

class ChorizoPizzaBuilder : public PizzaBuilder {
public:
	ChorizoPizzaBuilder() : PizzaBuilder() { }
	~ChorizoPizzaBuilder() { delete pizza_; }

	void buildName() { pizza_->setName("Chorizo"); }
	void buildSauce() { pizza_->setSauce("Tomamto"); }
	void buildTopping() { pizza_->setTopping("Sausages"); }
	void buildDough() { pizza_->setDough("Batterless"); }
};

class ChickenCurryPizzaBuilder : public PizzaBuilder {
public:
	ChickenCurryPizzaBuilder() : PizzaBuilder() { }
	~ChickenCurryPizzaBuilder() { delete pizza_; }

	void buildName() { pizza_->setName("Chicken Curry"); }
	void buildSauce() { pizza_->setSauce("Curry"); }
	void buildTopping() { pizza_->setTopping("Pepperoni"); }
	void buildDough() { pizza_->setDough("Yeast"); }
};

class Director {
private:
	PizzaBuilder* builder_;

public:
	void setBuilder(PizzaBuilder* builder) { builder_ = builder; }
	Pizza buildPizza() {
		builder_->createPizza();
		builder_->buildName();
		builder_->buildSauce();
		builder_->buildTopping();
		builder_->buildDough();
		Pizza pizza = builder_->getPizza();
		return pizza;
	}
};
	
	
