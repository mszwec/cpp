#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

char* function(char* s)
{
    int l=0;
    char* c=s;
    while(*c++) l++;
    int* e = new int[l+1];
    char* r = (char*)calloc(l+1, sizeof(char));
    int ki=0;
    int ri=0;

    for (int i=0; i<l; i++) if(s[i]==' ') e[ki++]=i;
    e[ki]=l;
    while(ki>0)
    {
        for(int i=e[ki-1]+1; i<e[ki]; i++)
        {
            r[ri++]=s[i];
        }
        r[ri++]=' ';
        ki--;
    }
    for(int i=0; i<e[0]; i++)
    {
        r[ri++]=s[i];
    }
    r[ri++]=0;
    delete [] e;
    return r;


}

char* function2(char *s)
{
    int l = 0;

    char *c = s;
    while(*s++)
        l++;

    char* str=(char*)calloc(l+1, sizeof(char));
    str[0]=0;


    int i=0;
    int separator=l;
    char* tmp;
    for(i=separator; i>=0; i--)
    {
        if(c[i]==' ' || i==0)
        {
            tmp = c+i+1;
            if(i==0)
                tmp=c;
            
            if(c[i]==' ')
                separator--;

            strncat(str, tmp, separator-i);

            if(i>0)
                strcat(str, " ");

            separator=i;
        }
    }

    return str;
}



string function3(char *s)
{
    string c(s), test;

    
    
    return c;
}

int mnozenie(int a)
{
    if(a==0)
        return a;

    int reszta = a%2;
    int wynik=0;

    wynik = 67<<(int)(log10(a-reszta)/log10(2));

    if(reszta>0)
    {
        wynik += 67;
    }    
    
    return wynik;

}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        cout << "Usage: egzamin <int number>"<<endl;
        return 1;
    }

    char c[]= {"Ala ma kota"};
    int input=0;

    input=  atoi(argv[1]);

    cout << c << endl;
    char * f = function(c) ;
    cout << f <<endl;
    
    char * f2 = function2(c) ;

cout << "\nf2: " << f2 << endl;
cout << input <<endl;
cout<< mnozenie(input) << endl;

free(f2);
free(f);

    return 0;
}
