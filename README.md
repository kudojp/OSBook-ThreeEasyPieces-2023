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
|3| A Dialogue on CPU Virtualization| `23/07/03`| N/A|
|4| The Abstraction: The Process | `23/07/03` |`23/07/03`|
|5| Interlude: Process API | `23/07/04`| `23/07/09` (Q8 skipped)|
|6|Mechanism: Limited Direct Execution |`23/07/04` | (Skipped)|
|7|Scheduling: Introduction |`23/07/05` | `23/07/10`|
|8| Scheduling: The Multi-Level Feedback Queue|`23/07/05` | `23/07/10`|
|9|Scheduling: Proportional Share |`23/07/05` |`23/07/10` |
|10|Multiprocessor Scheduling (Advanced) | `23/08/05` | |
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
|24| Summary Dialog on Memory Virtualization |`23/07/13` |N/A |

### II. Concurrency

|| Chapter | Read | Homework |
|-|-|-|-|
|25| A Dialogue on Concurrency | `23/07/13` | N/A |
|26| Concurrency: An Introduction | `23/07/27` |  |
|27| Interlude: Thread API | `23/07/28` |  |
|28| Lock | `23/07/29` |  |
|29| Lock-Based Concurrent Data Structure | `23/07/30` |  |
|30| Condition Variables | `23/07/30` |  |
|31| Semaphores | `23/07/30` |  |
|32| Common Concurrency Problems | `23/07/30` |  |
|33| Event-based Concurrency (Advanced) | `23/08/05` |  |
|34| Summary Dialog On Concurrency | `23/07/30` |  |

### Ⅲ. Persistence Security

**Local File System**

|| Chapter | Read | Homework |
|-|-|-|-|
|35| A Dialogue on Persistence | `23/07/15` | N/A |
|36| I/O Devices | `23/07/15` | N/A |
|37| Hard Disk Drives | `23/07/15` |  |
|38| Redundant Array Of Inexpensive Disks (RAID) | `23/07/16` |  |
|39| Interlude: Files and Directories | `23/07/17` |  |
|40| File System Implementation | `23/07/17` |  |
|41| Locality and The Fast File System | `23/07/22` |  |
|42| Crash Consistency: FSCK and Journaling | `23/07/22` |  |
|43| Log-Structured File Systems | `23/07/23` |  |
|44| Flash-based SSDs | `23/07/23` |  |
|45| Data Integrity and Protection | `23/07/23` |  |
|46| Summary Dialogue on Persistence | `23/07/23` | N/A |

**Distributed File System**

|| Chapter | Read | Homework |
|-|-|-|-|
|47| A Dialogue on Distribution  | `23/08/04` | N/A |
|48| Distributed Systems | `23/08/04` |  |
|49| Network File System (NFS) | `23/08/05` |  |
|50| Andrew File System (AFS) | `23/08/05` |  |
|51| Summary Dialogue on Distribution | `23/08/05` |  |

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

> - int pthread_mutex_trylock(pthread_mutex_t *mutex);
> - int pthread_mutex_timedlock(pthread_mutex_t *mutex, struct timespec *abs_timeout);
>  Both of these versions should generally be avoided; however, there are a few cases where avoiding getting stuck (perhaps indefinitely) in a lock acquisition routine can be useful, as we’ll see in future chapters (e.g., when we study deadlock).    
> P.309 §27. Interlude: Thread API    
> Why these versions should generally be avoided?    
> What are the pain points?    

> To share data between threads, the values must be in the heap or otherwise some locale that is globally accessible.    
> P.312 §27. Interlude: Thread API    
> 👉 Q. What is locale that is globally accessible?

For example, variables which are defined locally in the file and not in any scope.    
(e.g. variables neither in main function nor any other functions.)

> lock mechanism of Solaris
> Using Queues: Sleeping instead of spinning    
> P.329 §28. Lock

![Ruby Async](https://github.com/kudojp/Read-ThreeEasyPieces-OSBook2023/assets/44487754/575667f5-9482-41aa-8af9-db9e3015a7ee)

> In approximate counter implementation,    
> `int cpu = threadID % NUMCPUS`
> P. 341 §29. Lock-Based Concurrent Data Structure

Is this really a correct way to get cpu core id which executes the current thread?
Is there any other way?


> In approximate counter implementation,    
> `int cpu = threadID % NUMCPUS`
> P. 348 §29. Lock-Based Concurrent Data Structure


> other thread-safe structures like B-trees -> a database class is your best bet.    
> P. 348 §29. Lock-Based Concurrent Data Structure    
> 👉 Q. In PostgreSQL, one sub-process is created for one connection.    
> How does it guarantee the "process-safeness" rather than thread-safeness?



> a single lock when first transitioning to multiprocessors,    
> but when multi-CPU systems became the norm, became a performance bottleneck     
> P. 348 §29. Lock-Based Concurrent Data Structure
> 👉  Q. What are the differences between multiprocessors and multi-CPU systems?

> Binary Semaphores
> P.369 §30. Semaphores
> 👉 Q. I think that the value of a binary lock (built with semaphore) can be 2 or more.    
> In this way, if this is locked is used as `unlock (>val=2) -> lock (>val=1) -> lock (>val=0)`, two threads seem to be able to acquire locks.    
> Is this correct?
> 👉 Q. I think this semaphore can cause a deadlock when used as `wait() -> post()` order.    
> In `wait()`, it takes mutex_lock and then does cond_wait. Then in `post()`, it waits to acquire mutex_lock, which is a deadlock.

> Figure 31.16: Implementing Semaphores With Locks and CVs
> P.381 §30. Semaphores



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


> Another reliability concern is program disturbance. To minimize such disturbance, FTLs will commonly program pages within an erased block in order, from low page to high page. This sequential-programming approach minimizes disturbance and is widely utilized.    
> P. 569 §42. Flash-Based SSDs    
> 👉 Q. Isn't it possible that writing to a page makes bits in the neighboring lower page flipped?


> Some additional findings about LSEs are:
> • Costly drives with more than one LSE are as likely to develop additional errors as cheaper drives.
> P. 589 §43. Data Integrity and Protection    
> 👉 Q. What do these mean?


> Some findings about corruption:
> • Chance of corruption varies greatly across different drive models within the same drive class.
> P. 589 §43. Data Integrity and Protection    
> 👉 Q. What do these mean?


> The first failure mode of interest is called a misdirected write. This arises in disk and RAID controllers which write the data to disk correctly, except in the wrong location.
> P. 594 §43. Data Integrity and Protection    
> 👉 Q. What is the internal mechanism of this?


> The time overheads induced by checksumming can be quite noticeable. Minimally, the CPU must compute the checksum over each block, both when the data is stored and when it is accessed.    
> One approach is to combine data copying and checksumming into one streamlined activity; because the copy is needed anyhow (e.g., to copy the data from the kernel page cache into a user buffer), combined copying/checksumming can be quite effective.    
> P. 596 §43. Data Integrity and Protection    
> 👉 Q. Why is this so efficient? What is the internal mechanism of this?

> `myaddr.sin_port = htons(port);` (in `UDP_Open()`)    
> `addr->sin_port = htons(port); // network byte order` (in `UDP_FillSockAddr()`)    
> P.608 §43. Distributed Systems    
> 👉 Q. Why are ports converted from host order to machine order, but families are not?

> NFSv2 implementations solve these cache consistency problems in two ways. First, to address update visibility, clients implement what is sometimes called flush-on-close (a.k.a., close-to-open) consistency semantics;    
> specifically, when a file is written to and subsequently closed by a client application, the client flushes all updates (i.e, dirty pages in the cache) to the server. With flush-on-close consistency, NFS ensures that a subsequent open from another node will see the latest file version.    
> P.632 §43. Sun's network file system    
> 👉 Q. How NFS sustains update visibility, not in the case when a file is updated but NOT updated by another client?

> The designers of AFS, given their experience in measuring how file systems were used, made certain workload assumptions;    
> in particular, they assumed that most files were not frequently shared, and accessed sequentially in their entirety. Given those assumptions, the AFS design makes perfect sense.    
> P.649 §43. The Andrew network file system    
> 👉 Q. Explain this in detail.
