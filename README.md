# CS6210_Lab_3
RPC-Based Proxy Server (group assignment)

## Objective
The goal of this project is to implement a web proxy server using a remote procedure call (RPC) system (Apache Thrift). Several cache replacement mechanisms are implemented and compared to other approaches. 

## Overview & Implementation
- To implement an RPC system, we used Apache Thrift to generate the cpp files to develop the proxy server. The RPC skeleton was then created and we can just implement the desired features in the pre-declared functions.
- To implement the proxy server, first we loaded the web contents by *libcurl* library. By specifying an URL, we can obtain the corresponding body text. Then we implement a cache to store the web content to serve as a proxy server.
- There are several cache replacement policy implemented in this project: **FIFO**, **RAND**, **MAXS**, and **LRU**. More details are shown in ```\doc\report.pdf```. 
- To run the experiments, we need to generate an URL list to feed the client machine. In this project, we generated the patterns with two distributions: **Normal distribution** and **Uniform distribution**. More details are described in ```\doc\report.pdf```.

## Notes
- There are several scripts for running the codes. Please refer to ```\doc\readme.txt```.
