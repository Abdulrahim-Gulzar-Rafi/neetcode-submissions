class Solution:
    def calPoints(self, operations: List[str]) -> int:
        st = list()
        total = 0
        for i in operations:
            if i == "+":
                st.append(st[-1] + st[-2])
                total += st[-1]
            elif i == "D":
                st.append(2 * st[-1])
                total += st[-1]
            elif i == "C":
                total -= st[-1]
                st.pop()
            else:
                st.append(int(i))
                total += st[-1]
        return total