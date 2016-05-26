
#include <string>

#include "cache_LRU.h"

void cache_LRU::update(const std::string &url, const std::string &body){


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

void cache_LRU::evict(){
	TStrStrMap::iterator evict_item;
	TStrIntMap::iterator evict_counter;
	std::string evict_url;
	int max_count = 0;

	for(auto it = lru_bit.begin(); it != lru_bit.end(); ++it){
		if(max_count < it->second){
			max_count = it->second;
			evict_url = it->first;
			evict_counter = it;
		}
	}

	if(max_count == 0){
		evict_item = cache_map.begin();
		lru_bit.erase(evict_item->first);
	}
	else{
		evict_item = cache_map.find(evict_url);
		lru_bit.erase(evict_counter);
	}
	cache_size_active -= evict_item->second.size();
	DEBUG_MSG("%s is evicted, size: %d\n", evict_item->first.c_str(), evict_item->second.size());
	cache_map.erase(evict_item);
}

std::string cache_LRU::get_content(std::string url){
	TStrStrMap::iterator iter = cache_map.find(url);
	TStrIntMap::iterator recent_used;

	if(lru_bit.find(url) == lru_bit.end()){
		lru_bit.insert(TStrIntPair(url, 0));
		recent_used = lru_bit.find(url);
		for(auto it = lru_bit.begin(); it != lru_bit.end(); ++it){
			if(it == recent_used)
				continue;
			it->second++;
		}	
	}
	else{
		recent_used = lru_bit.find(url);
		for(auto it = lru_bit.begin(); it != lru_bit.end(); ++it){
			if(it == recent_used){
				it->second = 0;
				continue;
			}
			it->second++;
		}
	}

        if(iter == cache_map.end())
        {
                return "NULL";
        }
        else{
                std::string body;
                body = iter->second;    // get the value (webpage body)
                return body;
        }

}
