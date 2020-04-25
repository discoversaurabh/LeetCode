/*
LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 ); --> capacity 

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*
APPROACH IS MENTIONED INLINE
*/

class LRUCache {
public:
    // list to store the sequence of values as they come in lru cache
    list<int> lruList;
    
    // map to store the key value pair and the address of the correspondng node of this key in list.
    // The second part of this map contains a pair of int and list<int> type iterator in which first int
    // stores the value of key and second part (list<int>::iterator) stores the address of that node in
    // doubly linked list
    unordered_map<int, pair<int, list<int>::iterator>> lruMap;
    
    //stores the provided capacity of the lru cache, we need to check our actual list size with this
    // parameter time to time when we will get a insert command to enter new key value pair in our lru cache
    int _capacity;
    
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = lruMap.find(key);
        
        // if key is not found then return -1
        if( it == lruMap.end() )
        {
            return -1;
        }
        else
        {
            // if key is found then we need to erase that key from list as we need to re-insert
            // it to the front of the list, for that list<int> only accepts the address of the node
            // in erase() method and it does not work on the key value, it only accepts the node address
            // to be deleted
            lruList.erase(it->second.second);
            lruList.push_front(key);
            
            // as the key was already present in the map so that means we only need to update its address
            // to new address(which will be the begining node of the list as we are going to reinsert
            // this key to the front of the list
            lruMap[key].second = lruList.begin();
            
            //return its value
            return lruMap[key].first;
        }
    }
    
    void put(int key, int value) {
        auto it = lruMap.find(key);
        if(it == lruMap.end())
        {
            //new entry or removed entry, check existing size
            if(lruList.size() >= _capacity )
            {
                // if list is already full then remove the least used key which is at the last node
                int tmp = lruList.back();
                lruList.pop_back();
                
                //erase this key from the map as well, in map we can erase from just the key,we do not
                // need address as we need in the list to remove an element
                auto ite = lruMap.find(tmp);
                lruMap.erase(ite);  //erase this key
            }
            //once last element is removed we need to push this new key to the front of the list
            // and update its value and address also (new address is front of the list)
            lruList.push_front(key);
            lruMap[key].first = value;
            lruMap[key].second = lruList.begin();
        }
        else
        {
            // if the key is already present then just erase it from existing position in list and then
            // reinsert it to the front of the list
            lruList.erase(it->second.second);
            lruList.push_front(key);
            // update its value and its address as it is now at the front of our doubly linked list
            lruMap[key].first = value;
            lruMap[key].second = lruList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
