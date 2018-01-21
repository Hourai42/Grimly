# Grimly

Next time, watch out when you malloc an int array. I can't believe the program worked with that error for most cases.

1. Your Grimly is fairly slow because for one, your queue implementation is horrid. Instead of having a pointer to the tail and front ends of the queue, you only have a pointer to the tail(a regular linked list). Every time you wished to dequeue, you would simply iterate to the end of the list and pop whatever that was the end off. This is a very bad implementation and you should improve on it if you have time. Choosing the correct data structure as well as having the ideal implementation will greatly increase speed. 

2. Instead of multiplying by *-1, you can simply set whatever you're putting into the queue to 0. Multiplying by -1 is a read, write, and modify operation while setting something to zero is just a write operation.  

3. The rule of speed is to minimize function calls, iterations, and operations. 

4. Rules for closing files? Well, just to be safe, you might as well close after you're done. 
