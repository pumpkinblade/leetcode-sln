#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  enum TokenType { ADD, SUB, UMO, LPR, RPR, END, N };
  struct Token {
    TokenType t;
    int v;
    Token(TokenType t) : t(t), v(0) {}
    Token(TokenType t, int v) : t(t), v(v) {}
  };
  inline static int actionTable[N][N] = {
          /* +  -  U  (  )  E */ /*stk*/
      /*+*/ {1, 1, 1, 0, 1, 0},
      /*-*/ {1, 1, 1, 0, 1, 0},
      /*U*/ {0, 0, 1, 0, 1, 0},
      /*(*/ {0, 0, 0, 0,-1, 0},
      /*)*/ {1, 1, 1, 0, 1,-1},
      /*E*/ {1, 1, 1,-1, 1, 2}};
  stack<TokenType> oprStk;
  stack<int> valStk;

  vector<Token> lex(const string &s) {
    std::vector<Token> tokens;
    size_t pos = 0;
    int val = 0;
    char *endptr = nullptr;
    std::vector<char> buf;
    while (pos < s.size()) {
      switch (s[pos]) {
      case '+':
        tokens.emplace_back(ADD);
        pos++;
        break;
      case '-':
        if (!tokens.empty() && (tokens.back().t == RPR || tokens.back().t == N))
          tokens.emplace_back(SUB);
        else
          tokens.emplace_back(UMO);
        pos++;
        break;
      case '(':
        tokens.emplace_back(LPR);
        pos++;
        break;
      case ')':
        tokens.emplace_back(RPR);
        pos++;
        break;
      case ' ':
        pos++;
        break;
      default:
        // number
        buf.clear();
        while (std::isdigit(s[pos])) {
          buf.push_back(s[pos++]);
        }
        buf.push_back(0);
        val = std::strtol(buf.data(), &endptr, 0);
        tokens.emplace_back(N, val);
        break;
      }
    }
    tokens.emplace_back(END);
    // for (auto [t, v] : tokens) {
    //   std::cout << t << ' ' << v << '\n';
    // }
    return tokens;
  }

  void pop() {
    int x;
    switch (oprStk.top()) {
    case ADD:
      x = valStk.top();
      valStk.pop();
      valStk.top() += x;
      break;
    case SUB:
      x = valStk.top();
      valStk.pop();
      valStk.top() -= x;
      break;
    case UMO:
      valStk.top() = -valStk.top();
      break;
    case RPR:
      oprStk.pop();
      break;
    default:
      // error
      break;
    }
    oprStk.pop();
  }

  int parse(const vector<Token> &tokens) {
    valStk = stack<int>();
    oprStk = stack<TokenType>();
    oprStk.push(END);
    for (int i = 0; i < tokens.size();) {
      auto tk = tokens[i];
      if (tk.t == N) {
        valStk.push(tk.v);
        i++;
      } else {
        int action = actionTable[tk.t][oprStk.top()];
        if (action == 0) {
          oprStk.push(tk.t);
          i++;
        } else if (action == 1) {
          pop();
        } else {
          break;
        }
      }
    }
    return valStk.top();
  }

  int calculate(string s) { return parse(lex(s)); }
};

int main(void) {
  string s = "-2+1";
  int res = Solution{}.calculate(s);
  std::cout << res << '\n';
  return 0;
}
