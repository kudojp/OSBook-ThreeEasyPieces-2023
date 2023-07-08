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
|16| Segmentation|`23/07/07` | |
|17|Free-Space Management | `23/07/07`| |
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

> You might have noticed that we haven’t been talking about system calls when discussing malloc() and free(). The reason for this is simple: they are not system calls, but rather library calls. Thus the malloc library manages space within your virtual address space, but itself is built on top of some system calls which call into the OS to ask for more memory or release some back to the system. One such system call is called brk, which is used to change the location of the program’s break: the location of the end of the heap. It takes one argument (the address of the new break), and thus either increases or decreases the size of the heap based on whether the new break is larger or smaller than the current break. An additional call sbrk is passed an increment but otherwise serves a similar purpose.   
> Note that you should never directly call either brk or sbrk. They are used by the memory-allocation library; if you try to use them, you will likely make something go (horribly) wrong. Stick to malloc() and free() instead.   
> P.138 §14. Interlude: Memory API

How about stack?

> Finally, you can also obtain memory from the operating system via the mmap() call. By passing in the correct arguments, mmap() can create an anonymous memory region within your program — a region which is not associated with any particular file but rather with swap space, something we’ll discuss in detail later on in virtual memory. This memory can then also be treated like a heap and managed as such. Read the manual page of mmap() for more details.   
> P.138 §14. Interlude: Memory API

> 32-bit address space (4GB in size)   
> P.155 §16. Segmentation

For a machine with 32-bit registers, maximum virtual memory address it can represent is:   
`2**32 byte` offset = `2**10 * 2**10 * 2**10 * 4 byte` offset = `4GB` offset.   

For a machine with 64-but registers, it is:   
`2**64 byte` offset = `2**10 * 2**10 * 2**10 * 2**10 * 2**10 * 2**10 * 16 byte` offset = `16EB` offset.   


> There are other ways for the hardware to determine which segment a particular address is in. In the implicit approach, the hardware deter- mines the segment by noticing how the address was formed. If, for example, the address was generated from the program counter (i.e., it was an instruction fetch), then the address is within the code segment; if the address is based off of the stack or base pointer, it must be in the stack segment; any other address must be in the heap.
> P.159 §16. Segmentation

> We’ll also assume that once memory is handed out to a client, it cannot be relocated to another location in memory. For example, if a program calls malloc() and is given a pointer to some space within the heap, that memory region is essentially “owned” by the program (and cannot be moved by the library) until the program returns it via a corresponding call to free(). Thus, no compaction of free space is possible, which would be useful to combat fragmentation.   
> P.168 §17. Free-Space Management
> 
> 👉 Q. In reality, is it possible that a compaction is done inside the heap to remove internal fragmentation?
> That is, can the virtual memory address represented by x change while the program is running?	  
> `int *x = malloc(sizeof(int))`
