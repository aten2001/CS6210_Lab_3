#ifndef LRUCACHE_H
#define LRUCACHE_H

#include "cache_base.h"
#include <stdlib.h>

class cache_LRU : public cache_base {
	
public:

	cache_LRU(int cache_size_max) : cache_base(cache_size_max){
		cache_size_active = 0;
		cache_map.clear();
		lru_bit.clear();
	}
	virtual ~cache_LRU(){}

	void update(const std::string &url, const std::string &body) override;
	void evict() override;
	std::string get_content(std::string url) override;

private:

	TStrIntMap lru_bit;

};

#endif
