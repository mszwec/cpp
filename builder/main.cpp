#include <iostream>
#include <fstream>

using namespace std;

class Builder
{
    public:
            string source;
            virtual void read() {};
            virtual void open() {};
            virtual void close() {};
};

class FileRead: public Builder
{
    public:
        ifstream file;
        string filename;

        FileRead(string filename)
        {
            this->filename = filename;
        };

        virtual void open()
        {
            file.open(filename.c_str());
        };

        virtual void close()
        {
            file.close();
        };

        virtual void read()
        {
            if(file.is_open())
            {
                string line;
                while(getline(file, line))
                    cout << line << endl;
            }
        }
};

class Director
{
    private:
        Builder *b;
    public:
        void setBuilder(Builder *b)
        {
            this->b=b;
        }

        void run()
        {
            b->open();
            b->read();
            b->close();
        }
};

int main()
{
    Director *d = new Director();
    d->setBuilder(new FileRead("file.txt"));
    d->run();
}
