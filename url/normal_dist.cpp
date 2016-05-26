// normal_distribution
#include <iostream>
#include <string>
#include <fstream>
#include <random>

int main(int argc, char *argv[])
{
	std::string policy;
	std::string cache_size;

	if(argc == 4){
		policy = argv[1];
		cache_size = argv[2];
	}
	else{
		printf("normal_dist usage: ./urllist <policy> <cache size> <workload: 1-uniform 2-normal>\n");

	}
	const int nrolls = 200;  // number of experiments

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(5.0, 2.0);

	std::ofstream myfile;
	myfile.open("url_list.txt");
	//visit largest web least frequently 
	std::string p1[10]={
		"https://www.yahoo.com",
		"http://www.amazon.com/",
		"http://www.ign.com",
		"https://www.bing.com/",
		"http://www.twitch.tv/",
		"http://www.msn.com/",
		"http://www.gametrailers.com/",
		"https://www.google.com",
		"http://www.ebay.com/",
		"https://www.youtube.com",
	};
	//visit largest web most frequently 
	std::string p2[10]={
		"http://www.amazon.com/",
		"http://www.ign.com",
		"https://www.bing.com/",
		"http://www.twitch.tv/",
		"https://www.yahoo.com",
		"http://www.msn.com/",
		"http://www.gametrailers.com/",
		"https://www.google.com",
		"http://www.ebay.com/",
		"https://www.youtube.com"
	};
	myfile << policy << " " << cache_size <<"\n";

	switch(atoi(argv[3])){
		case 1:
			for (int i=0; i<nrolls; ++i) {
				myfile << p1[(int(rand()%10))] << "\n";
			}
			break;
		case 2:
			for (int i=0; i<nrolls; ++i) {
				double number = distribution(generator);
				if ((number>=0.0)&&(number<10.0))
					myfile << p1[(int(number))] << "\n";
				else
					printf("number = %d\n", number);
			}
			break;
		default:
			printf("normal_dist usage: ./urllist <policy> <cache size> <workload: 1-uniform 2-normal>\n");
			break;
	}

	myfile << "end\n";
	myfile.close();
	return 0;
}
