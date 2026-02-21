#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<char> vovels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

string GetRuler(const string& kingdom) {
  // TODO: implement this method to determine the ruler name, given the kingdom.
  string ruler = "";
  char lastLet = kingdom[kingdom.length()-1];
  if (lastLet=='y' || lastLet=='Y') {
      ruler = "nobody";
  } else if (vovels.find(lastLet)!=vovels.end()) {
      ruler = "Alice";
  } else {
      ruler = "Bob";
  }
  return ruler;
}

int main() {
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}
