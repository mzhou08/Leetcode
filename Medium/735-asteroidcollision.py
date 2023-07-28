from collections import deque

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        """
        Stack Approach
        """

        stack = deque()

        for ast in asteroids:
            add = True

            while stack and stack[-1] > 0 and ast < 0:
                # need to pop
                if stack[-1] + ast < 0:
                    stack.pop()
                elif stack[-1] + ast == 0:
                    stack.pop()
                    add = False
                    break
                else:
                    add = False
                    break

            if add:
                stack.append(ast)

        return list(stack)

