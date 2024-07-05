#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>
#include <queue>
char toChar(int node) {
    return static_cast<char>(node + 65); // 65 ist der ASCII-Wert für 'A' usw.. 
}
namespace Graphsearch {
	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen G,
		* ab dem Knoten v aus und markiert alle besuchten
		* Knoten in marked.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]	 G			Graph
		* \param[in]	 v			Startknoten
		* \param[in/out] marked		Bereits besuchte Knoten
		* \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
		*/
	void DFS_recursive(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO
		 */

		marked[v] = true;
		std::cout << char(v+65) << " -> ";
		for(auto &e : G.getAdj(v)){
			int w = e.other(v);
			if(!marked[w]){
				edgeTo[w] = v;
				DFS_recursive(G, w, marked, edgeTo);
			}
		}

	}

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		* Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
		*
		* \param[in]  G			Graph
		* \param[out] marked	Bereits besuchte Knoten
		* \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
		* \param[in]  v			Startknoten
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/
	bool DFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO
		 */
		
		marked.assign(G.getV(), false);
		edgeTo.assign(G.getV(), -1);
		DFS_recursive(G, v, marked, edgeTo);
		//check if all verticles are visited
		for(int i = 0; i < G.getV(); i++){
			if(!marked[i]){
				//std::cout << char(i+65) << " -> " << (marked[i] ? "true":"false") << std::endl;
				return false;
			}
		}
		
 	/*std::cout << std::endl << std::endl << "Besuchsreihenfolge: " << std::endl;
    for (int i = 0; i < G.getV(); i++) {
        if (marked[i]) std::cout << char(i+65) << " ";
    }*/
    std::cout << std::endl << "EdgeTo_Array: " << std::endl;
    for (int i = 0; i < G.getV(); i++) {
        std::cout << char(i+65) << " -> " << (edgeTo[i] == -1 ? "-1" : std::to_string(edgeTo[i])) << std::endl;
    }
	std::cout << std::endl;
    std::cout << "Marked_Array:" << std::endl;
    for (int i = 0; i < G.getV(); i++) {
        std::cout << char(i+65) << " -> " << (marked[i] ? "true" : "false") << std::endl;
    }
	std::cout << std::endl;
		return true;
	}

	/**
		* Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]  G			Graph
		* \param[in]  v			Startknoten
		* \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
		* \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/
	bool BFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO:
		 */
		std::queue<int> q;
		marked.assign(G.getV(), false);
		edgeTo.assign(G.getV(), -1);
		marked[v] = true;
		q.push(v);

		std::cout << std::endl << "Besuchsreihenfolge: ";

		while(!q.empty()){
			int current = q.front();
			q.pop();
			std::cout << char(current+65) << " ";
			for(auto &e : G.getAdj(current)){
				int w = e.other(current);
				if(!marked[w]){
					edgeTo[w] = current;
					marked[w] = true;
					q.push(w);
				}
			}
		}
		
		for(bool m : marked){
			if(!m) return false;
		} 
		
		std::cout << std::endl << "EdgeTo_Array: " << std::endl;
		for (int i = 0; i < G.getV(); i++) {
        std::cout << char(i+65) << " -> " << (edgeTo[i] == -1 ? "-1" : std::to_string(edgeTo[i])) << "\n";
    	}

		std::cout << std::endl << "Marked_Array: " << std::endl;
		for (int i = 0; i < G.getV(); i++) {
			std::cout << char(i+65) << " -> " << (marked[i] ? "true" : "false") << "\n";
		}
		std::cout << std::endl;

		return true;
	}
}

