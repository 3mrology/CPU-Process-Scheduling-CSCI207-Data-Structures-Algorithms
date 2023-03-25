# CPU-Process-Scheduling-CSCI207-Data-Structures-Algorithms
This project consists of five parts, where the first part requires implementing two classes: CPUProcess and ProcessNode. CPUProcess is a class representing a process that the CPU will work on, with private attributes such as process_id, process_name, and time_needed. ProcessNode is a class representing a node of a linked list, where the data part of the node is of type CPUProcess, and it contains a pointer to the next node.

The second part requires implementing a Queue using Linked List. The QueueLL class represents the queue, which is template-based and can accept any type of data. It contains attributes such as FRONT, CAPACITY, and REAR pointers, with a default capacity of 3. The class contains methods such as excecute to add a process to the queue, runProcess to delete a process from the FRONT if its time_needed is less than or equal to the CAPACITY, cpuSchedule to print all the processes in the queue, killProcess to delete the FRONT process if its time_needed is greater than the CAPACITY and add it to a StackLL object, and emptyQueue to check if the queue is empty.

The third part requires implementing a Stack using Linked List. The StackLL class is template-based and can accept any type of data. It contains attributes such as TOP pointer and methods such as pushProcess to add a process to the top of the stack, stackOfProcesses to print all the processes in the stack, lateProcess to get the latest process from the top of the stack, and emptyStack to check if the stack is empty.

The fourth part requires calculating the complexity and T(n) equation of the excecute method in QueueLL and showing the Big O at the end.

The fifth part is a bonus part that requires implementing a binary tree and its traversing method to print the binary tree nodes. The binary tree is implemented in a separate class in the same file, and testing is added in the main() function.

In summary, this project involves implementing CPUProcess and ProcessNode classes, a Queue using Linked List, a Stack using Linked List, calculating complexity, and implementing a binary tree as a bonus part.
