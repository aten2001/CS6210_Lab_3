
#ifndef BASECACHE_H
#define BASECACHE_H

#include <map>
#include <string>

//#define DEBUG_ON

#ifdef DEBUG_ON
#define DEBUG_MSG(...) fprintf (stderr, __VA_ARGS__)
#else
#define DEBUG_MSG(...) 
#endif

typedef std::pair<std::string, std::string> TStrStrPair;
typedef std::map<std::string, std::string> TStrStrMap;

typedef std::pair<std::string, int> TStrIntPair;
typedef std::map<std::string, int> TStrIntMap;

class cache_base{
	
	public:

		cache_base(int cache_size_max);
		virtual ~cache_base();

		/* implemented by derived class */
		virtual void update(const std::string &url, const std::string &body) = 0;
		virtual void evict() = 0;

		/* derived by other classes */
		virtual std::string get_content(std::string url);


	protected:
		int cache_size_max;
		int cache_size_active;
		TStrStrMap cache_map;


};

#endif
