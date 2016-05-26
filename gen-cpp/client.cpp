#include "proxy.h"

#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include <iomanip>

#include <boost/algorithm/string/predicate.hpp>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace std;



int main (int argc, char **argv){

	struct timeval start, end;
	double duration;
	std::string str_result;

	boost::shared_ptr<TSocket> socket (new TSocket("localhost", 9090));
//	boost::shared_ptr<TSocket> socket (new TSocket("localhost", 9090));
	boost::shared_ptr<TTransport> transport (new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol (new TBinaryProtocol(transport));

	proxyClient client(protocol);
	transport->open();

	string line;
	ifstream url_file ("./url_list.txt");
	ofstream time_file ("./time_result.txt", ios::out|ios::app);
	if(url_file.is_open())
	{
		gettimeofday(&start, NULL);
		while(getline(url_file, line)){

			client.req_from_client(str_result, line);
			if(boost::starts_with(line, "http"))
				printf("Got %d bytes from %s.\n", str_result.size(), line.c_str());
		}
		gettimeofday(&end, NULL);
		duration = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec)/1000000.0;
		time_file <<"The elapsed time is " << fixed << setprecision(6)<< duration << " seconds totally." << endl;

		url_file.close();

	}
	else{
		printf("Open url_list.txt fail.\n");
	}

	transport->close();


	return 0;

}
