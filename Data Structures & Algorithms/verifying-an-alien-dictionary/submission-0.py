class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        index_mp = { c: i for i,c in enumerate(order)}
        for j in range(len(words)-1):
            w1, w2 = words[j], words[j+1]
            for i in range(len(w1)):
                if i >= len(w2) or index_mp[w1[i]] > index_mp[w2[i]]:
                    return False
                elif index_mp[w1[i]] < index_mp[w2[i]]:
                    break

        return True
