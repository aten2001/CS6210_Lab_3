#ifndef MAXSCACHE_H
#define MAXSCACHE_H

#include "cache_base.h"
#include <stdlib.h>

class cache_MAXS : public cache_base {
	
public:

	cache_MAXS(int cache_size_max) : cache_base(cache_size_max){
		cache_size_active = 0;
		cache_map.clear();
	}
	virtual ~cache_MAXS(){}

	void update(const std::string &url, const std::string &body) override;
	void evict() override;


};

#endif
