
#include <string>

#include "cache_rand.h"

void cache_rand::update(const std::string &url, const std::string &body){

	if(body.size() == 0){
		DEBUG_MSG("no content fetched from %s... update terminated.\n", url.c_str());
		return;
	}

	while(cache_size_active + body.size() >= cache_size_max){
		DEBUG_MSG("evicting... active: %d bytes, insert: %d bytes\n", cache_size_active,body.size());
		evict();
	}		
	
	cache_map.insert(TStrStrPair(url, body));
	cache_size_active += body.size();
	
	DEBUG_MSG("cache miss...writing to cache... %s completed.\n", url.c_str());


}

void cache_rand::evict(){
	
	TStrStrMap::iterator evict_item = cache_map.begin();

	std::advance(evict_item, rand() % cache_map.size());


	cache_size_active -= evict_item->second.size();
	
	DEBUG_MSG("%s is evicted, size: %d\n", evict_item->first.c_str(), evict_item->second.size());	
	cache_map.erase(evict_item);
	

}
