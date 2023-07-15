class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        """
        Things to notice:
        1-indexed.

        Each bit is flipped only once.
        So we start with 00...00
        End with 11...11

        So the question becomes, for how many bits do we have
        flips[:i] == [1, 2, 3, 4 ... i - 1]?

        We can do this by sorting by flip time.

        At each step, just need to count the maximum
        idx of a bit that has been flipped.

        if it's == i-1 when we see position i, we know that it
        is prefix-aligned.
        """

        maxStep = 0

        res = 0


        for idx, step in enumerate(flips, 1):
            maxStep = max(maxStep, step)

            if (maxStep == idx):
                # max bit set so far (1-indexed) is number of
                # timesteps taken (0-indexed)
                res += 1
            
        return res