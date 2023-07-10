# Homework

Ref. https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/cpu-sched-mlfq

```
$ ./mlfq.py -h
Usage: mlfq.py [options]

Options:
  -h, --help            show this help message and exit
  -s SEED, --seed=SEED  the random seed
  -n NUMQUEUES, --numQueues=NUMQUEUES
                        number of queues in MLFQ (if not using -Q)
  -q QUANTUM, --quantum=QUANTUM
                        length of time slice (if not using -Q)
  -a ALLOTMENT, --allotment=ALLOTMENT
                        length of allotment (if not using -A)
  -Q QUANTUMLIST, --quantumList=QUANTUMLIST
                        length of time slice per queue level, specified as
                        x,y,z,... where x is the quantum length for the
                        highest priority queue, y the next highest, and so
                        forth
  -A ALLOTMENTLIST, --allotmentList=ALLOTMENTLIST
                        length of time allotment per queue level, specified as
                        x,y,z,... where x is the # of time slices for the
                        highest priority queue, y the next highest, and so
                        forth
  -j NUMJOBS, --numJobs=NUMJOBS
                        number of jobs in the system
  -m MAXLEN, --maxlen=MAXLEN
                        max run-time of a job (if randomly generating)
  -M MAXIO, --maxio=MAXIO
                        max I/O frequency of a job (if randomly generating)
  -B BOOST, --boost=BOOST
                        how often to boost the priority of all jobs back to
                        high priority
  -i IOTIME, --iotime=IOTIME
                        how long an I/O should last (fixed constant)
  -S, --stay            reset and stay at same priority level when issuing I/O
  -I, --iobump          if specified, jobs that finished I/O move immediately
                        to front of current queue
  -l JLIST, --jlist=JLIST
                        a comma-separated list of jobs to run, in the form
                        x1,y1,z1:x2,y2,z2:... where x is start time, y is run
                        time, and z is how often the job issues an I/O request
  -c                    compute answers for me
```

> 1. Run a few randomly-generated problems with just two jobs and two queues; compute the MLFQ execution trace for each. Make your life easier by limiting the length of each job and turning off I/Os.

Done as below.
$ `./mlfq.py --numJobs=2 --numQueues=2 --jlist=0,5,0:0,7,0 -c --quantumList=3,3`

> 2. How would you run the scheduler to reproduce each of the examples in the chapter?

- Example1: A single long running job (p.79) -> `./mlfq.py --numJobs=1 --numQueues=3 --jlist=0,200,0 -c --quantumList=10,10,10`
- Example2: Along came a short job (p.80) -> `./mlfq.py --numJobs=1 --numQueues=3 --jlist=0,200,0:100,20,0 -c --quantumList=10,10,10`
- Example3: What about I/O? (p.81) -> `./mlfq.py --numJobs=1 --numQueues=3 --jlist=0,200,0:50,15,1 -c --quantumList=10,10,10 --iotime=9 --allotmentList=10,10,10`
- Example with Boost (p.82) -> `./mlfq.py --numJobs=3 --numQueues=3 --jlist=0,120,0:100,50,5:100,50,5 -c --quantumList=10,10,10 --iotime=5 --boost=50`

> 3. How would you configure the scheduler parameters to behave just like a round-robin scheduler?

Set a shorter job quantum and set an allotment which is more than 1 instead.    
(e.g. `./mlfq.py --numJobs=2 --numQueues=2 --jlist=0,100,0:0,100,0 -c --quantumList=10,10,10`)

> 4. Craft a workload with two jobs and scheduler parameters so that one job takes advantage of the older Rules 4a and 4b (turned on with the -S flag) to game the scheduler and obtain 99% of the CPU over a particular time interval.



> 5. Given a system with a quantum length of 10 ms in its highest queue, how often would you have to boost jobs back to the highest priority level (with the -B flag) in order to guarantee that a single longrunning (and potentially-starving) job gets at least 5% of the CPU?

I could achieve 98.3% in this way.    

```
$ ./mlfq.py --numJobs=2 --numQueues=2 --jlist=0,10000,99:0,10000,0 --quantumList=100,100 --iotime=1 --stay -c

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 10200
  Job  1: startTime   0 - response  99 - turnaround 20000

  Avg  1: startTime n/a - response 49.50 - turnaround 15100.00
```

For the first 10200 time units, job1 dominates 10000 time units.

> 6. One question that arises in scheduling is which end of a queue to add a job that just finished I/O; the -I flag changes this behavior for this scheduling simulator. Play around with some workloads and see if you can see the effect of this flag.

With `--iobump` flag, process with I/O can be finished earlier. Example is shown as below.

Without `--iobump` flag, three jobs are treated equally.

```
./mlfq.py --numJobs=3 --numQueues=1 --jlist=0,100,10:0,100,0:0,100,0 --quantumList=10 --iotime=1 -c

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 280
  Job  1: startTime   0 - response  10 - turnaround 290
  Job  2: startTime   0 - response  20 - turnaround 300

  Avg  2: startTime n/a - response 10.00 - turnaround 290.00
```

With `--iobump` flag, the first job, which has I/O, is treated fairly favored. This is because when I/O finishes in the first job, it is inserted to the top of the queue.

```
./mlfq.py --numJobs=3 --numQueues=1 --jlist=0,100,10:0,100,0:0,100,0 --quantumList=10 --iotime=1 --iobump -c

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 109
  Job  1: startTime   0 - response  10 - turnaround 290
  Job  2: startTime   0 - response 110 - turnaround 300

  Avg  2: startTime n/a - response 40.00 - turnaround 233.00
```
