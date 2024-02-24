#include <thread>
#include <iostream>
#include <atomic>
#include <cstdlib>
#include <unistd.h>

const int n = 8; 
std::atomic<bool> cupcake(true);
std::atomic<int> flags[n];
std::thread partygoers[n];
int first;

void run_first() {
	int count = 0;
	while(true)  {
		// check if it's your turn
		if(flags[first].load() == 1) {
			// if there is a cupcake eat it
			if(cupcake.load() == true) {
				std::cout << "partygoer " << first <<  " ate the cupcake. Currently at " << count << ".\n";
				count++;
				cupcake.store(false);
			}
		}

		// check if count is n to terminate
		if(count == n) {
			// let the minotaur know 
			flags[first].store(2);
			break;
		}

		// otherwise return back home
		flags[first].store(0);
	}
}

void run_plebs(int i) {
	bool visited = false;
	while(true)  {
		// check if it's your turn in the maze
		// if you visited already just ignore it and finish the maze
		if(flags[i].load() == 1 && !visited) {
			// if there is no cupcake, put one there
			if(cupcake.load() == false) {
				std::cout << "partygoer " << i <<  " returned the cupcake\n";
				cupcake.store(true);
			}
		}

		// otherwise return back home
		flags[first].store(0);
	}
}


int main() {
	std::srand(std::time(nullptr));
	first = std::rand() % n;
	std::cout << "running 8 threads\n"; 
	std::cout << "first thread is " << first << "\n";

	// give threads jobs
	for(int i=0; i < n; i++) {
		if(i != first) {
			partygoers[i] = std::thread(run_plebs, i);
		}
		else {
			partygoers[i] = std::thread(run_first);
		}
	}
	
	// here we act as the minotaur
	while(flags[first].load() != 2) {
		int visitor = std::rand() % n;
		std::cout << "Sending partygoer " << visitor << " through the maze\n";
		flags[visitor].store(1);
		// wait til they finish the maze
		while(flags[visitor].load() == 1) {
			usleep(5000);
		}
	}

	std::cout << "Minotaur got news that all guests have gone through the maze\n";
}
