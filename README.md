# STM32F4 Task Scheduler (Round Robin with Task Delay and Priority Support)

![Platform](https://img.shields.io/badge/platform-STM32F407-blue)
![Language](https://img.shields.io/badge/language-C-blue)
![IDE](https://img.shields.io/badge/IDE-STM32CubeIDE-green)
![License](https://img.shields.io/badge/license-MIT-lightgrey)
![Project Status](https://img.shields.io/badge/status-learning-informational)
![Made With Love](https://img.shields.io/badge/Made%20with-%F0%9F%92%9C-ff69b4)

This project implements a basic task scheduler in C on the STM32F407 Discovery board. The scheduler is designed using a round-robin strategy and includes task delay management and support for idle task execution. Inspired by Kiran Nayak's Udemy course, this implementation adds a custom priority override feature to give more control over task execution order.

## Features

- **Fully Preemptive Round-Robin Scheduling**: Each task is given CPU time in turn, interrupted every 1 ms by a system tick.
- **Task Delay Mechanism**: Tasks can block themselves for a number of ticks, freeing up the CPU for others.
- **Idle Task**: Executes when no other tasks are ready to run.
- **Custom Task Priority** (Custom Addition): One task can be configured to be of priority and hence is allowed to preempt others if it's ready.
- **Efficient Context Switching**:
  - `SysTick` interrupt drives the 1 ms system tick.
  - Tasks are unblocked when delay expires.
  - `PendSV` is used to perform the context switch, ensuring minimal ISR latency and deterministic task switching.

## How It Works

<pre> SysTick (every 1 ms) <br><pre>         ↓ </pre> Update task block counters <br><pre>         ↓ </pre> Are any tasks unblocked? <br><pre>         ↓ </pre> Yes ──► Set PendSV Pending <br><pre>         ↓ </pre> PendSV Handler <br><pre>         ↓ </pre> Context Switch to next ready task </pre>

## Hardware & Tools

- STM32F407 Discovery Board  
- STM32CubeIDE  
- C Programming Language  

## Behavior

- Four user-defined tasks blink the on-board LEDs (Green, Orange, Blue, Red) with different delays.
- Tasks voluntarily yield the CPU after execution using a delay function.
- The idle task runs only when all others are delayed.
- A configurable prioritized task (set in code) always executes first if it’s ready.

## Getting Started

1. Clone the repository and open the project in STM32CubeIDE.
2. Connect your STM32F407 Discovery board via ST-Link.
3. Build and flash the firmware to the target.
4. Observe the LED behavior as per task scheduling logic.

## Directory Structure

Core/ <br>
├── Inc/ # Header files (main.h) <br>
├── Src/ # Source files (main.c) <br>
Startup/ <br>
└── startup_stm32f407xx.s <br>

## Learnings

- Building a fully preemptive task scheduler from scratch on ARM Cortex-M.
- Leveraging `SysTick` for precise periodic interrupts to drive task scheduling.
- Implementing context switching using the `PendSV` exception to defer low-priority context changes.
- Deepened understanding of STM32, interrupt handling, and register-level control.
- Managing task states: ready, running, blocked, and idle with custom delay and priority logic.

## License

This project is licensed under the MIT License – see the [LICENSE](./LICENSE) file for details.
