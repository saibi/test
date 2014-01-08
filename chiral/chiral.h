#ifndef CHIRAL_H
#define CHIRAL_H

#define RIGHT_SIDE  0
#define LEFT_SIDE   1
#define BOTH_SIDE   2

//
//Chiral
//
template < class T >
struct Chiral {
	typedef T       ChiralType;

                Chiral():                sideR(T()), sideL(T()) {
	}
                Chiral(const Chiral & d):                sideR(d.sideR), sideL(d.sideL) {
	}
Chiral(const T & r, const T & l):sideR(r), sideL(l) {
	}

	Chiral < T > &operator = (const Chiral < T > &other) {
		sideR = other.sideR;
		sideL = other.sideL;
		return *this;
	}

	T & get(int side) {
		switch (side) {
		case RIGHT_SIDE:
			return sideR;
		case LEFT_SIDE:
			return sideL;
		default:;
		}
		return sideR;
	}

	const           T & get(int side) const
	{
		switch (side) {
			case RIGHT_SIDE:return sideR;
		case LEFT_SIDE:
			return sideL;
		default:;
		}
		return sideR;
	}

	T              *getPtr(int side) {
		switch (side) {
			case RIGHT_SIDE:return &sideR;
		case LEFT_SIDE:
			return &sideL;
		default:;
		}
		return 0;
	}

	void            set(int side, const T & d) {
		switch (side) {
			case RIGHT_SIDE:sideR = d;
			break;
		case LEFT_SIDE:
			sideL = d;
			break;
		case BOTH_SIDE:
			sideR = d;
			sideL = d;
			break;
		default:;
		}
	}

	T               sideR;
	T               sideL;
};

template < class T >
inline bool operator == (const Chiral < T > &p1, const Chiral < T > &p2) {
	return p1.sideR == p2.sideR && p1.sideL == p2.sideL;
}

template < class T >
inline bool operator != (const Chiral < T > &p1, const Chiral < T > &p2) {
	return !(p1 == p2);
}

template < class T >
inline bool operator < (const Chiral < T > &p1, const Chiral < T > &p2) {
	return p1.sideR < p2.sideR || (!(p2.sideR < p1.sideR) && p1.sideL < p2.sideL);
}

template < class T >
inline bool operator > (const Chiral < T > &p1, const Chiral < T > &p2) {
	return p2 < p1;
}

template < class T >
inline bool operator <= (const Chiral < T > &p1, const Chiral < T > &p2) {
	return !(p2 < p1);
}

template < class T >
inline bool operator >= (const Chiral < T > &p1, const Chiral < T > &p2) {
	return !(p1 < p2);
}

template < class T >
inline Chiral < T > makeChiral(const T & x, const T & y)
{
	return Chiral < T > (x, y);
}
#endif	/* // CHIRAL_H */
