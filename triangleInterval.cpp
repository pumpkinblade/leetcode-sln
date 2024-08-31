#include <cassert>
#include <deque>
#include <vector>

int triangleInterval(const std::vector<int> &lengths) {
  assert(lengths.size() >= 3);

  std::deque<int> dqD, dqA, dqS;
  if (lengths[0] > lengths[1]) {
    dqD.push_back(0);
    dqD.push_back(1);
  } else {
    dqD.push_back(1);
  }
  if (lengths[0] < lengths[1]) {
    dqA.push_back(0);
    dqA.push_back(1);
  } else {
    dqA.push_back(1);
    dqS.push_back(0);
  }
  int start = 0;
  int maxlen = 2;
  for (int i = 2; i < lengths.size(); i++) {
    // check triangle's conditions
    while (i - start >= 2) {
      bool cond1 = lengths[dqD.front()] - lengths[dqA.front()] < lengths[i];
      int subminimum = 0;
      if (dqS.empty()) {
        subminimum = lengths[dqA[1]];
      } else if (dqA.size() <= 2) {
        subminimum = lengths[dqS[0]];
      } else {
        subminimum = std::min(lengths[dqA[1]], lengths[dqS[0]]);
      }
      bool cond2 = lengths[dqA.front()] + subminimum > lengths[i];

      if (cond1 && cond2)
        break;

      start++;
      while (!dqD.empty() && dqD.front() < start) {
        dqD.pop_front();
      }
      while (!dqA.empty() && dqA.front() < start) {
        dqA.pop_front();
      }
      while (!dqS.empty() && dqS.front() < start) {
        dqS.pop_front();
      }
      for (int j = dqS.empty() ? start : dqS.back(); j < dqA[0]; j++) {
        while (!dqS.empty() && lengths[dqS.back()] >= lengths[j]) {
          dqS.pop_back();
        }
        dqS.push_back(j);
      }
    }

    // monotonic
    while (!dqA.empty() && lengths[dqA.back()] >= lengths[i]) {
      dqA.pop_back();
    }
    dqA.push_back(i);
    while (!dqD.empty() && lengths[dqD.back()] <= lengths[i]) {
      dqD.pop_back();
    }
    dqD.push_back(i);
    for (int j = dqS.empty() ? start : dqS.back(); j < dqA[0]; j++) {
      while (!dqS.empty() && lengths[dqS.back()] >= lengths[j]) {
        dqS.pop_back();
      }
      dqS.push_back(j);
    }

    // maxlen update
    maxlen = std::max(maxlen, i + 1 - start);
  }
  return maxlen;
}
