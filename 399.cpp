#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class UnionFind {
public:
  UnionFind(int n) : parent(n), weight(n, 1.0) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      int ori = parent[x];
      parent[x] = find(ori);
      weight[x] *= weight[ori];
    }
    return parent[x];
  }

  double val(int x, int y) {
    if (find(x) == find(y)) {
      return weight[x] / weight[y];
    } else {
      return -1;
    }
  }

  void unionW(int x, int y, double w) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      parent[rootX] = rootY;
      weight[rootX] = w * weight[y] / weight[x];
    }
  }

private:
  std::vector<int> parent;
  std::vector<double> weight;
};

class Solution {
public:
  std::vector<double>
  calcEquationRef(std::vector<std::vector<std::string>> &equations,
                  std::vector<double> &values,
                  std::vector<std::vector<std::string>> &queries) {
    std::unordered_map<std::string, int> nameNodeMap;
    UnionFind uf(2 * equations.size());
    for (int i = 0; i < equations.size(); i++) {
      const auto &uName = equations[i].front();
      const auto &vName = equations[i].back();
      if (nameNodeMap.find(uName) == nameNodeMap.end()) {
        nameNodeMap[uName] = nameNodeMap.size();
      }
      if (nameNodeMap.find(uName) == nameNodeMap.end()) {
        nameNodeMap[vName] = nameNodeMap.size();
      }
      uf.unionW(nameNodeMap[uName], nameNodeMap[vName], values[i]);
    }

    std::vector<double> result;
    for (int i = 0; i < queries.size(); i++) {
      const auto &uName = equations[i].front();
      const auto &vName = equations[i].back();
      if (nameNodeMap.find(uName) == nameNodeMap.end() ||
          nameNodeMap.find(vName) == nameNodeMap.end()) {
        result.push_back(-1);
      } else {
        result.push_back(uf.val(nameNodeMap[uName], nameNodeMap[vName]));
      }
    }

    return result;
  }
  std::vector<double>
  calcEquation(std::vector<std::vector<std::string>> &equations,
               std::vector<double> &values,
               std::vector<std::vector<std::string>> &queries) {
    std::unordered_map<std::string, int> nameNodeMap;
    std::vector<std::vector<std::pair<int, double>>> edgesPerNode;
    for (int i = 0; i < values.size(); i++) {
      const auto &uName = equations[i].front();
      const auto &vName = equations[i].back();
      double val = values[i];
      if (nameNodeMap.find(uName) == nameNodeMap.end()) {
        nameNodeMap.emplace(uName, static_cast<int>(edgesPerNode.size()));
        edgesPerNode.emplace_back();
      }
      if (nameNodeMap.find(vName) == nameNodeMap.end()) {
        nameNodeMap.emplace(vName, static_cast<int>(edgesPerNode.size()));
        edgesPerNode.emplace_back();
      }
      int u = nameNodeMap[uName];
      int v = nameNodeMap[vName];
      edgesPerNode[u].push_back({v, val});
      edgesPerNode[v].push_back({u, 1 / val});
    }

    std::vector<double> result;
    for (int i = 0; i < queries.size(); i++) {
      const auto &sName = queries[i].front();
      const auto &tName = queries[i].back();
      if (nameNodeMap.find(sName) == nameNodeMap.end() ||
          nameNodeMap.find(tName) == nameNodeMap.end()) {
        result.push_back(-1);
        continue;
      }
      int s = nameNodeMap[sName];
      int t = nameNodeMap[tName];
      if (s == t) {
        result.push_back(1);
        continue;
      }

      double ans = -1;
      std::vector<bool> mark(edgesPerNode.size(), false);
      mark[s] = true;
      std::queue<std::pair<int, double>> q;
      for (auto [v, val] : edgesPerNode[s]) {
        if (!mark[v]) {
          q.push({v, val});
          mark[v] = true;
        }
      }
      while (!q.empty()) {
        auto [u, acc] = q.front();
        q.pop();
        if (u == t) {
          ans = acc;
          break;
        }
        for (auto [v, val] : edgesPerNode[u]) {
          if (!mark[v]) {
            q.push({v, acc * val});
            edgesPerNode[s].push_back({v, acc * val});
            mark[v] = true;
          }
        }
      }

      result.push_back(ans);
    }

    return result;
  }
};
