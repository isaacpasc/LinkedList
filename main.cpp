#include "linkedList.h"
#include "node.h"
#include "zombie.h"
#include "linkedList.cpp"
#include "node.cpp"
#include "zombie.cpp"
#include <random>
#include <iostream>
#include <string>

int randomIntBetween(int a, int b);
char randomColor();

int main(int argc, char** argv) {
    // initialize variables:
    int ans = 1;
    bool keepPlaying = true;
    int maxRounds = 0;
    int randomAction = 0;

    // creation of conga list of type Zombie
    LinkedList<Zombie> conga;

    // play loop until user stops
    while (keepPlaying) {
        std::cout << "Enter How Many Rounds To Run: ";
        scanf("%d", &maxRounds);

        // loop for desired rounds
        for (int round = 0; round <= maxRounds; round++) {

            // begin each round with printed list and length
            std::cout << "\n\nRound: " << round << "\nThe Zombie Party keeps on groaning!\nSize: " << conga.getLength() << " :: " << std::endl;
            conga.printList();
            std::cout << "\n" << std::endl;

            // if its the first round set up the list with zombies
            if (round == 0) {
                Zombie newZombie(randomColor());
                Zombie newZombie1('R');
                Zombie newZombie2('Y');
                Zombie newZombie3('G');
                Zombie newZombie4('B');
                Zombie newZombie5('M');
                Zombie newZombie6('C');
                conga.addToFront(newZombie);
                conga.addToEnd(newZombie1);
                conga.addToEnd(newZombie2);
                conga.addToEnd(newZombie3);
                conga.addToEnd(newZombie4);
                conga.addToEnd(newZombie5);
                conga.addToEnd(newZombie6);
                int randomBrains = randomIntBetween(2,5);
                for (int i = 0; i < randomBrains; i++) {
                    char type = randomColor();
                    Zombie newZombie7(type);
                    Zombie newZombie8(type);
                    Zombie newZombie9(type);
                    conga.addToFront(newZombie7);
                    conga.addToEnd(newZombie8);
                    conga.addAtIndex(newZombie9, (conga.getLength()/2));
                }
            } 
            // choose random action
            randomAction = randomIntBetween(1,7);
            switch (randomAction) {
        	    case 1: {
                    // engine action:
                        Zombie newZombie10(randomColor());
                        conga.addToFront(newZombie10);
        	        }
                        std::cout << "A zombie jumps in the front of the line! (ENGINE)\n" << std::endl;
                        break;
        	    case 2: {
                    // caboose action:
                        Zombie newZombie11(randomColor());
                        conga.addToEnd(newZombie11);
        	        }
        		std::cout << "A zombie pulls up the rear! (CABOOSE)\n" << std::endl;
                        break;
        	    case 3: {
                    // jump in line action:
                        Zombie newZombie12(randomColor());
                        conga.addAtIndex(newZombie12, randomIntBetween(0,conga.getLength()));
        	        }
        		std::cout << "A zombie jumps anywhere in the party (JUMP IN THE LINE!)\n" << std::endl;
                        break;
        	    case 4: {
                    // everyone out action:
                        Zombie newZombie13(randomColor());
                        conga.removeAllOf(newZombie13);
        	        }
        		std::cout << "A zombie enters the party and kicks out his entire family (EVERYONE OUT!)\n" << std::endl;
                        break;
        	    case 5: {
                    // youre done action:
                        Zombie newZombie14(randomColor());
                        conga.removeTheFirst(newZombie14);
        	        }
        		std::cout << "A zombie enters the party and kicks out his brother (YOU'RE DONE!)\n" << std::endl;
                        break;
        	    case 6: {
                    // brains action:
                        char type = randomColor();
                        Zombie newZombie15(type);
                        Zombie newZombie16(type);
                        Zombie newZombie17(type);
                        conga.addToFront(newZombie15);
                        conga.addToEnd(newZombie16);
                        conga.addAtIndex(newZombie17, (conga.getLength()/2));
        	        }
        		std::cout << "A zombie brings its friends to the party (BRAINS!)\n" << std::endl;
                        break;
        	    case 7: {
                    // rainbow brains action:
                        Zombie newZombie24(randomColor());
                        Zombie newZombie18('R');
                        Zombie newZombie19('Y');
                        Zombie newZombie20('G');
                        Zombie newZombie21('B');
                        Zombie newZombie22('M');
                        Zombie newZombie23('C');
                        conga.addToFront(newZombie24);
                        conga.addToEnd(newZombie18);
                        conga.addToEnd(newZombie19);
                        conga.addToEnd(newZombie20);
                        conga.addToEnd(newZombie21);
                        conga.addToEnd(newZombie22);
                        conga.addToEnd(newZombie23);
        	        }

                    // end with print list and length
        		std::cout << "A zombie brought a whole party itself! (RAINBOW BRAINS!)\n" << std::endl;
                        break;
                    }
                    std::cout << "The conga line is now: " << conga.getLength() << " :: " << std::endl;
                    conga.printList();
                    std::cout << "\n" << "*********************************" << std::endl;
                }

                // after loop of rounds ask to continue
                std::cout << "Would You Like To Continue?\n" << "Enter (1=yes,0=no): " << std::endl;
                scanf("%d", &ans);
                if (ans != 1) {
                    keepPlaying = false;
                }
    }
    return 0;
}


// helper function to find random int between two ints
int randomIntBetween(int a, int b) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a,b);
    return dist6(rng);
}

// helper function to generate random char of zombie type/color
char randomColor() {
    int randomCol = randomIntBetween(1,6);
    switch (randomCol) {
      case 1:
        return 'R';
        break;
      case 2:
        return 'Y';
        break;
      case 3:
        return 'G';
        break;
      case 4:
        return 'B';
        break;
      case 5:
        return 'M';
        break;
      case 6:
        return 'C';
        break;
    }
    return 'R';
}
