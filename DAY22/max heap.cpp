class maxHeap {
  private:
    vector<int>heap;
  public:
        maxHeap(){
            heap.push_back(-1);
        }

    void push(int x) {
        heap.push_back(x);
        int i=heap.size()-1;
        while(i>1 && heap[i]>heap[i/2]){
            swap(heap[i],heap[i/2]);
            i=i/2;
        }
    }

    void pop() {
        if(heap.size()==0) return;
        int n=heap.size();
        
        heap[1]=heap.back();
        heap.pop_back();
        
        int i=1,j=n-1;
        while(true){
            int left=2*i;
            int right=2*i+1;
            int large=i;
            
            if(left<n && heap[left]>heap[large]) large=left;
            if(right<n && heap[right]>heap[large])large=right;
            if(large!=i){
                swap(heap[i],heap[large]);
                i=large;
            }
            else break;
            
        }
        
    }

    int peek() {
        if(heap.size()==0) return -1;
        return heap[1];
    }

    int size() {
      return heap.size()-1;
    }
};
