class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
       map<int, int> count;

    for (int card : hand)
      ++count[card];

    for (auto& it : count) {
      int value = count[it.first];
      if (value > 0)
        for (int i = it.first; i < it.first + groupSize; ++i) {
          count[i] -= value;
          if (count[i] < 0)
            return false;
        }
    }

    return true;
    }
};