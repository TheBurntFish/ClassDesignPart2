#pragma once

#include <string>

using namespace std;

class item {
	
public:
	item() {
		itemName = "";
		itemID = 0;
		itemPrice = 0.0;
		itemQuantity = 0;
	};
	item(string name, long ID, double price, int quantity) {
		itemName = name;
		itemID = ID;
		itemPrice = price;
		itemQuantity = quantity;
	}
	void setAll(string name, long ID, double price, int quantity){
		itemName = name;
		itemID = ID;
		itemPrice = price;
		itemQuantity = quantity;
	}

	void setName(string name) {
		itemName = name;
	}
	void setID(long ID) {
		itemID = ID;
	}
	void setPrice(double price) {
		itemPrice = price;
	}
	void setQuantity(int quantity) {
		itemQuantity = quantity;
	}

	string getName() const {
		return itemName;
	}
	long getID() const {
		return itemID;
	}
	double getPrice() const {
		return itemPrice;
	}
	int getQuantity() const {
		return itemQuantity;
	}

private:
	string itemName = "";
	long itemID = 0;
	double itemPrice = 0.0;
	int itemQuantity = 0;
};




class order {
public:
	order() {};

	item orderItem[10];
	int orderQuantity[10];
	void addList(item item, int quantity, int position) {
		orderItem[position] = item;
		orderQuantity[position] = quantity;
		cout << "Added " << quantity << " " << item.getName() << " to cart." << endl;
	}

	string getPrice() const {
		for (int i = 0; i < 10; i++) {
			total = total + (orderItem[i].getPrice() * orderQuantity[i]);
		}
		return "$" + to_string(total);
	}

	item getOrderItem(int index) const{
		return orderItem[index];
	}
	int getOrderQuantity(int index) const {
		return orderQuantity[index];
	}

private:
	mutable double total = 0.0;
};



class store {
public:
	store() {};
	void addStorage(item item) {
		storage[item.getID()] = item;
	}
	/*
	void displayStorage() {
		for (int i = 0; i < 100; i++) {
			if(storage[i].getName().compare("") != 0)
				cout << storage[i].getName() << " x " << storage[i].getQuantity() << endl;
		}

	}
	*/
	item getStorage(int index) const {
		return storage[index];
	}

	void processOrder(const order& Order) {
		cout << "Processing order..." << endl;
		for (int i = 0; i < 10; i++) {
			if (Order.getOrderItem(i).getName().compare("") != 0) {
				//basically set store storage item quantity =- order quantity
				storage[Order.getOrderItem(i).getID()].setQuantity
				(
					storage[Order.getOrderItem(i).getID()].getQuantity() - Order.getOrderQuantity(i)
				);

			}
		}
		cout << "Order processed." << endl;
	}



private:
	item storage[100];
};







//io overload for item
ostream& operator << (ostream& out, const item& item) {
	out << "Name: " << item.getName() << "\n"
		<< "ID: " << item.getID() << "\n"
		<< "Price: " << item.getPrice() << "\n"
		<< "Quantity in stock: " << item.getQuantity() << "\n";
	return out;
}



//io overload for store
ostream& operator << (ostream& out, const store& store) {
	for (int i = 0; i < 100; i++) {
		if (store.getStorage(i).getName().compare("") != 0)
			//didn't think this would work
			out << store.getStorage(i).getName() << " x " << store.getStorage(i).getQuantity() << "\n";
	}
	
	return out;
}
