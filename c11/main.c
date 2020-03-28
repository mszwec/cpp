#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  char s[]="Hellow World";

  int Up=0;

  auto lambda = [&Up] (char c)
  {
    if(isupper(c))
      Up++;
  };

  for_each(s, s+sizeof(s), lambda);

  cout << "Up: " << Up << endl;

  return 0;
}
