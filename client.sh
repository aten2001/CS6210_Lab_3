cd build
array=(rand FIFO MAXS LRU no_cache)
size=(1024000 1536000 2048000)

for k in `seq 1 1` # workloads 1: uniform, 2: normal
do
for i in `seq 0 0` # cache size
do
	for j in `seq 0 0` # cache policy
	do
		./urllist ${array[$j]} ${size[$i]} $k
		./client
	done
done
done
