# Questions

## 1. CPU utilization when `-l 5:100,5:100`.

-> CPU busy is 100%.

## 2. `-l 4:100,1:0`

-> takes 11 time units.
- proc0 takes 4 CPU busy.
- then, proc1 takes 1+5+1 I/O


## 3. `-l 1:0,4:100`

-> takes 7 time units.
- (1) proc0: Run I/O
- (4) proc0: I/O blocked, proc1: CPU busy->Done
- (1) proc0: I/O blocked
- (1) proc0: Done I/O

## 4. `-l 1:0,4:100 -S SWITCH_ON_END`

-> takes 11 time units.

- proc0 takes 1+5+1 for I/O
- proc1 takes 4

## 5. `-l 1:0,4:100 -S SWITCH_ON_IO`

Same as #3 (`-l 1:0,4:100`).

## 6. `-l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER`

-> Takes 31 time units.

- (1) p0 is on Run I/O.
- (5) p0 is on I/O blocking. p1 is CPU busy.
- (5) p2 is CPU busy.
- (5) p3 is CPU busy.
- (1) p0 takes done I/O. <- Finally come back to p1. Too late 😢
- (7) p0 does second I/O.
- (7) p0 does third I/O.

The system resources are not efficiently used if CPU busy tasks are prioritized.
p0 can do 2nd and 3rd I/O while p2 and p3 are CPU busy.

## 7. `-l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE`

-> Takes 21 time units.

- (1) p0 is on Run I/O.
- (5) p0 is on I/O blocking. p1 is CPU busy.
- (1) p0 is done I/O.
- (1) p0 is on Run I/O.
- (5) p0 is on I/O blocking. p2 is CPU busy.
- (1) p1 is done I/O.
- (1) p0 is on Run I/O.
- (5) p0 is on I/O blocking. p3 is CPU busy.
- (1) p1 is done I/O.

The system resources are efficiently used.
Running a process that just completed an I/O again immediately is a good idea. This is because that process may does I/O again later, and other CPU tasks can be done meanwhile in other processes.


## 8. Run with randomly generated processes

-> The result seems to be random...

