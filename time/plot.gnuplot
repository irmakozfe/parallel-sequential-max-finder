set terminal png size 800,600
set output 'results_comparison.png'
set title "Sequential vs Parallel Execution Time"
set xlabel "Number of Threads"
set ylabel "Execution Time (seconds)"
set grid
set key left top
plot "results.txt" using 1:2 with linespoints title "Sequential Time", \
     "results.txt" using 1:3 with linespoints title "Parallel Time"
