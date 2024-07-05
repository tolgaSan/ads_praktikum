#include "KruskalMST.h"

/**
 * Erstellt einen MST zum Graph G mit dem Kruskal Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 */
KruskalMST::KruskalMST(EdgeWeightedGraph G)
{
	/*
	 * TODO
	 */
		std::vector<Edge> edges = G.edges();

		std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
			return a.weight() < b.weight();
		});

		treeID.resize(G.getV());;
		for(int i = 0; i < G.getV(); i++){
			treeID[i] = i; //at the start every knoten is his own tree
		}

		for(const Edge &e : edges){
			int v = e.either(), w = e.other(v);
			if(treeID[v] != treeID[w]){
				mst.push_back(e);
				int oldID = treeID[w];
				int newID = treeID[v];
				for(int i = 0; i < treeID.size(); i++) {
					if(treeID[i] == oldID) treeID[i] = newID;
				}
			}
		}
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> KruskalMST::edges() const
{
	/*
	 * TODO
	 */


	return mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double KruskalMST::weight() const
{
	/*
	 * TODO
	 */
	double totalWeight = 0.0;
	for(const Edge &e : mst){
		totalWeight += e.weight();
	}
	return totalWeight;
}
