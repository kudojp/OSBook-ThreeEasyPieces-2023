Ref. https://github.com/remzi-arpacidusseau/ostep-homework/tree/master/cpu-sched-lottery

> 1. Compute the solutions for simulations with 3 jobs and random seeds of 1, 2, and 3.

Done as below.

- python ./lottery.py -j 3 -s 1 -c
- python ./lottery.py -j 3 -s 2 -c
- python ./lottery.py -j 3 -s 3 -c

> 2. Now run with two specific jobs: each of length 10, but one (job 0) with just 1 ticket and the other (job 1) with 100 (e.g., -l 10:1,10:100). What happens when the number of tickets is so imbalanced? Will job 0 ever run before job 1 completes? How often? In general, what does such a ticket imbalance do to the behavior of lottery scheduling?

The probability that job1 finishes earlier than job2 is: `(100/101) ** 100 = 36.9%`.

> 3. When running with two jobs of length 100 and equal ticket allocations of 100 (-l 100:100,100:100), how unfair is the scheduler? Run with some different random seeds to determine the (probabilistic) answer; let unfairness be determined by how much earlier one job finishes than the other.

|seed |job 0 done at |job 1 done at| unfairness |
|-|-|-|-|
|0 |192 |200 |fair to job 1 (96%) |
|1 |200 |196 |fair to job 0 (98%) |
|2 |200 |190 |fair to job 0 (95%) |
|3 |196 |200 |fair to job 1 (98%) |
|4 |200 |199 |fair to job 0 (99.5%) |
|5 |200 |181 |fair to job 0 (90.5%) |
|6 |200 |193 |fair to job 0 (96.5%) |
|7 |200 |185 |fair to job 0 (92.5%) |
|8 |200 |191 |fair to job 0 (95.5%) |
|9 |200 |192 |fair to job 0 (96%) |


> 4. How does your answer to the previous question change as the quantum size (-q) gets larger?

As the quantum size increases, the scheduler becomes more unfair.

> 5. Can you make a version of the graph that is found in the chapter? What else would be worth exploring? How would the graph look with a stride scheduler?

Done in `homework-9-5.ipynb`.

