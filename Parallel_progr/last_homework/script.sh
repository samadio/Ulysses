module load cudatoolkit/10.0
cd /home/samadio/hpc/Parallel_progr/last_homework
for tries in 1 2 3 4 5; do
./naive_transpose.x >> /home/samadio/hpc/Parallel_progr/last_homework/results_serial.txt
done

exit
