set terminal pngcairo size 1280,800 enhanced font 'Verdana,12'
set output 'sorts_comparison.png'

set title "Сравнение времени сортировок (HW_8_3)"
set xlabel "Размер массива (N)"
set ylabel "Время (мс)"
set grid
set key outside
set datafile separator '\t'

plot \
    'results.txt' using 1:2 with linespoints title "Bubble Sort", \
    'results.txt' using 1:3 with linespoints title "Insertion Sort", \
    'results.txt' using 1:4 with linespoints title "Selection Sort", \
    'results.txt' using 1:5 with linespoints title "Quick Sort", \
    'results.txt' using 1:6 with linespoints title "Merge Sort"
