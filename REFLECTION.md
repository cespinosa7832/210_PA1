1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

  My first thought is that the lists are simply different. The method I used to concat two linked lists was I essentially just set the last node in the first list's next pointer to the head of the second list then removed the second list. For the Array implementation, I iterated through the second list just adding each element to the first. These methods are depended on the implementation itself. So my implicit response would be that the lists are different. Furthermore, the linked list stores Node opbjects, while the ArrayList jsut stores the data in an array. 

2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

  The three pointers in use are "prev", "current" and "nextNode". How the reverse function works is basically a while loop that starts current at head and runs until current is null. We set the nextNode equal to current's next pointer, and then set currents next pointer equal to "prev." Then we set prev to the current node and move current down the list. Essentially the way I think about it is if the nodes are boxes with pointers going in one direction, this function just rotates each box so that the pointers are facing the other direction. I did not try losing track of any pointers when I implemented this but I can imagine that if you lose a pointer you could end up with nodes pointing to locations they should not be pointing to.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

  The valid range should be anywhere within the list, 0 - size, anywhere from the first position in the list to the end of the list. For either one if the position is 0 I call the addFront() function, since that's all it needs to do. Otherwise I check to make sure it is within the appropriate bounds, for ArrayList, I do if (position > size_) it prints "Out of Bounds". The Linked list is a bit different as I walk the current pointer over to the location then run if (current = nullptr) print "Out of Bounds". Also in either case position < 0 will also print out of bounds.

5. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?
   
   With LinkedList::concat, I had to walk to the end of the first list in order to set the last Node's next pointer equal to the head of the other list that's being added to the first. addFront and deleteFront only deal with the first node so of course we needn't walk to the end of the list. A tail pointer would change this from O(n) to O(1), making it quicker.

7. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

   With addAnywhere, I start with checking whether or not the list is at capacity, followed by a bounds check. After that, I run a for loop with i starting at size_ and work my way backwards til i = position, shifting every element over with data_[i] = data[i-1], which moves items to one index greater than their current location. Finishing with data[position] = value, before incrementing the size. If the items get shifted the wrong direction then the array starts writing over itself moving the data to the wrong indexes which with overwrite the data that is still needed in the array.
   
9. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

    Line 44, and I suppose in the game of Uno if the reverse function is never called when a reverse card was played, then the turn order would continue the same as before. (I'm sorry if I don't really understand the question)
