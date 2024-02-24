#include <thread>
#include <iostream>
#include <atomic>
#include <unistd.h>

const int n = 8; 
std::atomic<bool> vase(false);
std::atomic<bool> flags[n];
std::thread partygoers[n];

void visit_vase(int i) {
	int wait = 50;
	do {
		while(vase) usleep(wait = wait * 2);
	} while(vase.exchange(true) && !flags[i].load());
	// lock acquired
	std::cout << "Partygoer " << i << " has visited the vase!\n";
	flags[i].store(true);
	vase.store(false);
}

int main() {
	std::cout << "Opening room for vase\n";

	// give threads jobs
	// set their flags to false
	for(int i=0; i < n; i++) {
		flags[i].store(false);
		partygoers[i] = std::thread(visit_vase, i );
	}


	for(int i=0; i < n; i++) {
		partygoers[i].join();
	}
	std::cout << "everyone has seen the vase!\n";
}
