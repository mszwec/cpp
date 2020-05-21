#ifndef URLSERVICE_H
#define URLSERVICE_H

#include <iostream>
#include <map>
#include <set>

using Collection = std::set < std::string >;
using UserUrlMap = std::map < std::string, Collection >;  

class UrlService
{

public:
  UrlService() = default;
  ~UrlService() = default;

  bool saveUrl(const std::string& userToken, const std::string& url);

  // getUrl returns a copy of a collection therefore it is a const method
  Collection getUrl(const std::string& userToken) const;

  bool removeUrl(const std::string& userToken, const std::string& url);
  
  // removeUrl(const std::string& userToken)
  // is used in a test example
  // and its assumed purpose is to delete all URLs from user
  bool removeUrl(const std::string& userToken);

private:
  UserUrlMap userUrl_;
};

bool UrlService::saveUrl(const std::string& userToken, const std::string& url)
{
  auto it = userUrl_.find(userToken);
  if (it != userUrl_.end())
  {
    // User exists, try to insert url to set
    auto& urlSet = (*it).second;
    return urlSet.insert(url).second;
  }
  
  Collection collection;
  collection.insert(url);
  auto result = userUrl_.emplace(std::make_pair(userToken, collection)); 
  return result.second;
}
  
Collection UrlService::getUrl(const std::string& userToken) const
{
  auto it = userUrl_.find(userToken);

  if (it == userUrl_.end())
  {
    // No such user, returning empty collection
    return {};
  }

  auto& urlSet = (*it).second;
  return urlSet;
}

bool UrlService::removeUrl(const std::string& userToken, const std::string& url)
{
  auto it = userUrl_.find(userToken);
  if (it == userUrl_.end())
  {
    // No such user, nothing to delete
    return false;
  }

  auto& urlSet = (*it).second;
  size_t result = urlSet.erase(url);

  return result > 0;
}

bool UrlService::removeUrl(const std::string& userToken)
{
  auto it = userUrl_.find(userToken);
  if (it == userUrl_.end())
  {
    // No such user, nothing to delete
    return false;
  }

  auto& urlSet = (*it).second;
  if (urlSet.size() == 0)
  {
    // No URLs, nothing to delete
    return false;
  }

  urlSet.clear();
  return urlSet.size() == 0;
}
#endif
