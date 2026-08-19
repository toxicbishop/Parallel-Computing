# Parallel Computing (BCS702)

A collection of **OpenMP** (Shared Memory) and **MPI** (Distributed Memory) programs implemented as part of the **Parallel Computing (BCS702)** laboratory course.

---

## Repository Structure

```text
Parallel-computing/
├── 01.c    # Sequential and Parallel Merge Sort using OpenMP Sections
├── 02.c    # Static Scheduling with Chunk Size = 2 (OpenMP)
├── 03.c    # Fibonacci Series using OpenMP Tasks
├── 04.c    # Prime Number Generation using OpenMP Parallel For
├── 05.c    # Point-to-Point Communication using MPI_Send and MPI_Recv
├── 06.c    # Deadlock Simulation and Resolution in MPI
├── 07.c    # Broadcast Communication using MPI_Bcast
├── 08.c    # Collective Scatter and Gather using MPI_Scatter and MPI_Gather
├── 09.c    # Reduction Operations using MPI_Reduce and MPI_Allreduce
├── README.md
└── LICENSE
```

---

## Programs

| File | Type | Description |
|------|------|-------------|
| `01.c` | OpenMP | Sequential and Parallel Merge Sort using OpenMP Sections |
| `02.c` | OpenMP | Static Scheduling (`schedule(static, 2)`) |
| `03.c` | OpenMP | Fibonacci Series using OpenMP Tasks |
| `04.c` | OpenMP | Prime Number Generation using OpenMP Parallel For |
| `05.c` | MPI | Point-to-Point Communication (`MPI_Send` & `MPI_Recv`) |
| `06.c` | MPI | Deadlock Simulation & Resolution |
| `07.c` | MPI | Broadcast Communication (`MPI_Bcast`) |
| `08.c` | MPI | Array Distribution & Collection (`MPI_Scatter` & `MPI_Gather`) |
| `09.c` | MPI | Collective Reductions (`MPI_Reduce` & `MPI_Allreduce`) |

---

## Prerequisites & Installation

### 1. Windows

#### A. Compiler & OpenMP (via MSYS2)
1. Install [MSYS2](https://www.msys2.org/).
2. Open the **MSYS2 UCRT64** terminal and install GCC (which includes OpenMP):
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```

#### B. MPI Setup (Microsoft MPI SDK)
1. Install the MS-MPI development headers and wrapper in MSYS2:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-msmpi
   ```
2. *(Optional/Recommended for `mpiexec` runtime)* Install Microsoft MPI:
   - Run in PowerShell:
     ```powershell
     winget install Microsoft.msmpi
     ```
   - Or download and run `msmpisetup.exe` from [Microsoft Download Center](https://www.microsoft.com/en-us/download/details.aspx?id=105289).

#### C. VS Code IntelliSense (Optional)
To resolve `#include <mpi.h>` and avoid include errors in VS Code, create/update `.vscode/c_cpp_properties.json`:
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "D:/msys64/ucrt64/include/**"
            ],
            "compilerPath": "D:/msys64/ucrt64/bin/gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```
*(Adjust the path `C:/msys64` or according to your MSYS2 installation location).*

---

### 2. Linux Distributions

MPI and OpenMP can be installed directly using the distribution's package manager:

#### **Ubuntu / Debian / Linux Mint / Pop!_OS**
```bash
sudo apt update
sudo apt install build-essential mpich
```
*(Alternative using OpenMPI: `sudo apt install build-essential libopenmpi-dev openmpi-bin`)*

#### **Fedora / RHEL / CentOS / AlmaLinux**
```bash
sudo dnf install gcc mpich mpich-devel
```
*(Load MPI modules if required: `module load mpi/mpich-x86_64`)*

#### **Arch Linux / Manjaro**
```bash
sudo pacman -S base-devel mpich
```

---

## Compilation & Execution

### OpenMP Programs (`01.c` – `04.c`)

#### **Compile**
- **Windows / Linux**:
  ```bash
  gcc 01.c -fopenmp -o 01.exe   # Windows
  gcc 01.c -fopenmp -o 01       # Linux
  ```

#### **Run**
- **Windows**:
  ```bash
  ./01.exe
  ```
- **Linux**:
  ```bash
  ./01
  ```

---

### MPI Programs (`05.c` – `09.c`)

#### **Compile**
- **Windows (MSYS2)**:
  ```bash
  mpicc 05.c -o 05.exe
  # or with gcc:
  gcc 05.c -lmsmpi -o 05.exe
  ```
- **Linux**:
  ```bash
  mpicc 05.c -o 05
  ```

#### **Run (Multi-Process)**
Run with `-n` (or `-np`) followed by the desired number of processes (e.g., 2 or 4):
- **Windows**:
  ```bash
  mpiexec -n 2 ./05.exe
  ```
- **Linux**:
  ```bash
  mpirun -np 2 ./05
  # or
  mpiexec -n 2 ./05
  ```

---

## Learning Objectives

- **Shared Memory (OpenMP)**: Directives (`parallel`, `sections`, `tasks`, `for`), scheduling strategies (`static`, `dynamic`), and timing with `omp_get_wtime()`.
- **Distributed Memory (MPI)**: Process rank and size management, point-to-point communication (`MPI_Send`, `MPI_Recv`), collective communication (`MPI_Bcast`, `MPI_Scatter`, `MPI_Gather`), and global reductions (`MPI_Reduce`, `MPI_Allreduce`).

---

## License

This repository is intended for educational and academic purposes.