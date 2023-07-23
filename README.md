Learnings from [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/).

## Progress

### Intro

|| Chapter | Read | Homework |
|-|-|-|-|
|1| A Dialogue on the Book|`23/07/02`| N/A|
|2|Introduction on Operating Systems | `23/07/02`|N/A |



### I. Virtualization

**CPU Virtualization**

|| Chapter | Read | Homework |
|-|-|-|-|
|3| A Dialogue on Virtualization| `23/07/03`| N/A|
|4| The Abstraction: The Process | `23/07/03` |`23/07/03`|
|5| Interlude: Process API | `23/07/04`| `23/07/09` (Q8 skipped)|
|6|Mechanism: Limited Direct Execution |`23/07/04` | (Skipped)|
|7|Scheduling: Introduction |`23/07/05` | `23/07/10`|
|8| Scheduling: The Multi-Level Feedback Queue|`23/07/05` | `23/07/10`|
|9|Scheduling: Proportional Share |`23/07/05` |`23/07/10` |
|10|Multiprocessor Scheduling | (Skipped) | |
|11|Summary Dialogue on CPU Virtualization |`23/07/05` |N/A |

**Memory Virtualization**

|| Chapter | Read | Homework |
|-|-|-|-|
|12|A Dialogue on Memory Virtualization |`23/07/05` |N/A|
|13|The Abstraction: Address Spaces |`23/07/05` | |
|14|Interlude: Memory API |`23/07/05` | |
|15|Mechanism: address translation |`23/07/06` | |
|16| Segmentation|`23/07/07` | |
|17|Free-Space Management | `23/07/07`| |
|18| Paging: Introduction|`23/07/08` | |
|19|Paging: Faster Translations (TLB)| `23/07/09`| |
|20|Paging: Smaller Tables | `23/07/11`| |
|21|Beyond Physical Memory: Mechanisms |`23/07/12` | |
|22|Beyond Physical Memory: Policies |`23/07/12` | |
|23|Complex Virtual Memory Systems |`23/07/13` | |
|24| Summary Dialog On Memory Virtualization |`23/07/13` |N/A |

### II. Concurrency

|| Chapter | Read | Homework |
|-|-|-|-|
|25| A Dialogue On Concurrency | `23/07/13` | N/A |
|26|  |  |  |
|27|  |  |  |
|28|  |  |  |
|29|  |  |  |
|30|  |  |  |
|31|  |  |  |
|32|  |  |  |
|33|  |  |  |
|34|  |  |  |

### Ⅲ. Persistence Security

|| Chapter | Read | Homework |
|-|-|-|-|
|35| A Dialogue On Persistence | `23/07/15` | N/A |
|36| I/O Devices | `23/07/15` | N/A |
|37| Hard Disk Drives | `23/07/15` |  |
|38| Redundant Array Of Inexpensive Disks (RAID) | `23/07/16` |  |
|39| Interlude: Files and Directories | `23/07/17` |  |
|40| File System Implementation | `23/07/17` |  |
|41| Locality and The Fast File System | `23/07/22` |  |
|42| Crash Consistency: FSCK and Journaling | `23/07/22` |  |
|43| Log-Structured File Systems | `23/07/23` |  |
|44| Flash-based SSDs |  |  |
|45| Data Integrity and Protection |  |  |
|46| Summary Dialogue on Persistence |  | N/A |

### Ⅳ. Distribution

|| Chapter | Read | Homework |
|-|-|-|-|
|47| A Dialogue On Distribution |  | N/A |
|48|  |  |  |
|49|  |  |  |
|50|  |  |  |
|51|  |  |  |

## Links which helped me

- [Why is the CPU not needed to service I/O requests?](https://stackoverflow.com/questions/13596997/why-is-the-cpu-not-needed-to-service-i-o-requests)

## Topics worth investigating/discussing

> a recent paper by systems researchers from Microsoft, Boston University, and ETH in Switzerland details some problems with fork(), and advocates for other, simpler process creation APIs such as spawn() [B+19].   
> P45. §5. Interlude: Process API


> In a child process, it cannot stdout anymore. However in the parent process, even if STDOUT_FILENO is closed in the child process, it can stdout.
> P.48 §5. Interlude: Process API - Homework

Why is this?

> Note that there are two types of register saves/restores that happen during this protocol. The first is when the timer interrupt occurs; in this case, the user registers of the running process are implicitly saved by the hardware, using the kernel stack of that process. The second is when the OS decides to switch from A to B; in this case, the kernel registers are explicitly saved by the software (i.e., the OS), but this time into memory in the process structure of the process. The latter action moves the system from running as if it just trapped into the kernel from A to as if it just trapped into the kernel from B.   
> P.59 §6. Mechanism: limited direct execution

> CFS (Completely Fair Scheduler) addresses this by keeping processes in a red-black tree.   
> P.98 §9. Scheduling: proportional share

> You might have noticed that we haven’t been talking about system calls when discussing `malloc()` and `free()`. The reason for this is simple: they are not system calls, but rather library calls. Thus the malloc library manages space within your virtual address space, but itself is built on top of some system calls which call into the OS to ask for more memory or release some back to the system. One such system call is called `brk`, which is used to change the location of the program’s break: the location of the end of the heap. It takes one argument (the address of the new break), and thus either increases or decreases the size of the heap based on whether the new break is larger or smaller than the current break. An additional call `sbrk` is passed an increment but otherwise serves a similar purpose.   
> Note that you should never directly call either `brk` or `sbrk`. They are used by the memory-allocation library; if you try to use them, you will likely make something go (horribly) wrong. Stick to `malloc()` and `free()` instead.   
> P.138 §14. Interlude: Memory API

Actually, program has to ask OS in order to get more memory used for heap.
That being considered, I think that memory space virtualization is achieved by OS + `malloc()`.

Q. How about stack?

> Finally, you can also obtain memory from the operating system via the mmap() call. By passing in the correct arguments, mmap() can create an anonymous memory region within your program — a region which is not associated with any particular file but rather with swap space, something we’ll discuss in detail later on in virtual memory. This memory can then also be treated like a heap and managed as such. Read the manual page of mmap() for more details.   
> P.138 §14. Interlude: Memory API

> From the program's perspective, its address space starts at address 0 and grows to a maximum of 16KB.    
> P.144 §15. Mechanism: Address Translation

In reality, what is the maximum address of the address space?

> 32-bit address space (4GB in size)    
> P.155 §16. Segmentation

For a machine with 32-bit registers, maximum virtual memory address it can represent is:   
`2**32 byte` offset = `2**10 * 2**10 * 2**10 * 4 byte` offset = `4GB` offset.   

For a machine with 64-but registers, it is:   
`2**64 byte` offset = `2**10 * 2**10 * 2**10 * 2**10 * 2**10 * 2**10 * 16 byte` offset = `16EB` offset.   


> The hardware uses segment registers during translation.   
> One common approach, sometimes referred to as an explicit approach ... This technique is used in th VAX/VMS system.   
> P.158 §16. Segmentation

In this approach,
- Segment register
  - base register of Code segment
  - bounds register of Code segment
  - base register of Heap segment
  - bounds register of Heap segment
  - base register of Stack segment
  - bounds register of Stack segment

And the virtual address of our interest always has first 2 bits which specifies the segment type (code/heap/stack).
In this way, CPU calculates the physical address with base/bounds registers of that type.

In the modern CPUs, what is mentioned as `base register`s in this book corresponds to these.

- Segment resister
  - `CodeSegment`
  - `DataSegment`
  - `ExtraSegment`
  - `StackSegment`

I could not figure out what corresponds to bounds register.

> There are other ways for the hardware to determine which segment a particular address is in. In the implicit approach, the hardware deter- mines the segment by noticing how the address was formed. If, for example, the address was generated from the program counter (i.e., it was an instruction fetch), then the address is within the code segment; if the address is based off of the stack or base pointer, it must be in the stack segment; any other address must be in the heap.    
> P.159 §16. Segmentation

> We’ll also assume that once memory is handed out to a client, it cannot be relocated to another location in memory. For example, if a program calls malloc() and is given a pointer to some space within the heap, that memory region is essentially “owned” by the program (and cannot be moved by the library) until the program returns it via a corresponding call to free(). Thus, no compaction of free space is possible, which would be useful to combat fragmentation.   
> P.168 §17. Free-Space Management    
> 👉 Q. In reality, is it possible that a compaction is done inside the heap to remove internal fragmentation?    
> That is, can the virtual memory address represented by x change while the program is running?	  
> `int *x = malloc(sizeof(int))`


> OS and CPU must know each other much, even though CPU companies does not develop OS by themselves.   
> How do CPU manufacturing companies (like Intel) know/decide CPU features to be included in their CPUs?

> In multi-level page tables,    
> `PTEAddr = (PDE.PFN << SHIFT) + (PTIndex * sizeof(PTE))`    
> P.223 §20. Paging Smaller Tables    
> 👉 Q. What is `SHIFT`? How does it convert (PDE.PFN, PTIndex) into physical address?

> In inverted pag tables, a linear scan would be expensive, and thus a hash table is often built over the base structure to speed up lookups.    
> P.226 §20. Paging Smaller Tables    
> 👉 Q. Why is hash table is used in inverted page tables, but not in other page tables such as single/multiple-level page tables?

> What are the benefits of keeping memory usage between low water mark and high water mark with swap daemon?    
> P.237 §20. Paging Smaller Tables

> Prove that replacing the page that will be accessed *furthest in the future* is the optimal policy.    
> P.244 §21. Beyond Physical Memory: Mechanisms


> Why don't we use `doubly linked list + hash map` instead of approximating LRU?    
> P.254 §21. Beyond Physical Memory: Mechanisms


> What is `pageable pge tables`?    
> P.254 §21. Beyond Physical Memory: Mechanisms


> List and summarize what you learned in memory virtualization chapter.    
> P.254 §21. Beyond Physical Memory: Mechanisms


> In `ide_intr()` method,
> wakeup(b); // wake waiting process    
> ```
> if ((ide_queue = b->qnext) != 0) // start next request
>    ide_start_request(ide_queue); // (if one exists)
> release(&ide_lock);
> ```
> P. 429 §36. I/O Devices    
> Why this device driver is responsible for starting a subsequent disk I/O job? I think that `ide_start_request` in `ide_intr()` will be triggered after the process of `b` is finished, and it is too late. I mean, another process would call `ide_start_request` in `ide_rw`, and I think this probably happens earlier.


> Even if sequential is not possible, at least think about transferring data in large chunks: the bigger, the better.    
> P. 429 §37. Hard Disk Drives    
> 👉 Q. How can I achieve this? Which system call is used for this?



> P. 508 §40. File Systems Implementation    
> Q. Which part of file system is implemented in kernel, and which part in a disk driver?



> The authors describe an approach which tries to segregate hot and cold segments. A hot segment is one in which the contents are being frequently over-written; thus, for such a segment, the best policy is to wait a long time before cleaning it, as more and more blocks are getting over-written (in new segments) and thus being freed for use. A cold segment, in contrast, may have a few dead blocks but the rest of its contents are relatively stable. Thus, the authors conclude that one should clean cold segments sooner and hot segments later, and develop a heuristic that does exactly that.    
> P. 557 §41. Log-Structured File Systems    
> 👉 Q. Why is this?
