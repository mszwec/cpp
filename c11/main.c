#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

    char s[]="Hellow World";

    int Up=0;

    for_each(s, s+sizeof(s), [&Up] (char c)
             {
                if(isupper(c))
                    Up++;
             }
             
             );
    
    cout << "Up: " << Up << endl;
    
    return 0;
}
