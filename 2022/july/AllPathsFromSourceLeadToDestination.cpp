/*
1059. All Paths from Source Lead to Destination
https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge 
between nodes ai and bi, and two nodes source and destination of this graph, determine 
whether or not all paths starting from source eventually, end at destination, that is:

At least one path exists from the source node to the destination node
If a path exists from the source node to a node with no outgoing edges, then that node 
is equal to destination.

The number of possible paths from source to destination is a finite number.
Return true if and only if all roads from source lead to destination.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
    enum class Color { GRAY, BLACK };

    class Solution {

    public:
        bool leadsToDestination(int n,
            vector<vector<int>>& edges,
            int source,
            int destination) {

            vector<vector<int>> graph = buildGraph(n, edges);
            unordered_map<int, Color> states;
            return leadsToDestination(graph, source, destination, states);
        }


    private:
        vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n);

            for (auto edge : edges) {
                graph[edge[0]].push_back(edge[1]);
            }

            return graph;
        }

        bool leadsToDestination(vector<vector<int>>& graph,
            int source,
            int destination,
            unordered_map<int, Color>& states
        ) {
            // If the state is GRAY, this is a backward edge and hence, it creates a loop.
            if (states.count(source)) {
                return states[source] == Color::GRAY;
            }

            // If this is a leaf node, it should be equal to the destination
            if (graph[source].empty()) {
                return source == destination;
            }

            states[source] = Color::GRAY;
            for (int v : graph[source]) {
                // If we get a `false` from any recursive call on the neighbors, 
                // we short circuit and return from there.
                if (!leadsToDestination(graph, v, destination, states))
                    return false;
            }

            // Recursive processing done for the node. We mark it BLACK
            states[source] = Color::BLACK;
            return true;
        }
    };
}
