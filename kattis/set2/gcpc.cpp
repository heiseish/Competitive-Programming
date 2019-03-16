/** 
Wherever someone is still thinking of you, that place is your home.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/


struct Team {
    int index, a, b;

    Team(int idx, int aa, int bb) : index(idx), a(aa), b(bb) { }
	Team(int idx) : index(idx), a(0), b(0) { }
     bool operator<(const Team& rhs) const {
        if (a != rhs.a) {
			return a < rhs.a;
		} else if (b != rhs.b) {
			return b > rhs.b;
		} else  return index > rhs.index;
    }


	bool operator==(const Team& rhs) const {
        return index == rhs.index && a == rhs.a && b == rhs.b;
    }
};

template <class myType>
class Vertex{
public:
    myType key;
    Vertex<myType> *left;
    Vertex<myType> *right;
    Vertex<myType> *parent;
    int height;
    int size;
    Vertex(myType p) : key(p), parent(NULL), right(NULL), left(NULL), height(0), size(1) { }
};

template <class myType>
class BinarySearchTree {
private:
    Vertex<myType>* root;
    Vertex<myType>* get(Vertex<myType>* v, myType p) {
        if (v == NULL)  return NULL;                    
        else if (v->key == p) return v;               
        else if (v->key < p)  return get(v->right, p);    
        else return get(v->left, p);       
    }
    Vertex<myType>* add(Vertex<myType>* v, myType p) {
        Vertex<myType>* w;
        if (v == NULL)  v = new Vertex<myType>(p);
        else if (v->key < p) {
            w = add(v->right, p);
            v->right = w;
            w->parent = v;
        } else  {
            w = add(v->left, p); 
            v->left = w;
            w->parent = v;
        }
        updateProperty(v);
        return checkVariant(v);
    }

    Vertex<myType>* remove(Vertex<myType>* v, myType p) {
        Vertex<myType>* w;
        if (v == NULL)  return NULL; // impossible, since remove guarantee to succeed
        else if (v->key == p) {
            Vertex<myType>* par = v->parent;
            Vertex<myType>* left = v->left;
            Vertex<myType>* right = v->right;
            if (right == NULL && left == NULL) v = NULL;
            else if (right != NULL && left == NULL) {
                right->parent = par;
                right->left = left;
                v = right;
            } else if (right == NULL && left != NULL) {
                left->parent = par;
                left->right = right;
                v = left;
            } else {
                w = successor(v);
                v->key = w->key;
                v->right = remove(v->right, w->key);
            }
            
        } else if (v->key < p) {
            w = remove(v->right, p);
            v->right = w;
            if (w != NULL) w->parent = v;
        } else  {
            w = remove(v->left, p); 
            v->left = w;
            if (w != NULL) w->parent = v;
        }
        updateProperty(v);
        return checkVariant(v);

    }

    Vertex<myType>* rotateLeft(Vertex<myType>* v) {
        Vertex<myType>* r = v->right;
        r->parent = v->parent;
        v->parent = r;
        v->right = r->left;
        if (r->left != NULL) r->left->parent = v;
        r->left = v;
        updateProperty(v);
        updateProperty(r);
        return r;
    }

    Vertex<myType>* rotateRight(Vertex<myType>* v) {
        Vertex<myType>* l = v->left;
        l->parent = v->parent;
        v->parent = l;
        v->left = l->right;
        if (l->right != NULL) l->right->parent = v;
        l->right = v;
        updateProperty(v);
        updateProperty(l);
        return l;
    }

    int balanceFactor(Vertex<myType>* v) {
        if (v == NULL) return 0;
        int leftHeight = v->left == NULL ? -1 : v->left->height;
        int rightHeight = v->right == NULL ? -1 : v->right->height;
        return leftHeight - rightHeight;
    }

    Vertex<myType>* checkVariant(Vertex<myType>* v) {
        if (v == NULL) return NULL;
        Vertex<myType>* w;
        if (balanceFactor(v) == 2 && 0 <= balanceFactor(v->left) && balanceFactor(v->left) <= 1) {
            v = rotateRight(v);
        } else if (balanceFactor(v) == 2 && balanceFactor(v->left) == -1) {
            w = rotateLeft(v->left);
            w->parent = v;
            v->left = w;
            v = rotateRight(v);
        } else if (balanceFactor(v) == -2 && -1 <= balanceFactor(v->right) && balanceFactor(v->right) <= 0) {
            v = rotateLeft(v);
        } else if (balanceFactor(v) == -2 && balanceFactor(v->right) == 1) {
            w = rotateRight(v->right);
            w->parent = v;
            v->right = w;
            v = rotateLeft(v);
        }
        return v;
    }

    void updateProperty(Vertex<myType>* v) {
        if (v == NULL) return;
        int leftSize = v->left == NULL ? 0 : v->left->size;
        int rightSize = v->right == NULL ? 0 : v->right->size;
        v->size = leftSize + rightSize + 1;

        int leftHeight = v->left == NULL ? -1 : v->left->height;
        int rightHeight = v->right == NULL ? -1 : v->right->height;
        v->height = max(leftHeight, rightHeight) + 1;
    }

    

    int rank(Vertex<myType>* v, myType p) {
        if (v == NULL) return 0;
        if (v->key == p) {
            if (v->left == NULL) return 0;
            return v->left->size;
        } else if (v->key < p) {
            int left = v->left == NULL ? 0 : v->left->size;
            return 1 + left + rank(v->right, p);
        } else return rank(v->left, p);
    }

    Vertex<myType>* findNearestVertexToTheRight(Vertex<myType>* v, myType p) {
        if (v == NULL) return NULL;
        if (v->key == p) return v;               
        else if (v->key < p && v->right != NULL)  return findNearestVertexToTheRight(v->right, p);   
        else if (v->key < p && v->right == NULL)  return successor(v);   
        else if (v->key > p && v->left != NULL)  return findNearestVertexToTheRight(v->left, p);
        else if (v->key > p && v->left == NULL)  return v;   
        return NULL;
    }

    Vertex<myType>* findNearestVertexToTheLeft(Vertex<myType>* v, myType p) {
        if (v == NULL) return NULL;
        if (v->key == p) return predecessor(v);               
        else if (v->key < p && v->right != NULL)  return findNearestVertexToTheLeft(v->right, p);   
        else if (v->key < p && v->right == NULL)  return v;   
        else if (v->key > p && v->left != NULL)  return findNearestVertexToTheLeft(v->left, p);
        else if (v->key > p && v->left == NULL)  return predecessor(v);   
        return NULL;
    }

    Vertex<myType>* successor(Vertex<myType>* v) {
        if (v->right != NULL)           
            return findMin(v->right);  
        else {
            Vertex<myType>* par = v->parent;
            Vertex<myType>* cur = v;
            // if par(ent) is not root and cur(rent) is its right children
            while ((par != NULL) && (cur == par->right)) {
                cur = par;                                         // continue moving up
                par = cur->parent;
            }
            return par == NULL ? NULL : par;           // this is the successor of T
        }
    }

    Vertex<myType>* findMin(Vertex<myType>* v) {
        if (v == NULL) return NULL;
        else if (v->left == NULL) return v;                    // this is the min
        else return findMin(v->left);           // go to the left
    }

    Vertex<myType>* predecessor(Vertex<myType>* v) {
        if (v->left != NULL)                       // this subtree has right subtree
            return findMax(v->left);  // the successor is the minimum of right subtree
        else {
            Vertex<myType>* par = v->parent;
            Vertex<myType>* cur = v;
            // if par(ent) is not root and cur(rent) is its right children
            while ((par != NULL) && (cur == par->left)) {
                cur = par;                                         // continue moving up
                par = cur->parent;
            }
            return par == NULL ? NULL : par;           // this is the successor of T
        }
    }
    Vertex<myType>* findMax(Vertex<myType>* v) {
        if (v == NULL) return NULL;
        else if (v->right == NULL) return v;                    // this is the min
        else return findMax(v->right);           // go to the left
    }

public:
    BinarySearchTree(): root(NULL) { }

    myType get(myType p) {
        Vertex<myType>* v = get(root, p);
        return v == NULL ? NULL : v->key;
    }

    void add(myType p) {
        if (root == NULL) root = new Vertex<myType>(p);
        else root = add(root, p);
    }

    void remove(myType p) {
        if (root == NULL) return;
        else root = remove(root, p);
    }

    int rank(myType p) {
        return rank(root, p);
 
    }

    int getSize() {
        return root->size;
    }

    int subSet(myType START, myType END) {
        Vertex<myType>* s = findNearestVertexToTheRight(root, START);
        Vertex<myType>* e = findNearestVertexToTheLeft(root, END);
        if (s == NULL || e == NULL) return 0;
        else {
            int start = rank(s->key);
            int end = rank(e->key);
            return end - start + 1;

        }

    }
};



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int n, m;
    cin>>n>>m;
    BinarySearchTree<Team> tree;
	vpi info(n + 1, {0 , 0});
	forn(i, 1, n) {
		tree.add(Team(i, 0, 0));
	}
    forn(i, 1, m) {
        int t, p;
        cin>>t>>p;
		Team a = tree.get(Team(t, info[t].st, info[t].nd));
		tree.remove(a);
		a.a++;
		a.b+=p;
		tree.add(a);
		info[t].st++;
		info[t].nd+=p;
		cout << tree.getSize() - tree.rank(Team(1, info[1].st, info[1].nd)) <<'\n';
    }
    return 0;
}
