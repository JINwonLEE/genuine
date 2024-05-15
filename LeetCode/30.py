class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        hmap = {}
        for w in words:
            if w not in hmap:
                hmap[w] = 0
            hmap[w] += 1
        wl = len(words[0])
        res = []
        for offset in range(0, wl):
            occurence = 0
            seen = {}
            i = offset
            while i + wl <= len(s):
                t_str = s[i:i + wl]
                if t_str in hmap:
                    if t_str not in seen:
                        seen[t_str] = 0
                    seen[t_str] += 1
                    occurence += 1
                    while seen[t_str] > hmap[t_str]:
                        left = s[i - wl * (occurence - 1):i - wl * (occurence - 1) + wl]
                        
                        seen[left] -= 1
                        occurence -= 1
                    if occurence == len(words):
                        res.append(i - (occurence - 1) * wl)
                else:
                    occurence = 0
                    seen.clear()
                i += wl
        return res

