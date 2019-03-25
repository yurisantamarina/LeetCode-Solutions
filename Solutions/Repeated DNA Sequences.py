class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        dic = {}
        for i in range(len(s)):
            if i + 9 >= len(s):
                break
            if s[i:i + 10] in dic:
                dic[s[i:i + 10]] += 1
            else:
                dic[s[i:i + 10]] = 1
        answer = []
        for i in dic.keys():
            if dic[i] > 1:
                answer.append(i)
        return answer
