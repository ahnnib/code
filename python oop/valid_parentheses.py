from collections import deque

class Solution:
    @staticmethod
    def dbg():
        print("dfad")

    @staticmethod
    def opening(ch) -> str:
        if ch == ')':
            return '('
        if ch == ']':
            return '['
        if ch == '}':
            return '{'

    @staticmethod
    def is_open(ch) -> bool:
        return ch in '([{'

    @staticmethod
    def is_close(ch) -> bool:
        return ch in ')]}'

    def isValid(self, s: str) -> bool:
        st = deque()

        for c in s:
            if Solution.is_open(c):  # Call static method via class name
                st.append(c)
            if Solution.is_close(c):
                if not st:
                    return False
                if st[-1] != Solution.opening(c):
                    return False
                st.pop()

        return not st

# Example usage
sol = Solution()
print(sol.isValid("()[]{}"))  # Output: True
print(sol.isValid("([)]"))    # Output: False
