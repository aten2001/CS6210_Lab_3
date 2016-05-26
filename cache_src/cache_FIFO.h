#ifndef FIFOCACHE_H
#define FIFOCACHE_H
#include <queue>

#include "cache_base.h"

class cache_FIFO : public cache_base {
	
public:

	cache_FIFO(int cache_size_max) : cache_base(cache_size_max){
		cache_size_active = 0;
		cache_map.clear();
	}
	virtual ~cache_FIFO(){}

	void update(const std::string &url, const std::string &body) override;
	void evict() override;

private:

	std::queue<std::string> FIFO_queue;

};
#endif
