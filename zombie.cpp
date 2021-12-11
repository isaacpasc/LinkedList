
#include "zombie.h"

inline Zombie::Zombie() {
  
}

inline Zombie::Zombie(char type) {
    color = type;
}

inline char Zombie::getColor() {
	return color;
}
