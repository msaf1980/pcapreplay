#include <cstdio>
#include <cxxopts.hpp>

int main(int argc, char *argv[])
{
	bool debug;
	std::string pcap;
	cxxopts::Options options("pcapreplay", "Replay TCP/UDP from pcap file");
	options.add_options()
        ("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
        ("p,pcap", "Pcap file", cxxopts::value<std::string>())
        ("h,help", "Print usage")
    ;
	try {
		auto result = options.parse(argc, argv);
		if (result.count("help")) {
		  std::cout << options.help() << std::endl;
		  exit(0);
		}
		debug = result["debug"].as<bool>();
		if (result.count("pcap")) {
			pcap = result["pcap"].as<std::string>();
		}
	} catch (cxxopts::OptionException &e) {
		fprintf(stderr, "%s\n", e.what());
	}

return 0;
}
