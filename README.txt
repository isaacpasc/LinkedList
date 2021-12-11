*To run this program use Makefile
make: creates executable named "exe"
make clean: removes .o and executable

The linkedlist class has the following properties:
- Constructor
• Destructor
• AddToFront(T data) – create a node containing T data and add it to the front of the
list
• AddToEnd(T data) – create a node containing T data and add it to the end of the
list
• AddAtIndex(T data, int index) – create a node containing T data and add it to the
list at index. The new node containing the data will be the #index node in the list. Return boolean for success or failure (optional: you could also return an integer with failure codes since this method can fail multiple ways)
• RemoveFromFront() – Delete first item and return its contents
• RemoveFromEnd() – Delete last item and return its contents
• RemoveTheFirst(T data) – find first instance of T data and remove it
• RemoveAllOf(T data) – find each instance of T data and remove it
• ElementExists(T data) – Returns a T/F if element exists in list
• Find(T data) – Look for data in the list, return a pointer to its node
• IndexOf(T data) – returns an index of the item in the list (zero-based)
• RetrieveFront – returns the data contained in the first node, does not delete it
• RetrieveEnd – returns the data contained in the last node, does not delete it
• Retrieve(int index) – returns the data contained in node # index, does not delete
it, returns null if index is out of bounds or data does not exist
• PrintList – Loop through each node and print the contents of the Node
• Empty – Empty out the list, delete everything
• Length – How many elements are in the list

T data is templated

To demonstrate the linked list abilities I have also created a small, silly demonstration using zombies.
At the start of the program the user is asked to input the number of rounds to play.
Each round the list of zombies can perform one of the following actions:

Engine!:
o This zombie becomes the first Zombie in the conga line
Caboose!:
o This zombie becomes the last zombie in the conga line
Jump in the Line!:
o This zombie joins the conga line at position X where X <= length of
           the linked list
Everyone Out!:
o Remove all matching zombies from the linked list
You’re done!:
o Remove the first matching zombie from the linked list
Brains!:
o Generate two more matching Zombies and add one to the front, one to the end and one to the middle.
Rainbow Brains!:
o Add this zombie to the front, then add one of each zombie color to the
           end of the conga line.

And finally an example of output after 5 rounds:

Round: 0
The Zombie Party keeps on groaning!
Size: 16 :: [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] [M] [R] B zombie jumps in the front of the line! (ENGINE)
The conga line is now:
Size: 17 :: [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] [M] *******************

Round: 1
The Zombie Party keeps on groaning!
Size: 17 :: [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] [M] M zombie jumps in the front of the line! (ENGINE)
The conga line is now:
Size: 18 :: [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] *******************

Round: 2
The Zombie Party keeps on groaning!
Size: 18 :: [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] C zombie pulls up the rear! (CABOOSE)
The conga line is now:
Size: 19 :: [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] *******************

Round: 3
The Zombie Party keeps on groaning!
Size: 19 :: [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [G] Y zombie brought a whole party itself! (RAINBOW BRAINS!)
The conga line is now:
Size: 26 :: [Y] [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [C]
*******************

Round: 4
The Zombie Party keeps on groaning!
Size: 26 :: [Y] [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [M] [C] [C]
Y zombie brings its friends to the party (BRAINS!)
The conga line is now:
Size: 29 :: [Y] [Y] [M] [B] [R] [M] [G] [R] [R] [G] [G] [R] [M] [B] [Y] [Y] [Y] [M] [C] [Y]
