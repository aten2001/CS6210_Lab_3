cd build
array=(rand FIFO MAXS LRU no_cache)
size=(1024000 1536000 2048000)
#size=(1024000)

for i in `seq 0 1 2` # cache size
do
	for j in `seq 0 1 4`
	do
		./urllist ${array[$j]} ${size[$i]} 1
		./client
	done
done
