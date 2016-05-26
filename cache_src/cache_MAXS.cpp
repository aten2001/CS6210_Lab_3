
#include <string>

#include "cache_MAXS.h"

void cache_MAXS::update(const std::string &url, const std::string &body){

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

void cache_MAXS::evict(){
	TStrStrMap::iterator evict_item;
	int max_size = 0;

	for(auto it = cache_map.begin(); it != cache_map.end(); ++it){
		if(max_size < it->second.size()){
			max_size = it->second.size();
			evict_item = it;
		}
	}

	cache_size_active -= evict_item->second.size();
	DEBUG_MSG("%s is evicted, size: %d\n", evict_item->first.c_str(), evict_item->second.size());
	cache_map.erase(evict_item);
	

}
