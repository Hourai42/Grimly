# Grimly

Next time, watch out when you malloc an int array. I can't believe the program worked with that error for most cases.

1. Your Grimly is fairly slow because for one, your queue implementation is horrid. Instead of having a pointer to the tail and front ends of the queue, you only have a pointer to the tail(a regular linked list). Every time you wished to dequeue, you would simply iterate to the end of the list and pop whatever that was the end off. This is a very bad implementation and you should improve on it if you have time. Choosing the correct data structure as well as having the ideal implementation will greatly increase speed. 

[x] Fixed linked list implementation. Possibly using global variables instead of storing the head in a struct might speed up the implementation quite a bit? You won't need to set the head every time you push a new node... But whatever, global variables aren't allowed.

a. ./grimly tests/ted.map  1.55s user 0.54s system 97% cpu 2.138 total with incorrect linked list implementation

b. ./grimly tests/ted.map  0.36s user 0.60s system 97% cpu 0.981 total with correct linked list implementation

2. Instead of multiplying by *-1, you can simply set whatever you're putting into the queue to 0. Multiplying by -1 is a read, write, and modify operation while setting something to zero is just a write operation. 

[x] Checked speed on *-1 vs setting to 0.  
a. ./grimly tests/ted.map  1.67s user 0.56s system 90% cpu 2.466 total (1000 by 1000 labyrinth)

b. ./grimly tests/ted.map  1.66s user 0.55s system 92% cpu 2.383 total

Completely unnoticeable difference from changing *-1 to setting to 0 instead.


3. Rules for closing files? Well, just to be safe, you might as well close after you're done. 

[x] Closed files.

4. Instead of using a 2D array, a 1D array is enough. If your key holds the number of row and columns, you can use the remainder and modulus operations to access whatever piece of information on the board you wish. 

[o] I won't be implementing this as it's an extremely minor memory improvement, but possibly a performance detriment. 

5. Freeing everything you malloc will prevent memory leaks and free up valuable memory space. However, I can't risk freeing due to the way my program is structured. Everything is linked, so I have a high possibility of double freeing and segfaulting.
Possibly implementing a flag system or making sure it exists before mallocing. Or simply setting it to NULL everytime, so if you don't MALLOC it's just null. 
[ ] 

6. The rule of speed is to minimize function calls, iterations, and operations. 

7. LLDB USAGE: Add -g to compile flags, lldb -- (program name) (input), b main, run, gui, n for newline, s for side, h for help. 

8. leaks ./(program name) (input) to check for memory leaks
