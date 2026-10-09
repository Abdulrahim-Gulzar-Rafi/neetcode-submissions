class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        for course, prereq in prerequisites:
            graph[prereq].append(course)
            indegree[course] += 1

        order = []
        q = deque(i for i in range(numCourses) if not indegree[i])

        while q:
            node = q[0]
            q.popleft()
            order.append(node)
            for neighbour in graph[node]:
                indegree[neighbour] -= 1
                if not indegree[neighbour]:
                    q.append(neighbour)

        return order if len(order) == numCourses else []

