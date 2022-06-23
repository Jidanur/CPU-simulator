#pragma once

class ListItem {
public:
    ListItem();
	virtual int compareTo(ListItem *other) = 0;

	// virtual method to print items using polymorphism
	virtual void print() = 0;

}; // class ListItem
