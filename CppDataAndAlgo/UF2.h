/*
 * UF.h
 *
 *  Created on: Apr 21, 2020
 *      Author: vsirvent
 */

#ifndef UF2_H_
#define UF2_H_

#include <unordered_map>
#include <unordered_set>
#include "IUF.h"

using namespace std;
/**
 * Algorithms section 1.5:
 *
 * To specify the problem, we develop an API that encapsulates the basic operations
 * that we need: initialize, add a connection between two sites, identify the component
 * containing a site, determine whether two sites are in the same component, and count
 * the number of components.
 * UF2 - quick-union implementation
 */
class UF2: public IUF {
private:
	std::unordered_map<int /*node*/, int /*network*/> ids;
	int ncomp;
public:
	UF2(int n) {
		for (int i = 0; i < n; ++i) {
			//create nodes with empty connections
			ids[i] = i; // node i in network i
		}
		ncomp = n;
	}

	virtual ~UF2() {

	}

	void connect(int p, int q) {
		//get networks by nodes
		int idp = find(p);
		int idq = find(q);

		if (idq != idp) {
			ids[q] = p;
			ncomp--;
		}
	}

	int find(int p) {
		//return root node
		while (ids[p] != p) { p = ids[p]; }
		return p;
	}

	bool connected(int p, int q) {
		return (find(p) == find(q));
	}

	int count() const {
		return ncomp;
	}
};

#endif /* UF2_H_ */
