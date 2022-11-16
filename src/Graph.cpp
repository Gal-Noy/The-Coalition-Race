#include "Graph.h"

#include <utility>

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(std::move(vertices)), mEdges(std::move(edges))
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return (int) mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}