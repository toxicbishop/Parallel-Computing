# Parallel Computing (BCS702)

A collection of OpenMP programs implemented as part of the **Parallel Computing (BCS702)** laboratory course. The programs demonstrate the use of OpenMP directives such as `parallel`, `sections`, `tasks`, and `parallel for` to solve computational problems and compare sequential and parallel execution.

The repository is based on the BCS702 lab manual. :contentReference[oaicite:0]{index=0}

## Repository Structure

```text
Parallel-computing/
├── 01.c    # Sequential and Parallel Merge Sort using OpenMP Sections
├── 02.c    # Static Scheduling with Chunk Size = 2
├── 03.c    # Fibonacci Series using OpenMP Tasks
├── 04.c    # Prime Numbers using OpenMP Parallel For
├── README.md
└── LICENSE
```

## Programs

| File | Experiment |
|------|------------|
| `01.c` | Sequential and Parallel Merge Sort using OpenMP Sections |
| `02.c` | Static Scheduling (`schedule(static, 2)`) |
| `03.c` | Fibonacci Series using OpenMP Tasks |
| `04.c` | Prime Number Generation using OpenMP Parallel For |

## Requirements

- GCC (with OpenMP support)
- MinGW-w64 / GCC on Windows, or GCC on Linux
- OpenMP

## Compilation

Compile any program using:

```bash
gcc <filename>.c -fopenmp -o <output>
```

Example:

```bash
gcc 01.c -fopenmp -o 01.exe
```

## Execution

Windows (Git Bash)

```bash
./01.exe
```

Linux

```bash
./01
```

## Learning Objectives

- Understand shared-memory parallel programming.
- Learn OpenMP directives and scheduling policies.
- Compare sequential and parallel execution.
- Measure execution time using `omp_get_wtime()`.
- Explore task-based and data-parallel programming.

## License

This repository is intended for educational and academic purposes.