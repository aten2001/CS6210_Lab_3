Steps to run the code:
1> bash cleanup.sh
2> bash run.sh
3> open a new termnal window
4> bash client.sh
5> all results are generated in build directory
	5-1. time_result.txt is created by client, including all the time measurements
	5-2. hit_rate.txt is created by server, including all the cache hit/miss results
6> The configuration can be changed in client.sh
	6-1. To change the workload type, please modify line 10:
		./urllist ${array[$j]} ${size[$i]} 2
		the last parameter indicates the workload type (1: rand(), 2: normal distribution)
	6-2. In line 2, the array variable is for specifying the cache policy
	6-3. In line 3, the size variable is for specifying the cache size


