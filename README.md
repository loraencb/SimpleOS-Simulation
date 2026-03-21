# SimpleOS Simulation

![C](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20WSL-green)
![Build](https://img.shields.io/badge/build-Makefile-orange)
![Status](https://img.shields.io/badge/status-Active-success)

A lightweight **Operating System simulator** written in C that demonstrates core OS concepts such as process management, memory allocation, file systems, and system calls through an interactive shell.

---

## Features

- **Process Management**
  - Create and list processes
  - Round-robin style scheduler

- **Memory Management**
  - Page-based allocation (bitmap)
  - Tracks used and free memory

- **File System**
  - Create, read, and list files
  - In-memory storage

- **System Calls Simulation**
  - `open`, `read`, `write`, `close`

- **Interactive Shell**
  - CLI interface for OS interaction

---

## Requirements

This project runs best in a **Linux environment**.

### Recommended (Windows Users)
Use Ubuntu via WSL:

```bash
wsl --install
wsl -d Ubuntu

## Installation & Run
1. Navigate to the project
```bash
cd /mnt/c/Users/YOUR_USERNAME/path/to/SimpleOS-Simulation/simpleOS

2. Install dependencies (first time only)
```bash
sudo apt update
```bash
sudo apt install build-essential -y
3. Build the project
```bash
make
4. Run the simulator
```bash
./simpleos

| Command               | Description                |
| --------------------- | -------------------------- |
| `help`                | Show available commands    |
| `ps`                  | List processes             |
| `sched`               | Run scheduler tick         |
| `mem`                 | Show memory usage          |
| `ls`                  | List files                 |
| `cat <file>`          | Display file contents      |
| `read <file>`         | Read file via system calls |
| `write <file> <text>` | Write to file              |
| `run`                 | Create a demo process      |
| `exit`                | Exit simulator             |

## Architecture
simpleOS/
├── main.c        # Kernel entry point
├── process.c     # Process table & scheduler
├── memory.c      # Page allocation system
├── fs.c          # File system simulation
├── syscall.c     # System call layer
├── shell.c       # Command interface
├── *.h           # Headers
├── Makefile      # Build system

## How It Works
The system initializes:
Process table
Memory bitmap
File system
Open file table
Then launches an interactive shell where users can:
Create processes
Allocate memory
Read/write files
Simulate scheduling

## Notes
This is a simulation, not a real OS kernel.
All data is stored in memory (no persistence).
Built for educational purposes.

## Contributors
- Bobbi Perry
- Braulio Lora 
- Karina Ponze

## Learning Objectives
Understand OS fundamentals
Explore process scheduling
Simulate memory management
Implement system call interfaces
Work with low-level C programming

## Future Improvements
Priority-based scheduling
Persistent file system
Multi-threading simulation
Enhanced error handling
GUI visualization

## Usage Tip
If you're running on Windows, always use:
wsl -d Ubuntu
before building and running the project.
