#ifndef MYCONTAINER_H
#define MYCONTAINER_H

using namespace std;

template <typename T>
class MyContainer
{
  public:
    using value_type      = T;
    using reference       = T&;
    using const_reference = const T&;
    using size_type       = int;

    class iterator
    {
      private:
        value_type* address { nullptr };
      public:
        iterator()
        {
          cout<<"MyContainer::iterator Default Costructor"<<endl;
        }

        iterator(value_type* addr)
        : address(addr)
        {
          cout<<"MyContainer::iterator Costructor"<<endl;
        }

        reference operator* ()
        {
          return *address;
        }
        void set(value_type* addr)
        {
          address = addr;
        }
        iterator& next()
        {
          address++;
          return *this;
        }
        iterator& operator++ (int i)
        {
          address++;
          return *this;
        }
        iterator& operator++ ()
        {
          ++address;
          return *this;
        }
        bool operator!=(const iterator& it)
        {
          return address!=it.address;
        }
        bool operator==(const iterator& it)
        {
          return address==it.address;
        }
    };    

  private:
    value_type* val       { nullptr };
    size_type   size_val  { 0 };
    size_type   reserved  { 0 };
    iterator*   it        { nullptr };

  public:
    MyContainer(void);
    MyContainer(const MyContainer& old);
    ~MyContainer(void);

    // Modify
    void push_back(const_reference cr);
    void pop_back(void);

    // Info
    bool empty(void) const;
    size_type size(void) const;

    // Access
    reference back(void);
    reference operator[](int i);
    iterator& end(void);
    iterator& begin(void);
};

template <typename T>
MyContainer<T>::MyContainer(void)
{
  cout<<"MyContainer::Constructor"<<endl;
  it = new iterator();
}

template <typename T>
MyContainer<T>::MyContainer(const MyContainer& old)
{
  cout<<"MyContainer::Copy constructor"<<endl;
  it = new iterator();
  size_val = old.size_val;
  reserved = old.reserved;
  val = (value_type*) calloc (sizeof(value_type),reserved);
  for(int i=0; i<size_val; i++)
  {
    val[i]=old.val[i];
  }
}

template <typename T>
MyContainer<T>::~MyContainer(void)
{
  if(val)
    free(val);
  if(it)
    delete it;
}

template <typename T>
void MyContainer<T>::push_back(const_reference cr)
{
  if(++size_val > reserved)
    ++reserved;

  value_type* val2 = (value_type*) calloc (sizeof(value_type),reserved);
  if(val)
  {
    for(int i=0; i<size_val-1; i++)
    {
      val2[i]=val[i];
    }
    free(val);
    val2[size_val-1] = cr;
    val=val2;
  }
  else
  {
    val=val2;
    val[size_val-1] = cr;
  }
}

template <typename T>
void MyContainer<T>::pop_back(void)
{
  --size_val;
}

template <typename T>
bool MyContainer<T>::empty(void) const
{
  return !(bool)val;
}

template <typename T>
typename MyContainer<T>::size_type MyContainer<T>::size(void) const
{
  return size_val;
}

template <typename T>
typename MyContainer<T>::reference MyContainer<T>::back(void)
{
  return val[size_val-1];
}


template <typename T>
typename MyContainer<T>::reference MyContainer<T>::operator[](int i)
{
  return val[i];
}

template <typename T>
typename MyContainer<T>::iterator& MyContainer<T>::end(void)
{
  it->set(val+size_val);
  return *(it);
}

template <typename T>
typename MyContainer<T>::iterator& MyContainer<T>::begin(void)
{
  it->set(val);
  return *(it);
}

#endif
