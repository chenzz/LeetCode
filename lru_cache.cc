#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
	LRUCache(int capacity)
	{
		capacity_ = capacity;
	}

	int get(int key)
	{
		if (cache_map_.find(key) == cache_map_.end())
			return -1;
		else
		{
			//delete old node and push a new node in front of list
			int temp = cache_map_[key]->second;
			cache_.erase(cache_map_[key]);
			cache_.push_front(pair<int, int>(key, temp));
			cache_map_[key] = cache_.begin();
			return temp;
		}
	}

	void set(int key, int value)
	{
		if (cache_map_.find(key) == cache_map_.end())
		{
			if (cache_.size() >= capacity_)
			{
				//delete the last node of list
				cache_map_.erase(cache_.back().first);
				cache_.pop_back();
			}
			//push new node in front of list
			cache_.push_front(pair<int, int>(key, value));
			cache_map_[key] = cache_.begin();
		}
		else
		{
			//delete old node and push a new node in front of  list
			cache_.erase(cache_map_[key]);
			cache_.push_front(pair<int, int>(key, value));
			cache_map_[key] = cache_.begin();
		}
	}

private:
	int capacity_;
	list<pair<int, int>> cache_;
	unordered_map<int, list<pair<int, int>>::iterator> cache_map_;
};

int main()
{
	LRUCache cache(3);
	cache.set(1, 87);
	cache.set(2, 9);
	cache.set(3, 34);

	return 0;
}
