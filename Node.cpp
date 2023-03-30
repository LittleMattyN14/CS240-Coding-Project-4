class Node{
        public:
        int val;
        Node* left;
        Node* right;
        Node(){
            left = NULL;
            right = NULL;
        }
        Node(int x){
            val = x;
            left = NULL;
            right = NULL;
        }
    };