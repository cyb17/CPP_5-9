#include <bits/stdc++.h>
#include <ctime>

int main () 
{
	std::time_t	currentTime = std::time( NULL );
	std::cout << std::time( &currentTime ) << '\n';
  return 0;
}
