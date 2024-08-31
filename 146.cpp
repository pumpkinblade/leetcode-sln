#include <iostream>
#include <unordered_map>

struct LRUNode {
  int key, val;
  LRUNode *prev, *next;
};

class LRUCache {
public:
  LRUCache(int capacity)
      : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    LRUNode *node = map[key];
    if (node != head) {
      if (node->prev)
        node->prev->next = node->next;
      if (node->next)
        node->next->prev = node->prev;
      if (node->next == nullptr)
        tail = node->prev;
      node->next = head;
      head->prev = node;
      node->prev = nullptr;
      head = node;
    }
    return node->val;
  }

  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      map[key]->val = value;
      get(key);
      return;
    }
    if (size == capacity) {
      map.erase(tail->key);
      if (head == tail) {
        delete tail;
        head = tail = nullptr;
      } else {
        LRUNode *prev = tail->prev;
        tail->prev->next = nullptr;
        delete tail;
        tail = prev;
      }
      size--;
    }

    LRUNode *node = new LRUNode{key, value, nullptr, nullptr};
    map.insert({key, node});
    if (head == nullptr) {
      head = tail = node;
    } else {
      node->next = head;
      head->prev = node;
      head = node;
    }
    size++;
  }

  void print() {
    LRUNode *node = head;
    while (node) {
      std::cout << "(" << node->key << "," << node->val << ")->";
      node = node->next;
    }
    std::cout << "    ";
    node = tail;
    while (node) {
      std::cout << "(" << node->key << "," << node->val << ")<-";
      node = node->prev;
    }
    std::cout << '\n';
  }

private:
  std::unordered_map<int, LRUNode *> map;
  LRUNode *tail;
  LRUNode *head;
  int capacity;
  int size;
};

int main(void) {
  LRUCache lRUCache(2);
  lRUCache.put(2, 1);
  lRUCache.print();
  lRUCache.put(1, 1);
  lRUCache.print();
  lRUCache.put(1, 1);
  lRUCache.print();
  lRUCache.put(2, 3);
  lRUCache.print();
  lRUCache.put(4, 1);
  lRUCache.print();
  int x1 = lRUCache.get(1);
  lRUCache.print();
  int x2 = lRUCache.get(2);
  lRUCache.print();
  std::cout << x1 << ' ' << x2 << '\n';
}
