#include <cmath>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
// To measure performance, use
// $ make timep
//
// which relies on the bash command
// $ time (./a.out > results.txt)

class Prime_numbers {
  public:
    Prime_numbers(int num_threads = 1): NUM_THREADS{num_threads} { }

    // Returns true if "number" is a prime number
    bool is_prime (int number) {
      if (number < 2) return false;
      for (int i=2; i <= std::sqrt(number); ++i) {
        if ((number % i) == 0) return false;
      }
      return true;
    }


    // find_primes is the algorithm to be run as multiple threads,
    //     adding each prime found to the shared vector "primes".
    // NOTE: You'll likely need to break out the for loop as a separate
    //     method, which will be the code executed by each thread.
    //     The find_prime method will just create and managed the threads.


    // void find_primes(int lower, int upper) {
    //   std::vector <std::thread> threads;
    //     for (int i=lower; i<=upper; ++i) {
    //         if (is_prime(i)) {
    //             primes.push_back(i);
    //         }
    //     }
    // }

    void find_primes_threads(int lower, int upper) {
        for (int i=lower; i<=upper; i++) {
            if (is_prime(i)) {
              m.lock();
                primes.push_back(i);
             m.unlock();
            }
        }
     }

    void find_primes(int lower, int upper) {
      std::vector <std::thread *> threadc;
      int num_search = ceil((upper-lower)/NUM_THREADS);
    	int lo = lower;
      for (int i=0; i<= NUM_THREADS; i++)
      {
        int l = lo;
        int u = l + num_search;
        int x = fmin(u,upper);
        std::thread* t1 = new 		  std::thread{&Prime_numbers::find_primes_threads,this, l, x};
	threadc.push_back(t1);
	lo = x+1;
      }
      for (int j=0; j< NUM_THREADS; j++)
      {
        threadc[j]->join();
      }
    }

    typedef std::vector<int> Primes;

    // Iterating Prime_numbers will iterate attribute primes
    typedef Primes::iterator iterator;
    typedef Primes::const_iterator const_iterator;
    iterator begin() {return primes.begin();}
    iterator end() {return primes.end();}
    std::mutex m;
  private:
    const int NUM_THREADS;
    // Vector primes will contain all of the primes found
    Primes primes;
};

int main(int argc, char* argv[]) {
    // Determine number of threads requested
    int threads = 1;
    if(argc > 1) threads = atoi(argv[1]);
    Prime_numbers prime_numbers(threads);

    // Determine maximum integer to search
    int max_int = 10000000;

    if(argc > 2) max_int = atoi(argv[2]);

    // Search and identify all primes between 2 and max_int
    prime_numbers.find_primes(2, max_int);

    // Print all primes that were found
    for (int p : prime_numbers) std::cout << p << '\n';
    std::cout << std::endl;



}
