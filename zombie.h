#pragma once
#include <iostream>

class Zombie {
    private:
    	char color;
    public:
	Zombie();
    	Zombie(char type);
    	char getColor();
    	bool operator == (Zombie zom) {
    		if (color == zom.getColor()) {
    			return true;
    		}
    		return false;
    	}
	friend std::ostream& operator<<(std::ostream& output, const Zombie& D) {
	  output << D.color;
	  return output;
	};
};
