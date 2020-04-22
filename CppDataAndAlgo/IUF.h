#ifndef IUF_H
#define IUF_H

class IUF {
public:
	virtual ~IUF() {
	}

	virtual void connect(int p, int q) = 0;
	virtual int find(int p) = 0;
	virtual bool connected(int p, int q) = 0;
	virtual int count() const = 0;

};
#endif
