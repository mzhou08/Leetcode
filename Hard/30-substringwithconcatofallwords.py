from collections import deque
from collections import Counter, defaultdict

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:

        """
        Since all words have the same length k, we can go through s,
        k at a time, and convert it into all numbers 1->len(words).

        Then we just need to check that all n words occur in length-n window, which we can do by keeping a length-n array.
        """
        k = len(words[0])

        self.target_counts = Counter(words)

        res = []

        for i in range(k):
            res += self.helper(i, s, k, words)

        return res

    def helper(self, start_idx: int, s, k, words) -> int:

        seen_words = defaultdict(int)
        num_words = 0

        res = []

        # size-k steps
        for i in range(start_idx, len(s), k):

            # candidate string: look forward k
            candidate = s[i:i+k]

            if candidate in words:
                # if buffer is full
                if num_words == len(words):
                    prev_word_start = i - k * len(words)
                    prev_word = s[
                        prev_word_start:
                        prev_word_start + k
                    ]

                    seen_words[prev_word] -= 1
                    num_words -= 1

                    # to make dict have no 0 entries
                    if seen_words[prev_word] == 0:
                        del seen_words[prev_word]

                # increment counts
                seen_words[candidate] += 1
                num_words += 1

                if seen_words == self.target_counts:
                    res.append(
                        i - k * (len(words) - 1)
                    )

            else:
                seen_words = defaultdict(int)
                num_words = 0

        return res
