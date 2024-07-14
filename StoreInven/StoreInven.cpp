// StoreInven.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


class StoreInventory {
private:
	string itemName;
	string location;
	int numItems;

public:
	friend ostream& operator << (ostream&, const StoreInventory&);

	StoreInventory(string item, string locationItem, int numOfItems) {
		itemName = item;
		location = locationItem;
		numItems = numOfItems;
	}

	void setItem(string item) {
		itemName = item;
	}

	void setLocation(string locationItem) {
		location = locationItem;
	}

	void setNumber(int num) {
		if (numItems > 0) {
			numItems = num;
		}
		else {
			numItems = 0;
		}
	}

	int getNumItems() {
		return numItems;
	}

	string getItemNames() {
		return itemName;
	}

	string getLocation() {
		return location;
	}

	
	StoreInventory operator++(int) {
		StoreInventory temp(itemName, location, numItems);
		numItems++;
		return temp;
	}

	//TESTED
	StoreInventory operator--(int) {
		StoreInventory temp(itemName, location, numItems);
		numItems--;
		return temp;
	}

	//TESTED
	bool operator>(const StoreInventory& other) const {
		return numItems > other.numItems;
	}

	//TESTED
	bool operator<(const StoreInventory& other) const {
		return !(*this > other);
	}

	
	//NEED TO TEST.
	bool operator==(const StoreInventory& other) const {
		return itemName = other.itemName;
	}
	
	//NEED TO ADD INPUT STREAM OPERATOR.
	//NEED TO ADD ADDITION OPERATOR OVERLOADER.
	
};

ostream& operator << (ostream& strm, const StoreInventory& s) {
	strm << "Item:" << s.itemName << ", Location:" << s.location << ", Number: " << s.numItems;
	return strm;
}

int main() {
	StoreInventory item1("soup", "aisle1" , 24);
	StoreInventory item2("bread", "aisle3", 4);
	StoreInventory item3("soup", "aisle2", 5);
	std::cout << "Item: " << item1.getItemNames() << "\n";
	std::cout << "Number of Item: " << item1.getNumItems() << "\n";
	std::cout << "Location: " << item1.getLocation() << "\n";
	item1++;
	std::cout << "Updated Item number: " << item1.getNumItems() << "\n";
	item1--;
	std::cout << "Updated Item Number: " << item1.getNumItems() << "\n";
	
	if (item1 > item3) {
	std::cout << "More of Item 1";
	}
	else {
	std::cout << "More of Item 3";
	};

	std::cout << item2 << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
