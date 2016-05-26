#ifndef RANDCACHE_H
#define RANDCACHE_H

#include "cache_base.h"
#include <stdlib.h>

class cache_rand : public cache_base {
	
public:

	cache_rand(int cache_size_max) : cache_base(cache_size_max){
		cache_size_active = 0;
		cache_map.clear();
	}
	virtual ~cache_rand(){}

	void update(const std::string &url, const std::string &body) override;
	void evict() override;


};

#endif