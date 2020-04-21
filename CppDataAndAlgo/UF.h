/*
 * UF.h
 *
 *  Created on: Apr 21, 2020
 *      Author: vsirvent
 */

#ifndef UF_H_
#define UF_H_

#include <unordered_map>
#include <unordered_set>

using namespace std;
/**
 * Algorithms section 1.5:
 *
 * To specify the problem, we develop an API that encapsulates the basic operations
 * that we need: initialize, add a connection between two sites, identify the component
 * containing a site, determine whether two sites are in the same component, and count
 * the number of components.
 * UF1 - quick-find implementation
 * - network hash_map to fast access to ids by network and avoid
 *   iterate ids.
 */
class UF1 {
private:
	std::unordered_map<int /*node*/, int /*network*/> ids;
	std::unordered_map<int /*network*/, unordered_set<int> /*nodes*/ > network;
	int ncomp;
public:
	UF1(int n) {
		for (int i = 0; i < n; ++i) {
			//create nodes with empty connections
			ids[i] = i; // node i in network i
			network[i].insert(i); //network i contains node i
		}
		ncomp = n;
	}

	virtual ~UF1() {

	}

	void connect(int p, int q) {
		//get networks by nodes
		int idp = ids[p];
		int idq = ids[q];

		if (idq != idp) {
			//get ids that belongs to idp network
			//to move to new network
			unordered_set<int>& ids_by_net = network[idp];
			for (int id: ids_by_net) {
				//set new network
				ids[id] = idq;
				network[idq].insert(id);
			}
			network[idp].clear(); //network idp is removed
			ncomp--;
		}
	}

	int find(int p) {
		return ids[p];
	}

	bool connected(int p, int q) {
		return (ids[p] == ids[q]);
	}

	int count() const {
		return ncomp;
	}
};

#endif /* UF_H_ */
