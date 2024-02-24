# 2092. Find All People With Secret
# https://leetcode.com/problems/find-all-people-with-secret

class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0]*n
    def find(self, x):
        if self.parent[x]!=x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px!=py:
            if self.parent[px]<=self.parent[py]:
                px, py = py, px
            self.parent[py] = px
            if self.rank[px]==self.rank[py]:
                self.rank[px] += 1

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
	
		# inital the graph
        graph = UnionFind(n)
        graph.union(0,firstPerson)
		
        meetings.sort(key=lambda x: x[2])
		
        ptr = 0
        while ptr<len(meetings):
            curr_time = meetings[ptr][2]
			
			# get all the meetings happening at this time
            start = ptr
            end = ptr
            while end<len(meetings) and meetings[end][2]==curr_time:
                end += 1
            
           # record the nodes for all the people attending meeting at this time
            people = set()
            
			# union
            for i in range(start, end):
                node_1, node_2 = meetings[i][0], meetings[i][1]
                graph.union(node_1,node_2)
                people.add(node_1)
                people.add(node_2)
            
			# reset nodes that are not connect to 0 
            for node in people:
                if graph.find(node)!=graph.find(0):
                    graph.parent[node] = node
                    graph.rank[node] = 0
					
			# update pointer		
            ptr = end
        
        ans = []
        for i in range(n):
            if graph.find(i) == graph.find(0):
                ans.append(i)
        
        return ans
