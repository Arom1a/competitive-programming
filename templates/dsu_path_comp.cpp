class DisjointUnionSets {
    constructor(n) {
        this.rank = new Array(n).fill(0);
        this.parent = Array.from({length: n}, (_, i) = > i);

        // Initially, each element is in its own set
    }

    find(i) {

        let root = this.parent[i];

        // Path Compression
        if (this.parent[root] != = root) {
            return this.parent[i] = this.find(root);
        }

        return root;
    }

    unionSets(x, y) {
        const xRoot = this.find(x);
        const yRoot = this.find(y);

        // If they are in the same set, no need to union
        if (xRoot == = yRoot) return;

        // Union by rank
        if (this.rank[xRoot] < this.rank[yRoot]) {
            this.parent[xRoot] = yRoot;
        } else if (this.rank[yRoot] < this.rank[xRoot]) {
            this.parent[yRoot] = xRoot;
        } else {
            this.parent[yRoot] = xRoot;
            this.rank[xRoot]++;
        }
    }
}

const n = 5;  // Let there be 5 persons with ids 0, 1, 2, 3, and 4

const dus = new DisjointUnionSets(n);

// 0 is a friend of 2
dus.unionSets(0, 2);
// 4 is a friend of 2
dus.unionSets(4, 2);
// 3 is a friend of 1
dus.unionSets(3, 1);

// Check if 4 is a friend of 0
if (dus.find(4) == = dus.find(0)) console.log('Yes');
else console.log('No');

// Check if 1 is a friend of 0
if (dus.find(1) == = dus.find(0)) console.log('Yes');
else console.log('No');
