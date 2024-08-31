#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Trie {
public:
  Trie() { nodes.emplace_back(); }

  void insert(std::string word) {
    int nId = 0;
    for (char c : word) {
      auto &node = nodes[nId];
      if (node.find(c) == node.end()) {
        nId = nodes.size();
        node.emplace(c, nId);
        nodes.emplace_back();
      } else {
        nId = node[c];
      }
    }
    if (nodes[nId].find(0) == nodes[nId].end()) {
      nodes[nId].emplace(0, nodes.size());
      nodes.emplace_back();
    }
  }

  bool search(std::string word) {
    int nId = 0;
    for (char c : word) {
      auto &node = nodes[nId];
      if (node.find(c) == node.end())
        return false;
      nId = node[c];
    }
    if (nodes[nId].find(0) == nodes[nId].end()) {
      return false;
    }
    return true;
  }

  bool startsWith(std::string prefix) {
    int nId = 0;
    for (char c : prefix) {
      auto &node = nodes[nId];
      if (node.find(c) == node.end())
        return false;
      nId = node[c];
    }
    return true;
  }

private:
  std::vector<std::unordered_map<char, int>> nodes;
};

int main(void) {
  Trie t{};
  t.insert("apple");
  std::cout << std::boolalpha << t.search("apple") << '\n';
  std::cout << std::boolalpha << t.search("app") << '\n';
  std::cout << std::boolalpha << t.startsWith("app") << '\n';
  t.insert("app");
  std::cout << std::boolalpha << t.search("app") << '\n';
  return 0;
}
