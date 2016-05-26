
#include "cache_base.h"
#include <iostream>

cache_base::cache_base(int size) : cache_size_max(size){

	cache_size_active = 0;
}

cache_base::~cache_base(){

	DEBUG_MSG("cache_base is destructed.\n");
}

std::string cache_base::get_content(std::string url){
	
	
	TStrStrMap::iterator iter = cache_map.find(url);

	if(iter == cache_map.end())
	{
		return "NULL";
	}
	else{
		std::string body;
		body = iter->second;	// get the value (webpage body)
		return body;
	}

};
