#include<iostream>
using namespace std;

int find_winner(int n, int k, int start) {
  // If there is only one friend remaining, return that friend as the winner
  if (n == 1) {
    return start;
  }

  // Find the friend that will be eliminated next
  int eliminated = (start + k - 1) % n + 1;

  // Recursively call the function with the number of friends reduced by 1 and the starting friend set to the next friend in the circle
  return find_winner(n - 1, k, eliminated % n + 1);
}

std::pair<int, int> game(int n, int k) {
  return std::make_pair(find_winner(n, k, 1), n);
}
