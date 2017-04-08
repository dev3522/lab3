Lab3
Write a program with 3 processes: A, B and C. A constantly reads numbers from user and sends them to B using pipe. 
B squares them and passes them to C via shared memory. Process C consists of two threads: C-1 and C-2. C-1 receives 
squared numbers from B and C-2 constantly prints something to terminal, e.g. "I am alive!", but whenever C-1 receives 
a number, C-2 should print "value = XXXX", where XXXX - the received number. When C receives "100", 
it should send SIGUSR1 to B, which should gracefully shutdown all the three processes.