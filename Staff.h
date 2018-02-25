#include <iostream>


class Waiter {
public:
	virtual std::string takeAnOrder() = 0;
	virtual std::string passToTheKitchen() = 0;
	virtual std::string completeTheOrder() = 0;
	virtual std::string getLanguage() = 0;
};

class Cook {
public:
	virtual std::string startCooking() = 0;
	virtual std::string finishCooking() = 0;
	virtual std::string getLanguage() = 0;
};

class StaffFactory {
public:
	virtual Waiter* getWaiter() = 0;
	virtual Cook* getCook() = 0;
};

class EnWaiter : public Waiter {
public:
	std::string takeAnOrder() { return "The waiter accepted the order"; }
	std::string passToTheKitchen() { return "The waiter delivered order to the kitchen"; }
	std::string completeTheOrder() { return "The waiter completed the order"; }
	std::string getLanguage() { return "ENWaiter"; }
};

class RuWaiter : public Waiter {
public:
	std::string takeAnOrder() { return "Официант принял заказ"; }
	std::string passToTheKitchen() { return "Официант передал заказ на кухню"; }
	std::string completeTheOrder() { return "Официант завершил выполнение заказа"; }
	std::string getLanguage() { return "RUWaiter"; }
};

class EnCook : public Cook {
public:
	std::string startCooking() { return "The chef began to cook a dish"; }
	std::string finishCooking() { return "The chef cooked a dish"; }
	std::string getLanguage() { return "ENCook"; }
};

class RuCook : public Cook {
public:
	std::string startCooking() { return "Повар начал готовить блюдо"; }
	std::string finishCooking() { return "Повар приготовил блюдо"; }
	std::string getLanguage() { return "RUCook"; }
};

class EnStaffFactory : public StaffFactory {
public:
	Waiter* getWaiter() { return new EnWaiter(); }
	Cook* getCook() { return new EnCook(); }
};

class RuStaffFactory : public StaffFactory {
public:
	Waiter* getWaiter() { return new RuWaiter(); }
	Cook* getCook() { return new RuCook(); }
};
	

