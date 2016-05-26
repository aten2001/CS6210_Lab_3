#cmake_minimum_required(VERSION 3.0)
Project(Test_build)

# For Mac OS X 10.9 workaround
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w")

set(SERVER_SRC
	gen-cpp/proxy_constants.cpp
	gen-cpp/proxy_constants.h
	gen-cpp/proxy_types.cpp
	gen-cpp/proxy_types.h
	gen-cpp/proxy.cpp
	gen-cpp/proxy.h
	gen-cpp/proxy_server.skeleton.cpp
	cache_src/cache_base.cpp
	cache_src/cache_base.h
	cache_src/cache_FIFO.cpp
	cache_src/cache_FIFO.h
	cache_src/cache_MAXS.cpp
	cache_src/cache_MAXS.h
	cache_src/cache_LRU.cpp
	cache_src/cache_LRU.h
	cache_src/cache_rand.cpp
	cache_src/cache_rand.h)

set(CLIENT_SRC
	gen-cpp/client.cpp
	gen-cpp/proxy.cpp
	gen-cpp/proxy.h)

set(URL_SRC
	url/normal_dist.cpp)


add_executable(server ${SERVER_SRC})
target_link_libraries(server thrift curl)

add_executable(client ${CLIENT_SRC})
target_link_libraries(client thrift)

add_executable(urllist ${URL_SRC})
target_link_libraries(urllist)