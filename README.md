# Parallel and Sequential Maximum Finder

This project implements a program to find the maximum value in an array using both sequential and parallel approaches with `pthreads`. It measures execution time for both approaches and compares their performance. Results are stored in a `results.txt` file, and GNUplot is used to visualize the results.

---

## Features

- **Parallel Maximum Finder**:
    - Uses `pthreads` to divide the array into chunks and calculate the maximum value concurrently.
    - Global maximum is updated safely using `pthread_mutex`.

- **Sequential Maximum Finder**:
    - Computes the maximum value in a single-threaded manner.

- **Performance Comparison**:
    - Measures execution time for sequential and parallel approaches.
    - Results are saved in `results.txt`.

- **Visualization**:
    - Results are visualized using GNUplot to compare the performance.

---

## Files

- **`main.c`**:  
  Source code of the program.

- **`results.txt`**:  
  Contains execution times for sequential and parallel approaches for each run.

- **`Makefile`**:  
  Automates the build process.

- **`results_comparison.png`**:  
  Chart comparing execution times of sequential and parallel approaches.

---

## Requirements

- **GNU C Compiler (`gcc`)**:
  To compile the C program.

- **GNUplot**:
  To visualize the results.

- **Pthreads**:
  For parallel computation (POSIX threads).

---

## Compilation and Execution

1. **Compile**:
   ```bash
   make
   ggc -o file_creator main.c

2. **Run the Program**:
    ```bash
    ./file_creator
   
3. **Create the Chart**
    ```bash
    gnuplot plot.gnuplot

![Chart](C:\Users\Irmak\CLionProjects\time\results_comparison.png)
# Parallel and Sequential Maximum Finder

This project implements a program to find the maximum value in an array using both sequential and parallel approaches with `pthreads`. It measures execution time for both approaches and compares their performance. Results are stored in a `results.txt` file, and GNUplot is used to visualize the results.

---

## Features

- **Parallel Maximum Finder**:
    - Uses `pthreads` to divide the array into chunks and calculate the maximum value concurrently.
    - Global maximum is updated safely using `pthread_mutex`.

- **Sequential Maximum Finder**:
    - Computes the maximum value in a single-threaded manner.

- **Performance Comparison**:
    - Measures execution time for sequential and parallel approaches.
    - Results are saved in `results.txt`.

- **Visualization**:
    - Results are visualized using GNUplot to compare the performance.

---

## Files

- **`main.c`**:  
  Source code of the program.

- **`results.txt`**:  
  Contains execution times for sequential and parallel approaches for each run.

- **`Makefile`**:  
  Automates the build process.

- **`results_comparison.png`**:  
  Chart comparing execution times of sequential and parallel approaches.

---

## Requirements

- **GNU C Compiler (`gcc`)**:
  To compile the C program.

- **GNUplot**:
  To visualize the results.

- **Pthreads**:
  For parallel computation (POSIX threads).

---

## Compilation and Execution

1. **Compile**:
   ```bash
   make
   ggc -o file_creator main.c

2. **Run the Program**:
    ```bash
    ./file_creator
   
3. **Create the Chart**
    ```bash
    gnuplot plot.gnuplot

---

## Conclusion

In conclusion, this project, implemented in C, highlights the fundamental concepts of time measurement and performance analysis in computing. Through sequential and parallel maximum-finding algorithms, it explores performance trade-offs and demonstrates how execution times can vary due to factors like workload distribution and environmental noise. The results, visualized using GNUplot, emphasize the importance of precise measurement and tuning for reliable performance evaluation, providing a solid foundation for further optimization and experimental analysis in system programming.
