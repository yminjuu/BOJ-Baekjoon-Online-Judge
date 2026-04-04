class Heap {
    constructor(comparator = (a,b) => a-b){
        this.heap = [];
        this.comparator = comparator;
    }
    top(){
        if (this.heap.length==0) return null;
        return this.heap[0];
    }
    push(n){
        this.heap[this.heap.length]= n;
        this.bubbleUp();
    }
    pop(){
        let popItem;
        
        if (this.heap.length==0) return null;
        if (this.heap.length==1) return this.heap.pop();
        popItem = this.heap[0];
        
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        return popItem;
    }
    bubbleUp(){
        let idx = this.heap.length - 1;
        let parent = Math.floor((idx-1)/2);
        
        while (idx!=0) {
            if (this.comparator(this.heap[idx], this.heap[parent]) < 0) { // idx 값이 더 작다면
                // 자리 변경
                [[this.heap[idx], this.heap[parent]]]= [[this.heap[parent], this.heap[idx]]];
                idx = parent;
                parent = Math.floor((idx-1)/2);
            } else break;
        }
    }
    bubbleDown(){
        let idx = 0;
        let left = idx*2 + 1;
        let right = idx*2 + 2;
        
        while (true){
            let left = idx*2 + 1;
            let right = idx*2 + 2;
            let smallest= idx;
            
            if (left< this.heap.length && this.comparator(this.heap[smallest], this.heap[left]) >= 0) {
                smallest= left;
            }
            if (right < this.heap.length && this.comparator(this.heap[smallest], this.heap[right]) >= 0) {
                smallest= right;
            }
            
            if (smallest==idx) break;
            [this.heap[smallest], this.heap[idx]] = [this.heap[idx], this.heap[smallest]];
            idx = smallest;
        }
    }
    size(){
        return this.heap.length;
    }
}


function solution(scoville, K) {
    var answer = 0;
    
    let pq = new Heap();
    for (let i= 0; i<scoville.length; i++){
        pq.push(scoville[i]);
    }
    
    while (pq.top()<K){
        let a = pq.pop();
        if (pq.size()==0) return -1;
        
        let b= pq.pop();
        pq.push(a+b*2);
        answer++;
    }
    
    return answer;
}