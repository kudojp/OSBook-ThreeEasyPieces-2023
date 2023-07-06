Learnings from [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/).

## Progress

### Intro

|| Chapter | Read | Homework |
|-|-|-|-|
|1| A Dialogue on the Book|`23/07/02`| N/A|
|2|Introduction on Operating Systems | `23/07/02`|N/A |



### I. Virtualization

CPU vitrualization

|| Chapter | Read | Homework |
|-|-|-|-|
|3| A Dialogue on Virtualization| `23/07/03`| N/A|
|4| The Abstraction: The Process | `23/07/03` |`23/07/03` |
|5| Interlude: Process API | `23/07/04`| |
|6| |`23/07/04` | |
|7| |`23/07/05` | |
|8| |`23/07/05` | |
|9|Scheduling: Proportional Share |`23/07/05` | |
|10|Multiprocessor Scheduling | | |

Memory virtualization

|| Chapter | Read | Homework |
|-|-|-|-|
|11| |`23/07/05` | |
|12| |`23/07/05` | |
|13| |`23/07/05` | |
|14| |`23/07/05` | |
|15|Mechanism: address translation |`23/07/06` | |
|16| | | |
|17| | | |
|18| | | |
|19| | | |
|20| | | |
|21| | | |
|22| | | |
|23| | | |
|24| | | |




### II. Concurrency

### Ⅲ. Persistence Security


## Links which helped me

- [Why is the CPU not needed to service I/O requests?](https://stackoverflow.com/questions/13596997/why-is-the-cpu-not-needed-to-service-i-o-requests)

## Topics worth investigating/discussing

> a recent paper by systems researchers from Microsoft, Boston University, and ETH in Switzerland details some problems with fork(), and advocates for other, simpler process creation APIs such as spawn() [B+19].
> P45. §5. Interlude: Process API


> Note that there are two types of register saves/restores that happen during this protocol. The first is when the timer interrupt occurs; in this case, the user registers of the running process are implicitly saved by the hardware, using the kernel stack of that process. The second is when the OS decides to switch from A to B; in this case, the kernel registers are explicitly saved by the software (i.e., the OS), but this time into memory in the process structure of the process. The latter action moves the system from running as if it just trapped into the kernel from A to as if it just trapped into the kernel from B.
> P.59 §6. Mechanism: limited direct execution

> CFS (Completely Fair Scheduler) addresses this by keeping processes in a red-black tree.
> P.98 §9. Scheduling: proportional share
