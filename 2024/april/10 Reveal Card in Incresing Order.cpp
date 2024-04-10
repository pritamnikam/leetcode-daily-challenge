// 950. Reveal Card in Incresing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        // queue for indices
        for (int i = 0; i < N; i++) {
            queue.push(i);
        }

        sort(deck.begin(), deck.end());

        // Put cards at correct index in result
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            // Reveal card
            result[queue.front()] = deck[i];
            queue.pop();

            // move card to bottom
            if (!queue.empty()) {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }
};
