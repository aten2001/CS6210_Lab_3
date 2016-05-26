
#include <string>

#include "cache_FIFO.h"

void cache_FIFO::update(const std::string &url, const std::string &body){

	if(body.size() == 0){
		DEBUG_MSG("no content fetched from %s... update terminated.\n", url.c_str());
		return;
	}

	while(cache_size_active + body.size() >= cache_size_max){
		DEBUG_MSG("evicting... active: %d bytes, insert: %d bytes\n", cache_size_active,body.size());
		evict();
	}		
	
	FIFO_queue.push(url);
	cache_map.insert(TStrStrPair(url, body));
	cache_size_active += body.size();
	
	DEBUG_MSG("cache miss...writing to cache... %s completed.\n", url.c_str());


}

void cache_FIFO::evict(){

	std::string evict_url;
	evict_url = FIFO_queue.front();
	TStrStrMap::iterator evict_item = cache_map.find(evict_url);

	if(evict_item->first.c_str() == evict_url){
		FIFO_queue.pop();
		cache_size_active -= evict_item->second.size();
		DEBUG_MSG("%s is evicted, size: %d\n", evict_item->first.c_str(), evict_item->second.size());
		cache_map.erase(evict_url);
	}
	

}
