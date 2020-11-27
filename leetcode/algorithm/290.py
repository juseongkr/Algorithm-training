class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        x, y = {}, {}
        words = s.split(' ')

        if len(words) != len(pattern):
            return False

        for pat, word in zip(pattern, words):
            if pat not in x:
                if word in y:
                    return False
                else:
                    x[pat] = word
                    y[word] = pat
            elif x[pat] != word:
                return False

        return True

