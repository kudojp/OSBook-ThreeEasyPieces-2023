# Homework

`scheduler.py` I used is here: https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/cpu-sched

> 1. Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.

## SJF

|job id | arrival time| start time | end time| response time | turnaround time| wait time|
|-|-|-|-|-|-|-|
| job0|0 |0 |200 | 0| 200|0|
| job1|0 |200 |400 | 200| 400|200|
| job2|0 |400 |600 | 400| 600|400|

-> average
- response = 200
- turnaround = 400
- wait = 200


## FIFO

|job id | arrival time| start time | end time| response time | turnaround time| wait time|
|-|-|-|-|-|-|-|
| job0|0 |0 |200 | 0| 200|0|
| job1|0 |200 |400 | 200| 400|200|
| job2|0 |400 |600 | 400| 600|400|

-> average
- response = 200
- turnaround = 400
- wait = 200

> 2. Now do the same but with jobs of different lengths: 100, 200, and 300.

## SJF

|job id | arrival time| start time | end time| response time | turnaround time| wait time|
|-|-|-|-|-|-|-|
|job0(100)| 0| 0| 100| 0| 100|0|
|job1(200)| 0| 100| 300| 100| 300|100|
|job2(300)| 0| 300|600 |300 |600 |300|

-> average
- response = 133.3
- turnaround = 333.3
- wait = 133.3

## FIFO

|job id | arrival time| start time | end time| response time | turnaround time| wait time|
|-|-|-|-|-|-|-|
|job0(100)| 0| 0| 100| 0| 100|0|
|job1(200)| 0| 100| 300| 100| 300|100|
|job2(300)| 0| 300|600 |300 |600 |300|

-> average
- response = 133.3
- turnaround = 333.3
- wait = 133.3

> 3. Now do the same, but also with the RR scheduler and a time-slice of 1.

- t=298 -> A is finished.
- t=300 -> remaining is (0,100,200)
- t=499 -> B is finished
- t=500 -> remaining is (0,0,100)
- t=600 -> C is finished

avg response time is (0+1+2)/3 = 1.00     
avg turnaround time is (298+499+600)/3 = 465.67    
avg wait time is (298+499+600-600)/3 = 897/3 = 265.67    

> 4. For what types of workloads does SJF deliver the same turnaround times as FIFO?

Workloads whose length of each job is the same.


> 5. For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

Workloads whose lengths of all jobs in SJF are the same as the time-slice of RR.

> 6. What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?

- 1,2,3 -> `Average -- Response: 1.33  Turnaround 3.33  Wait 1.33`
- 10,20,30 -> `Average -- Response: 13.33  Turnaround 33.33  Wait 13.33`
- 100,200,300 -> ` Average -- Response: 133.33  Turnaround 333.33  Wait 133.33`

As the job lengths increase, the response time of SJF increases.

> 7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?

Average response time increases as RR's quantum lengths increase.    
In the worst case, where quantum length is longer than any of the job lengths, the average response time is:

```
(Sum of all job lengths) / N
```
