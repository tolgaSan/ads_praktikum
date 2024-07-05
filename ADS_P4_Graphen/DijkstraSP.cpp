#include <assert.h>
#include "DijkstraSP.h"

/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	/*
	 * TODO
	 */
	for (DirectedEdge &e : G.getAdj(v)) {
        int w = e.to();
        if (distToVect[w] > distToVect[v] + e.weight()) {
            distToVect[w] = distToVect[v] + e.weight();
            edgeTo[w] = e;
            pq.push(w, distToVect[w]);
        }
    }
}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	/*
	 * TODO
	 */

	distToVect.assign(G.getV(), std::numeric_limits<double>::infinity());
	edgeTo.clear();
	distToVect[s] = 0.0;
	pq.push(s, 0.0);
	while(!pq.empty()) {
		int v = pq.top().value;
		pq.pop();
		relax(G, v);
	}
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	/*
	 * TODO
	 */
	return distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	/*
	 * TODO
	 */

	return distToVect[v] < std::numeric_limits<double>::infinity();
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v) 
{
	/*
	 * TODO
	 */

	std::vector<DirectedEdge> path;
    if (!hasPathTo(v)) return path;

    for (int x = v; x != v || path.empty(); x = edgeTo[x].from()) {
        if (edgeTo.find(x) == edgeTo.end()) break;
        path.push_back(edgeTo[x]);
    }
	std::reverse(path.begin(), path.end());
	return path;
}


