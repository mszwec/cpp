#include "UrlService.h"

// Testing functions headers
void basicTest();
void returnSaveValueTest();
void removeSingleUrlTest();
void getEmptyCollectionTest();
void getCollectionTest();

// main
int main()
{
  basicTest();
  returnSaveValueTest();
  removeSingleUrlTest();
  getEmptyCollectionTest();
  getCollectionTest();

  std::cout << "success" << std::endl;
  return 0;
}

// Testing functions

void basicTest()
{
  UrlService service;
  service.saveUrl("tom", "www.example.com");
  service.saveUrl("tom", "www.example.com/news");
  service.saveUrl("john", "www.other.com");

  int found = service.getUrl("tom").size();

  if (found != 2)
  {
    std::string print ("Something went wrong. There should be 2 URLs assigned to tom but " + std::to_string(found) + " found");
    std::cout << print << std::endl;
  }

  service.removeUrl("john");
}

void returnSaveValueTest()
{
  UrlService service;
  bool returnValue;
  bool expectValue;

  returnValue = service.saveUrl("tom", "www.example.com");
  expectValue = true;

  if (returnValue != expectValue)
  {
    std::cout << "Bad return value" << std::endl;
  }

  returnValue = service.saveUrl("tom", "www.example.com");
  expectValue = false;

  if (returnValue != expectValue)
  {
    std::cout << "Bad return value" << std::endl;
  }
}


void removeSingleUrlTest()
{
  UrlService service;
  service.saveUrl("tom", "www.example.com");
  service.saveUrl("tom", "www.example.com/news");
  
  bool returnValue = service.removeUrl("tom", "www.example.com/news");
  int found = service.getUrl("tom").size();

  if (found != 1)
  {
    std::string print ("Something went wrong. There should be 1 URLs assigned to tom but " + std::to_string(found) + " found");
    std::cout << print << std::endl;
  }
 
  if (returnValue != true)
  {
    std::cout << "Bad return value" << std::endl;
  }
  
  returnValue = service.removeUrl("tom", "www.example.com/news");
  if (returnValue != false)
  {
    std::cout << "Bad return value" << std::endl;
  }
}

void getEmptyCollectionTest()
{
  UrlService service;
  service.saveUrl("tom", "www.example.com");
  service.saveUrl("tom", "www.example.com/news");
  int found = service.getUrl("john").size();

  if (found != 0)
  {
    std::string print ("Something went wrong. There should be 0 URLs assigned to tom but " + std::to_string(found) + " found");
    std::cout << print << std::endl;
  }
}

void getCollectionTest()
{
  Collection expect;
  expect.insert("www.example.com");
  expect.insert("www.example.com/news");
  expect.insert("www.example.com/news2");
  
  UrlService service;
  service.saveUrl("tom", "www.example.com");
  service.saveUrl("john", "www.other.com");
  service.saveUrl("tom", "www.example.com/news");
  service.saveUrl("john", "www.other.com/news");
  service.saveUrl("tom", "www.example.com/news2");
  service.saveUrl("john", "www.other.com/news2");

  auto result = service.getUrl("tom");
  if (expect != result)
  {
    std::cout << "Expected URLS not found" << std::endl;
    return;
  }


}

