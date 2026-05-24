class UnionFind {
    constructor(n) {
        this.Parent = Array.from({length: n}, (_, i) = > i);
        this.Size = Array(n).fill(1);
    }

    // Function to find the representative (or the root
    // node) for the set that includes i
    find(i) {

        let root = this.Parent[i];

        if (this.Parent[root] != = root) {
            return this.Parent[i] = this.find(root);
        }

        return root;
    }

    // Unites the set that includes i and the set that
    // includes j by size
    unionBySize(i, j) {
        // Find the representatives (or the root nodes) for
        // the set that includes i
        const irep = this.find(i);

        // And do the same for the set that includes j
        const jrep = this.find(j);

        // Elements are in the same set, no need to unite
        // anything.
        if (irep == = jrep) return;

        // Get the size of i’s tree
        const isize = this.Size[irep];

        // Get the size of j’s tree
        const jsize = this.Size[jrep];

        // If i’s size is less than j’s size
        if (isize < jsize) {
            // Then move i under j
            this.Parent[irep] = jrep;

            // Increment j's size by i's size
            this.Size[jrep] += this.Size[irep];
        } else {
            // Then move j under i
            this.Parent[jrep] = irep;

            // Increment i's size by j's size
            this.Size[irep] += this.Size[jrep];
        }
    }
}

const n = 5;

const unionFind = new UnionFind(n);
unionFind.unionBySize(0, 1);
unionFind.unionBySize(2, 3);
unionFind.unionBySize(0, 4);
for (let i = 0; i < n; i++) {
    console.log(`Element ${i} : Representative = $ { unionFind.find(i) }`);
}
