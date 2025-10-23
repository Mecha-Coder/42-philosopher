```text
 _  _  ____            _     _ _                       _               
| || ||___ \ _   _ __ | |__ (_) | ___  ___  ___  _ __ | |__   ___ _ __ 
| || |_ __) (_) | '_ \| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__|
|__   _/ __/ _  | |_) | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |   
   |_||_____(_) | .__/|_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|   
                |_|                             |_|                                                       
```

### **Overview**

An introduction to concurrency through the classic Dining Philosophers problem. This simulation demonstrates how to manage threads or processes, so all philosophers have fair eating chance and not starve to dead.

---

### **About**

👉 [**Project requirement**](https://github.com/Mecha-Coder/42-philosopher/blob/main/demo/en.subject.pdf)

The Dining Philosophers problem is a foundational computer science exercise in concurrency, which explores how multiple tasks (threads or processes) can safely share limited resources.

Concurrency is like having several workers performing tasks at the same time with a shared resource.

Trouble begins when multiple workers tries to modify the same resource simultaneously. This led to data race, where the results is unpredictable.

Since this project is written in C, we use below synchronization primitives to solve this problem:

- mutex (mutual exclusion locks)
- semaphore

![figure1](https://github.com/Mecha-Coder/42-philosopher/blob/main/demo/figure1.png)

A mutex or semaphore acts like key to a locked resource — only one person can hold the key and use the resource. When done, the key must be returned so others can use to unlock the resource.

Another thing to watch for is deadlock, where someone forgets to return the key. Others can’t enter and wait indefinitely for a resource to be released.

![figure2](https://github.com/Mecha-Coder/42-philosopher/blob/main/demo/figure2.png)

The goal of the simulation is to ensure fair resource time (forks or chopsticks) to every philosopher, so all have the chance to “eat” without starving or blocking others.

This project is implemented in two parts:
- Threads version — each philosopher is a thread.
- Processes version — each philosopher runs as a separate process.

---

### **Learnings**
- The conecept of thread and process working together to achieve a goal
- Understand the concept and benefit of concurrency
- The challenges of using concurrency
- Managed concurrency to prevent Deadlock and Data Race

---

### **How to run**

System requirement: **Debian/Ubuntu/WSL2**


```bash
# Install dependencies

# Clone the repository
git clone https://github.com/Mecha-Coder/42-philosopher

# Nagivate into the project folder
cd 42-philosopher/philo         # Simulation using thread
cd 42-philosopher/philo_bonus   # Simulation using process

# Build the program
make

# Run the simulation
./philo 5 620 200 200 5        # Simulation using thread
./philo_bonus 5 620 200 200 5  # Simulation using process

# where the agrument to the program as follows
   # arg 1 = number of philos
   # arg 2 = duration to die
   # arg 3 = duration to eat
   # arg 4 = duration to sleep
   # arg 5 = number of meals required to end the simulation

```

---

### **Resource**

---

### **Demo**

![demo](https://github.com/Mecha-Coder/42-philosopher/blob/main/demo/demo.gif)
