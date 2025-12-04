class Node {
    constructor(data) {
        this.data = data;
        this.height = 1; // leaf height = 1
        this.left = null;
        this.right = null;
    }
}

class AVL {
    #root;
    constructor() {
        this.root = null;
    }

    nodeHeight(node) {
        if (node) {
            let hl = node.left ? node.left.height : 0;
            let hr = node.right ? node.right.height : 0;
            return (hl > hr ? hl : hr) + 1;
        }
        return 0;
    }

    balanceFactor(node) {
        if (node) {
            let hl = node.left ? node.left.height : 0;
            let hr = node.right ? node.right.height : 0;
            return hl - hr;
        }
        return 0;
    }

    // ---------------- ROTATIONS ---------------- //

    LLRotation(node) {
        let nodeLeft = node.left;
        let nodeLeftRight = node.left.right;

        nodeLeft.right = node;
        node.left = nodeLeftRight;

        node.height = this.nodeHeight(node);
        nodeLeft.height = this.nodeHeight(nodeLeft);

        return nodeLeft;
    }

    LRRotation(node) {
        let nodeLeftRight = node.left.right;
        let nodeLeftRightLeft = node.left.right.left;
        let nodeLeftRightRight = node.left.right.right;

        nodeLeftRight.left = node.left;
        nodeLeftRight.right = node;

        nodeLeftRight.left.right = nodeLeftRightLeft;
        nodeLeftRight.right.left = nodeLeftRightRight;

        nodeLeftRight.left.height = this.nodeHeight(nodeLeftRight.left);
        node.height = this.nodeHeight(node);
        nodeLeftRight.height = this.nodeHeight(nodeLeftRight);

        return nodeLeftRight;
    }

    RRRotation(node) {
        let nodeRight = node.right;
        let nodeRightLeft = node.right.left;

        nodeRight.left = node;
        node.right = nodeRightLeft;

        node.height = this.nodeHeight(node);
        nodeRight.height = this.nodeHeight(nodeRight);

        return nodeRight;
    }

    RLRotation(node) {
        let nodeRightLeft = node.right.left;
        let nodeRightLeftLeft = node.right.left.left;
        let nodeRightLeftRight = node.right.left.right;

        nodeRightLeft.right = node.right;
        nodeRightLeft.left = node;

        nodeRightLeft.left.right = nodeRightLeftLeft;
        nodeRightLeft.right.left = nodeRightLeftRight;

        nodeRightLeft.left.height = this.nodeHeight(nodeRightLeft.left);
        nodeRightLeft.right.height = this.nodeHeight(nodeRightLeft.right);
        nodeRightLeft.height = this.nodeHeight(nodeRightLeft);

        return nodeRightLeft;
    }

    // ---------------- INSERT ---------------- //

    insert(data) {
        this.root = this._insert(this.root, data);
    }

    _insert(node, data) {
        if (node == null) {
            return new Node(data);
        } else if (data < node.data) {
            node.left = this._insert(node.left, data);
        } else if (data > node.data) {
            node.right = this._insert(node.right, data);
        }

        node.height = this.nodeHeight(node);

        if (this.balanceFactor(node) === 2 && this.balanceFactor(node.left) === 1)
            return this.LLRotation(node);

        if (this.balanceFactor(node) === 2 && this.balanceFactor(node.left) === -1)
            return this.LRRotation(node);

        if (this.balanceFactor(node) === -2 && this.balanceFactor(node.right) === -1)
            return this.RRRotation(node);

        if (this.balanceFactor(node) === -2 && this.balanceFactor(node.right) === 1)
            return this.RLRotation(node);

        return node;
    }

    // ---------------- SEARCH ---------------- //

    searchData(data) {
        return this._searchData(this.root, data);
    }

    _searchData(node, data) {
        if (node) {
            if (data === node.data) return node;
            if (data < node.data) return this._searchData(node.left, data);
            return this._searchData(node.right, data);
        }
        return null;
    }

    // ---------------- COUNT ---------------- //

    countTotalNodes() {
        return this._countTotalNodes(this.root);
    }

    _countTotalNodes(node) {
        if (!node) return 0;
        return (
            this._countTotalNodes(node.left) +
            this._countTotalNodes(node.right) +
            1
        );
    }

    // ---------------- DELETE ---------------- //

    predecessor(node) {
        if (node.right == null) return node.data;
        return this.predecessor(node.right);
    }

    deleteNode(data) {
        this.root = this._deleteNode(this.root, data);
    }

    _deleteNode(node, data) {
        if (node != null) {
            if (data === node.data) {
                if (!node.left && !node.right) return null;
                if (node.left && !node.right) return node.left;
                if (!node.left && node.right) return node.right;

                if (node.left.right == null) {
                    node.left.right = node.right;
                    return node.left;
                } else {
                    node.data = this.predecessor(node.left);
                    node.left = this._deleteNode(node.left, node.data);
                }
            } else if (data < node.data) {
                node.left = this._deleteNode(node.left, data);
            } else {
                node.right = this._deleteNode(node.right, data);
            }

            node.height = this.nodeHeight(node);

            if (this.balanceFactor(node) === 2 && this.balanceFactor(node.left) === 1)
                return this.LLRotation(node);

            if (this.balanceFactor(node) === 2 && this.balanceFactor(node.left) === -1)
                return this.LRRotation(node);

            if (this.balanceFactor(node) === -2 && this.balanceFactor(node.right) === -1)
                return this.RRRotation(node);

            if (this.balanceFactor(node) === -2 && this.balanceFactor(node.right) === 1)
                return this.RLRotation(node);
        }

        return node;
    }

    // ---------------- DISPLAY (INORDER) ---------------- //

    showAVL() {
        let arr = [];
        this._inorder(this.root, arr);
        console.log("AVL Data:", arr.join("  "));
        console.log("----------------------------------------");
    }

    _inorder(node, arr) {
        if (node) {
            this._inorder(node.left, arr);
            arr.push(node.data);
            this._inorder(node.right, arr);
        }
    }
}

const t1 = new AVL();

let values = [50,30,60,20,40,38,25,55,70,53,80];

for (let value of values) {
    t1.insert(value);
}


t1.showAVL();

let searchedData = t1.searchData(10);
if (searchedData) {
    console.log("Searched Data: " + searchedData.data);
} else {
    console.log("Data not found!");
}

console.log("----------------------------------------");

console.log("Total Nodes:", t1.countTotalNodes());

t1.deleteNode(38);
t1.deleteNode(55);
t1.deleteNode(50);
t1.deleteNode(60);

t1.showAVL();