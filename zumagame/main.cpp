#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        int n_hand = hand.size();
        for (int i = 0; i < hand.size(); i++) {
            if (input.count(hand[i]) == 0)
                input[hand[i]] = 1;
            else
                input[hand[i]] += 1;
        }
        return helper(board, n_hand);
    }

private:
    unordered_map<char, int> input;

    int helper(string& board, int n_hand) {
        if (board.size() == 0) {
            cout << "0" << endl;
            return 0;
        }
        if (n_hand == 0) {
            cout << "-1" << endl;
            return -1;
        }
        int ans = INT_MAX;
        for (int i = 0; i < board.size(); i++) {
            if (input.count(board[i]) == 0 || input[board[i]] == 0) continue;
            if (i == board.size() - 1 || board[i] != board[i+1]) {
                if (input[board[i]] < 2) continue;
            }

            if (i == board.size() - 1 || board[i] != board[i+1]) {
                int start = i;
                int end = i;
                input[board[i]] -= 2;
                string newstr = update(board, start, end);
                int ret = helper(newstr, n_hand - 2);
                input[board[i]] += 2;
                if (ret < 0) continue;
                ans = min(ans, ret + 2);
            } else {
                int start = i;
                int end = i+1;
                input[board[i]] -= 1;
                string newstr = update(board, start, end);
                int ret = helper(newstr, n_hand - 1);
                input[board[i]] += 1;
                i++;
                if (ret < 0) continue;
                ans = min(ans, ret + 1);
            }
        }
        if (ans == INT_MAX) {
            cout << "-1" << endl;
            return -1;
        } else {
            cout << ans << endl;
            return ans;
        }
    }

    string update(const string& board, int start, int end) {
        while (start > 0 && end < board.size() - 1) {
            int total = 0;
            char c = board.c_str()[start - 1];
            int newstart = start;
            int newend = end;
            while (newstart - 1 >= 0 && board[newstart - 1] == c) {
                total += 1;
                newstart -= 1;
            }
            while (newend + 1 < board.size() && board[newend + 1] == c) {
                total += 1;
                newend += 1;
            }
            if (total >= 3) {
                start = newstart;
                end = newend;
            } else {
                break;
            }
        }
        string ret = board.substr(0, start);
        if (end < board.size() - 1)
            ret += board.substr(end + 1);
        cout << ret << endl;
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}